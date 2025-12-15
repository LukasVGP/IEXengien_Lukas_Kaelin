// GameState.cpp (for 14_FinalSetUP)
#include "GameState.h"

using namespace IExeEngine;
using namespace IExeEngine::Graphics;
using namespace IExeEngine::Input;


void GameState::Initialize()
{
    // 1. CAMERA: Cinematic Position
    mCamera.SetPosition({ 2.0f, 1.5f, -3.0f });
    mCamera.SetLookAt({ 0.0f, 0.5f, 0.0f });

    // 2. LIGHTING: Dark, Gritty Atmosphere (Pre-Volumetric Fog Look)
    mDirectionalLight.direction = Math::Normalize({ 1.0f, -1.0f, 1.0f });
    mDirectionalLight.ambient = { 0.1f, 0.1f, 0.15f, 1.0f }; // Dark Blue/Grey Ambient
    mDirectionalLight.diffuse = { 0.3f, 0.3f, 0.3f, 1.0f };  // Dim main light
    mDirectionalLight.specular = { 0.1f, 0.1f, 0.1f, 1.0f };

    // 3. TERRAIN
    mTerrain.Initialize(L"../../Assets/Textures/terrain/heightmap_1024x1024.raw", 20.0f);
    mGround.meshBuffer.Initialize(mTerrain.mesh);
    mGround.diffuseMapId = TextureManager::Get()->LoadTexture(L"../../Assets/Textures/terrain/dirt_seamless.jpg");
    mGround.specMapId = TextureManager::Get()->LoadTexture(L"../../Assets/Textures/terrain/grass_2048.jpg");

    // 4. MODELS: Load and Position

    // Union Soldier: Facing +X (Right)
    mUnionSoldier.Initialize("Final/UnionSoldiersitting.model");
    mUnionSoldier.transform.position = { -0.3f, 0.0f, 0.0f };
    mUnionSoldier.transform.rotation = Math::Quaternion::CreateFromYawPitchRoll(Math::Constants::Pi * 0.5f, 0.0f, 0.0f);

    // CSA Soldier: Facing -X (Left), placed back-to-back
    mCSASoldier.Initialize("Final/CSASoldiersitting.model");
    mCSASoldier.transform.position = { 0.3f, 0.0f, 0.0f };
    mCSASoldier.transform.rotation = Math::Quaternion::CreateFromYawPitchRoll(Math::Constants::Pi * -0.5f, 0.0f, 0.0f);

    // Cannon: Environment prop
    mCannon.Initialize("Final/CivilwarCannon.model");
    mCannon.transform.position = { 0.0f, 0.0f, 2.5f }; // Behind them
    mCannon.transform.rotation = Math::Quaternion::CreateFromYawPitchRoll(0.5f, 0.0f, 0.0f);

    MeshPX screenQuadMesh = MeshBuilder::CreateScreenQuadPX();
    mScreenQuad.meshBuffer.Initialize(screenQuadMesh);

    // 5. EFFECTS SETUP 
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
    // ... (Your DebugUI code for Light, StandardEffect, ShadowEffect, TerrainEffect) ...
    ImGui::End();
}

void GameState::UpdateCamera(float deltaTime)
{
    // ... (Your camera movement logic remains the same) ...
}