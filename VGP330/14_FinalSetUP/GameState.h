// GameState.h (for 14_FinalSetUP)
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

	// Renamed Models for clarity and final scene setup
	IExeEngine::Graphics::RenderGroup mUnionSoldier;
	IExeEngine::Graphics::RenderGroup mCSASoldier;
	IExeEngine::Graphics::RenderGroup mCannon;

	IExeEngine::Graphics::RenderObject mGround;
	IExeEngine::Graphics::Terrain mTerrain;
	IExeEngine::Graphics::RenderObject mScreenQuad;

	IExeEngine::Graphics::StandardEffect mStandardEffect;
	IExeEngine::Graphics::ShadowEffect mShadowEffect;
	IExeEngine::Graphics::TerrainEffect mTerrainEffect;
};