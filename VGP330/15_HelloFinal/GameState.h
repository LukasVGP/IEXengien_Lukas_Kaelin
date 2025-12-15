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
	IExeEngine::Graphics::RenderGroup mCannon;
	IExeEngine::Graphics::RenderGroup mUnionSoldier;
	IExeEngine::Graphics::RenderGroup mCSASoldier;
	// ----------------------------

	IExeEngine::Graphics::RenderObject mGround;

	// --- MISSING TERRAIN COMPONENTS ADDED ---
	IExeEngine::Graphics::Terrain mTerrain;
	// ----------------------------------------

	IExeEngine::Graphics::RenderObject mScreenQuad;

	IExeEngine::Graphics::StandardEffect mStandardEffect;
	IExeEngine::Graphics::ShadowEffect mShadowEffect;

	// --- MISSING TERRAIN EFFECT ADDED ---
	IExeEngine::Graphics::TerrainEffect mTerrainEffect;
	// ------------------------------------
};