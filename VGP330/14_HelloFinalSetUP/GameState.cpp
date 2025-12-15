#include "GameState.h"

using namespace IExeEngine;
using namespace IExeEngine::Graphics;
using namespace IExeEngine::Input;


void GameState::Initialize()
{
    // 1. CAMERA: Cinematic Position
    // Positioned for a cinematic view of the centered cannon and flanking soldiers.
    mCamera.SetPosition({ 2.0f, 1.5f, -3.0f });
    mCamera.SetLookAt({ 0.0f, 0.5f, 0.0f });

    // 2. LIGHTING: Dark, Gritty Atmosphere (Adjusted for Cinematic look)
    // Low ambient/diffuse to simulate darkness, preparing for the volumetric light/flare.
    mDirectionalLight.direction = Math::Normalize({ 1.0f, -1.0f, 1.0f });
    mDirectionalLight.ambient = { 0.1f, 0.1f, 0.15f, 1.0f }; // Dark Blue/Grey Ambient
    mDirectionalLight.diffuse = { 0.3f, 0.3f, 0.3f, 1.0f };  // Dim main light
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

    // 5. POSITIONING: CORNERED SOLDIERS & VISIBLE CANNON 

    // Rotation Fix Constants
    const float pitchFix = 1.5f; // Tilts head up by ~86 degrees (to fix 'face down' issue)
    const float yaw90 = Math::Constants::Pi * 0.5f; // 90 degrees
    const float yaw180 = Math::Constants::Pi;       // 180 degrees

    // Cannon: Place closer to the front, centered.
    mCannon.transform.position = { 0.0f, 0.0f, -0.5f };
    mCannon.transform.rotation = Math::Quaternion::CreateFromYawPitchRoll(yaw90, 0.0f, 0.0f);

    // Union Soldier: Back-Left Corner, facing away from the camera
    mUnionSoldier.transform.position = { -2.0f, 0.0f, 1.0f };
    // Yaw 180 (facing away from camera) + PitchFix (tilts head up)
    mUnionSoldier.transform.rotation = Math::Quaternion::CreateFromYawPitchRoll(yaw180, pitchFix, 0.0f);

    // CSA Soldier: Back-Right Corner, facing away from the camera
    mCSASoldier.transform.position = { 2.0f, 0.0f, 1.0f };
    // Yaw 180 (facing away from camera) + PitchFix (tilts head up)
    mCSASoldier.transform.rotation = Math::Quaternion::CreateFromYawPitchRoll(yaw180, pitchFix, 0.0f);

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
}

void GameState::Terminate()
{
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
        // Only snap if the group's root transform is near the ground.
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