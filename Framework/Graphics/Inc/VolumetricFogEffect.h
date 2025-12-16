#pragma once

#include <IExeEngine/Inc/IExeEngine.h>

// Note: Ensure the path to the ImGui utilities is included if it's separate from IExeEngine.h
// #include <IExeEngine/Inc/DebugUI.h> 

namespace IExeEngine::Graphics
{
    // The struct must be 16-byte aligned to match the HLSL constant buffer (CB) packing rules.
    class VolumetricFogEffect
    {
    public:
        // C++ Structure matching the HLSL FogBuffer (b1)
        struct FogData
        {
            Color fogColor;             // HLSL: float4
            float fogDensity;           // HLSL: float
            float fogHeightFalloff;     // HLSL: float
            float maxFogDistance;       // HLSL: float
            float padding;              // HLSL: float (Ensures 16-byte alignment if needed)
        };

        // Define the Constant Buffer type using the engine's template
        // Note: TypedConstantBuffer must be defined in ConstantBuffer.h
        using FogBuffer = TypedConstantBuffer<FogData>;

    public:
        void Initialize(const std::filesystem::path& shaderPath);
        void Terminate();

        void Begin();
        void End();
        void Render(const RenderObject& renderObject); // Renders the screen quad

        void SetCamera(const Camera& camera);
        void SetDirectionalLight(const DirectionalLight& light);

        // Sets the depth map, typically the depth buffer from the ShadowEffect or G-Buffer.
        void SetDepthMap(Texture depthMap);

        void DebugUI();

    private:
        // Shader resource IDs
        VertexShader mVertexShader;
        PixelShader mPixelShader;
        Sampler mSampler;

        // Constant Buffers
        FogBuffer mFogBuffer;

        // Input Resources (Stored as pointers to avoid copying large objects)
        const Camera* mCamera = nullptr;
        const DirectionalLight* mDirectionalLight = nullptr;

        // Textures
        Texture mDepthMap;

        // Fog Control Parameters (Host-side storage)
        FogData mFogData;
    };
}