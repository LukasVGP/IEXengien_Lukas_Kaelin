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

	// Existing models
	IExeEngine::Graphics::RenderGroup mCharacter;
	IExeEngine::Graphics::RenderGroup parasite;
	IExeEngine::Graphics::RenderGroup zombie;

	// NEW 4th MODEL
	IExeEngine::Graphics::RenderGroup csaSoldier;

	IExeEngine::Graphics::StandardEffect mStandardEffect;
};