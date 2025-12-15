// GameState.h (Updated for Projects 10, 11, 12, 13)
#pragma once

#include <IExeEngine/Inc/IExeEngine.h>

class GameState : public IExeEngine::AppState
{
public:
    void Initialize() override;

    void Terminate() override;

    void Update(float deltaTime) override;

    void Render() override;

    void DebugUI() override;

private:

    void UpdateCamera(float deltaTime);

    IExeEngine::Graphics::Camera mCamera;
    IExeEngine::Graphics::DirectionalLight mDirectionalLight;

    // --- NEW CIVIL WAR MODELS ---
    // Cannon: Replaces mCharacter in P10-P13 logic
    IExeEngine::Graphics::RenderGroup mCannon;
    // Union Soldier: Replaces parasite in P10-P13 logic
    IExeEngine::Graphics::RenderGroup mUnionSoldier;
    // CSA Soldier: Replaces zombie in P10-P13 logic
    IExeEngine::Graphics::RenderGroup mCSASoldier;
    // ----------------------------

    IExeEngine::Graphics::RenderObject mGround;

    IExeEngine::Graphics::Terrain mTerrain; // P13 Only
    IExeEngine::Graphics::RenderObject mScreenQuad;

    IExeEngine::Graphics::StandardEffect mStandardEffect;
    IExeEngine::Graphics::ShadowEffect mShadowEffect; // P12, P13 Only
    IExeEngine::Graphics::TerrainEffect mTerrainEffect; // P13 Only

    // P11 Only:
    // IExeEngine::Graphics::RenderTarget mRenderTarget;
    // IExeEngine::Graphics::Texture mCombineTexture;
    // IExeEngine::Graphics::PostProcessingEffect mPostProcessingEffect;
};