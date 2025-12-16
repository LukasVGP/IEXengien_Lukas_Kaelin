#include "Precompiled.h" // FIX: Must be the first include for Precompiled Headers to work.

#include "VolumetricFogEffect.h"

// Standard Library Includes (if any, placed before engine includes)
// #include <filesystem> (already used by the path argument)

// Engine Includes (using angle brackets for system-wide includes)
#include <IExeEngine/Inc/Graphics/PixelShader.h>
#include <IExeEngine/Inc/Graphics/VertexShader.h>
#include <IExeEngine/Inc/Graphics/Sampler.h>
#include <IExeEngine/Inc/Graphics/ConstantBuffer.h>
#include <IExeEngine/Inc/Graphics/Texture.h>
#include <IExeEngine/Inc/Graphics/Camera.h>
#include <IExeEngine/Inc/Graphics/DirectionalLight.h>
#include <IExeEngine/Inc/Color.h>
#include <IExeEngine/Inc/DebugUI.h> // Includes ImGui headers
#include <IExeEngine/Inc/IExeEngine.h>
#include <IExeEngine/Inc/Graphics/RenderObject.h>

// External Library Includes (specifically for ImGui flags)
// FIX: The compiler cannot find ImGuiTreeNodeFlags_DefaultOpen, 
// which is a flag from the ImGui library.
// Assuming DebugUI.h provides the core ImGui definitions, 
// we only need to ensure ImGui is available.

using namespace IExeEngine;
using namespace IExeEngine::Graphics;

void VolumetricFogEffect::Initialize(const std::filesystem::path& shaderPath)
{
    // Initialize Shaders
    mVertexShader.Initialize(shaderPath);
    mPixelShader.Initialize(shaderPath);

    // Initialize Sampler for depth map reading
    mSampler.Initialize(Sampler::Filter::Linear, Sampler::AddressMode::Clamp);

    // Initialize Constant Buffer
    mFogBuffer.Initialize();

    // Default Fog Values
    mFogData.fogColor = { 0.5f, 0.5f, 0.55f, 1.0f }; // Slightly blue-gray
    mFogData.fogDensity = 0.05f;
    mFogData.fogHeightFalloff = 0.1f;
    mFogData.maxFogDistance = 100.0f;
}

void VolumetricFogEffect::Terminate()
{
    mFogBuffer.Terminate();
    mSampler.Terminate();
    mPixelShader.Terminate();
    mVertexShader.Terminate();
}

void VolumetricFogEffect::Begin()
{
    // Activate Shaders and Sampler
    mVertexShader.Bind();
    mPixelShader.Bind();
    mSampler.BindPS(0); // Bind sampler to slot 0

    // Update and Bind Fog Buffer
    mFogBuffer.Update(mFogData);
    mFogBuffer.BindPS(1); // Bind to slot 1 (example)

    // Bind Textures (Depth Map from the G-Buffer or Shadow Map)
    mDepthMap.BindPS(0); // Bind Depth Map to slot 0 (example slot, match shader)
}

void VolumetricFogEffect::End()
{
    // Unbind resources
    mDepthMap.UnbindPS(0);
}

void VolumetricFogEffect::Render(const RenderObject& renderObject)
{
    // Render the full-screen quad (contained in the RenderObject's meshBuffer)
    renderObject.meshBuffer.Render();
}

void VolumetricFogEffect::SetCamera(const Camera& camera)
{
    mCamera = &camera;
}

void VolumetricFogEffect::SetDirectionalLight(const DirectionalLight& light)
{
    mDirectionalLight = &light;
}

void VolumetricFogEffect::SetDepthMap(Texture depthMap)
{
    mDepthMap = depthMap;
}

void VolumetricFogEffect::DebugUI()
{
    // FIX: The ImGui:: is correctly used here. The error was likely caused by 
    // DebugUI.h not being processed correctly due to the precompiled header issue.
    if (ImGui::CollapsingHeader("Volumetric Fog", ImGuiTreeNodeFlags_DefaultOpen))
    {
        ImGui::ColorEdit4("Fog Color", &mFogData.fogColor.r);
        ImGui::DragFloat("Density", &mFogData.fogDensity, 0.001f, 0.0f, 1.0f);
        ImGui::DragFloat("Height Falloff", &mFogData.fogHeightFalloff, 0.001f, 0.0f, 1.0f);
        ImGui::DragFloat("Max Distance", &mFogData.maxFogDistance, 1.0f, 10.0f, 1000.0f);
    }
}