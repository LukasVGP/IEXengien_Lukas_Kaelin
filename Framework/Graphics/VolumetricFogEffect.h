#pragma once

#include <IExeEngine/Inc/IExeEngine.h>

namespace IExeEngine::Graphics
{
    class VolumetricFogEffect
    {
    public:
        void Initialize(const std::filesystem::path& shaderPath);
        void Terminate();

        void Begin();
        void End();
        void Render(const RenderObject& renderObject);

        void SetCamera(const Camera& camera);
        void SetDirectionalLight(const DirectionalLight& light);
        void SetDepthMap(Texture depthMap);

        void DebugUI();

    private:
        // Struct for Fog Parameters (matches the HLSL constant buffer)
        struct FogData
        {
            Color fogColor;
            float fogDensity;
            float fogHeightFalloff;
            float maxFogDistance;
            float padding;
        };

        using FogBuffer = TypedConstantBuffer<FogData>;

        // Shader resource IDs
        VertexShader mVertexShader;
        PixelShader mPixelShader;
        Sampler mSampler;

        // Constant Buffers
        FogBuffer mFogBuffer;

        // Input Resources
        const Camera* mCamera = nullptr;
        const DirectionalLight* mDirectionalLight = nullptr;

        // Textures
        Texture mDepthMap;

        // Fog Control Parameters
        FogData mFogData;
    };
}