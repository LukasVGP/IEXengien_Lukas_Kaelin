#pragma once

#include <IExeEngine/Inc/IExeEngine.h>
#include <IExeEngine/Inc/Graphics/VolumetricFogEffect.h> // Requires a correct Include Path setting

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
	IExeEngine::Graphics::RenderGroup mCannon;
	IExeEngine::Graphics::RenderGroup mUnionSoldier;
	IExeEngine::Graphics::RenderGroup mCSASoldier;
	// ----------------------------

	IExeEngine::Graphics::RenderObject mGround;
	IExeEngine::Graphics::Terrain mTerrain;
	IExeEngine::Graphics::RenderObject mScreenQuad;

	IExeEngine::Graphics::StandardEffect mStandardEffect;
	IExeEngine::Graphics::ShadowEffect mShadowEffect;
	IExeEngine::Graphics::TerrainEffect mTerrainEffect;

	// --- NEW: Volumetric Fog Effect ---
	IExeEngine::Graphics::VolumetricFogEffect mVolumetricFogEffect;
	// ----------------------------------
};