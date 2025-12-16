#include "Precompiled.h" // FIX: Must be the first include if using Precompiled Headers
#include "GameState.h"


using namespace IExeEngine;
using namespace IExeEngine::Graphics;
using namespace IExeEngine::Input;


void GameState::Initialize()
{
	// --- SCENE CENTER CALCULATION ---
	// The terrain is centered by translating models by a positive offset (10.0f).
	const float centerOffset = 10.0f;
	const float sceneX = 22.0f + centerOffset;
	const float sceneZ = 19.1f + centerOffset; // Average Z of soldiers (20.1 + 18.1) / 2
	const float sceneY = 1.5f; // Target look height
	// ------------------------------

	// 1. CAMERA: Cinematic Position
	mCamera.SetPosition({ 2.0f, 1.5f, -3.0f });
	// Camera now looks directly at the center of the translated scene:
	mCamera.SetLookAt({ sceneX, sceneY, sceneZ });

	// 2. LIGHTING: Dark, Gritty Atmosphere 
	mDirectionalLight.direction = Math::Normalize({ 1.0f, -1.0f, 1.0f });
	mDirectionalLight.ambient = { 0.1f, 0.1f, 0.15f, 1.0f };
	mDirectionalLight.diffuse = { 0.3f, 0.3f, 0.3f, 1.0f };
	mDirectionalLight.specular = { 0.1f, 0.1f, 0.1f, 1.0f };

	// 3. TERRAIN
	mTerrain.Initialize(L"../../Assets/Textures/terrain/heightmap_1024x1024.raw", 20.0f);
	mGround.meshBuffer.Initialize(mTerrain.mesh);
	mGround.diffuseMapId = TextureManager::Get()->LoadTexture(L"../../Assets/Textures/terrain/dirt_seamless.jpg");
	mGround.specMapId = TextureManager::Get()->LoadTexture(L"../../Assets/Textures/terrain/grass_2048.jpg");

	// 4. MODELS: Load New Civil War Assets
	mCannon.Initialize("Final/Cannon.model");
	mUnionSoldier.Initialize("Final/UnionSoldiersitting.model");
	mCSASoldier.Initialize("Final/CSASoldiersitting.model");

	// 5. FINAL POSITIONING: CENTERED CANNON & BACK-TO-BACK SOLDIERS

	// Rotation Fix Constants
	const float pitchFix = 1.5f; // Tilts soldier head up by ~86 degrees
	const float yaw90 = Math::Constants::Pi * 0.5f;
	const float yaw180 = Math::Constants::Pi;

	// Cannon: Centered, Standing Upright, Barrel Pointing Forward
	mCannon.transform.position = { 32.0f + centerOffset, 5.0f, 19.0f + centerOffset };
	// YAW 90, PITCH adjusted to tilt barrel up slightly, ROLL 0
	mCannon.transform.rotation = Math::Quaternion::CreateFromYawPitchRoll(yaw90, 0.1f, 0.0f);

	// Union Soldier: Back-to-Back, facing AWAY from the cannon
	mUnionSoldier.transform.position = { 22.0f + centerOffset, 5.0f, 20.1f + centerOffset };
	// Yaw 180 (opposite CSA) + PitchFix (sit upright)
	mUnionSoldier.transform.rotation = Math::Quaternion::CreateFromYawPitchRoll(yaw180, pitchFix, 0.0f);

	// CSA Soldier: Back-to-Back, facing TOWARDS the cannon
	mCSASoldier.transform.position = { 22.0f + centerOffset, 5.0f, 18.1f + centerOffset };
	// Yaw 0 (opposite Union) + PitchFix (sit upright)
	mCSASoldier.transform.rotation = Math::Quaternion::CreateFromYawPitchRoll(0.0f, pitchFix, 0.0f);

	MeshPX screenQuadMesh = MeshBuilder::CreateScreenQuadPX();
	mScreenQuad.meshBuffer.Initialize(screenQuadMesh);

	// 6. EFFECTS SETUP 
	std::filesystem::path shaderFile = L"../../Assets/Shaders/Standard.fx";
	mStandardEffect.Initialize(shaderFile);
	mStandardEffect.SetCamera(mCamera);
	mStandardEffect.SetDirectionalLight(mDirectionalLight);
	mStandardEffect.SetLightCamera(mShadowEffect.GetLightCamera());
	mStandardEffect.SetShadowMap(mShadowEffect.GetDepthMap());

	shaderFile = L"../../Assets/Shaders/Shadow.fx";
	mShadowEffect.Initialize();
	mShadowEffect.SetDirectionalLight(mDirectionalLight);

	mTerrainEffect.Initialize();
	mTerrainEffect.SetCamera(mCamera);
	mTerrainEffect.SetLightCamera(mShadowEffect.GetLightCamera());
	mTerrainEffect.SetDirectionalLight(mDirectionalLight);
	mTerrainEffect.SetShadowMap(mShadowEffect.GetDepthMap());

	// --- NEW: Volumetric Fog Effect Initialization ---
	shaderFile = L"../../Assets/Shaders/VolumetricFog.fx";
	mVolumetricFogEffect.Initialize(shaderFile);
	mVolumetricFogEffect.SetCamera(mCamera);
	mVolumetricFogEffect.SetDirectionalLight(mDirectionalLight);
	// Use the Shadow Map's depth buffer for world position reconstruction
	mVolumetricFogEffect.SetDepthMap(mShadowEffect.GetDepthMap());
}

void GameState::Terminate()
{
	// Terminate the new effect
	mVolumetricFogEffect.Terminate();

	mTerrainEffect.Terminate();
	mShadowEffect.Terminate();
	mScreenQuad.Terminate();
	mCannon.Terminate();
	mUnionSoldier.Terminate();
	mCSASoldier.Terminate();
	mGround.Terminate();
	mStandardEffect.Terminate();
}

void GameState::Update(float deltaTime)
{
	UpdateCamera(deltaTime);

	// Snap objects to terrain height in Update loop
	auto SnapToGround = [&](RenderGroup& group) {
		// This ensures models sit on the terrain, even if it's uneven.
		Math::Vector3 pos = group.transform.position;
		float h = mTerrain.GetHeight(pos);
		if (h >= 0.0f)
		{
			group.transform.position.y = h;
		}
		};
	SnapToGround(mUnionSoldier);
	SnapToGround(mCSASoldier);
	SnapToGround(mCannon);
}

void GameState::Render()
{
	// First Pass: Render to Shadow Map
	mShadowEffect.Begin();
	mShadowEffect.Render(mCannon);
	mShadowEffect.Render(mUnionSoldier);
	mShadowEffect.Render(mCSASoldier);
	mShadowEffect.Render(mGround);
	mShadowEffect.End();

	// Second Pass: Render Terrain
	mTerrainEffect.Begin();
	mTerrainEffect.Render(mGround);
	mTerrainEffect.End();

	// Third Pass: Render Entities with Shadows
	mStandardEffect.Begin();
	mStandardEffect.Render(mCannon);
	mStandardEffect.Render(mUnionSoldier);
	mStandardEffect.Render(mCSASoldier);
	mStandardEffect.End();

	// --- FINAL PASS: Volumetric Fog (Post-Processing) ---
	mVolumetricFogEffect.Begin();
	// Render the full-screen quad (mScreenQuad) to apply the volumetric fog shader
	mVolumetricFogEffect.Render(mScreenQuad);
	mVolumetricFogEffect.End();
	// ----------------------------------------------------
}

void GameState::DebugUI()
{
	ImGui::Begin("Debug", nullptr, ImGuiWindowFlags_AlwaysAutoResize);

	// Display Asset Memory Addresses
	if (ImGui::CollapsingHeader("Asset Addresses", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ImGui::LabelText("Cannon Address", "0x%p", (void*)&mCannon);
		ImGui::LabelText("UnionSoldier Address", "0x%p", (void*)&mUnionSoldier);
		ImGui::LabelText("CSASoldier Address", "0x%p", (void*)&mCSASoldier);
		ImGui::Separator();
	}

	// Light Control
	if (ImGui::CollapsingHeader("Light", ImGuiTreeNodeFlags_DefaultOpen))
	{
		if (ImGui::DragFloat3("Direction#Light", &mDirectionalLight.direction.x, 0.01f))
		{
			mDirectionalLight.direction = Math::Normalize(mDirectionalLight.direction);
		}
		ImGui::ColorEdit4("Ambient#Light", &mDirectionalLight.ambient.r);
		ImGui::ColorEdit4("Diffuse#Light", &mDirectionalLight.diffuse.r);
		ImGui::ColorEdit4("Specular#Light", &mDirectionalLight.specular.r);
	}

	// Material Control (Targeting the Union Soldier)
	if (ImGui::CollapsingHeader("Union Soldier Material", ImGuiTreeNodeFlags_DefaultOpen))
	{
		for (uint32_t i = 0; i < mUnionSoldier.renderObjects.size(); ++i)
		{
			Material& material = mUnionSoldier.renderObjects[i].material;
			std::string renderObjectId = "RenderObject " + std::to_string(i);
			ImGui::PushID(renderObjectId.c_str());
			if (ImGui::CollapsingHeader(renderObjectId.c_str()))
			{
				ImGui::LabelText("label", "Material:");
				ImGui::ColorEdit4("Emissive#Material", &material.emissive.r);
				ImGui::ColorEdit4("Ambient#Material", &material.ambient.r);
				ImGui::ColorEdit4("Diffuse#Material", &material.diffuse.r);
				ImGui::ColorEdit4("Specular#Material", &material.specular.r);
				ImGui::DragFloat("Shininess#Material", &material.shininess, 0.1f, 0.1f, 10000.0f);
			}
			ImGui::PopID();
		}
	}

	ImGui::Separator();
	mStandardEffect.DebugUI();
	mShadowEffect.DebugUI();
	mTerrainEffect.DebugUI();

	// NEW: Debug UI for Fog Parameters
	mVolumetricFogEffect.DebugUI();

	ImGui::End();
}

void GameState::UpdateCamera(float deltaTime)
{
	// Camera Controls:
	InputSystem* input = InputSystem::Get();
	const float moveSpeed = input->IsKeyDown(KeyCode::LSHIFT) ? 10.0f : 4.0f;
	const float turnSpeed = 0.5f;

	if (input->IsKeyDown(KeyCode::W)) { mCamera.Walk(moveSpeed * deltaTime); }
	else if (input->IsKeyDown(KeyCode::S)) { mCamera.Walk(-moveSpeed * deltaTime); }
	else if (input->IsKeyDown(KeyCode::D)) { mCamera.Strafe(moveSpeed * deltaTime); }
	else if (input->IsKeyDown(KeyCode::A)) { mCamera.Strafe(-moveSpeed * deltaTime); }
	else if (input->IsKeyDown(KeyCode::E)) { mCamera.Rise(moveSpeed * deltaTime); }
	else if (input->IsKeyDown(KeyCode::Q)) { mCamera.Rise(-moveSpeed * deltaTime); }

	if (input->IsMouseDown(MouseButton::RBUTTON))
	{
		mCamera.Yaw(input->GetMouseMoveX() * turnSpeed * deltaTime);
		mCamera.Pitch(input->GetMouseMoveY() * turnSpeed * deltaTime);
	}
}