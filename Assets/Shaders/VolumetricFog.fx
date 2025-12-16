//------------------------------------------------------------------------------
// Constant Buffers (Must match C++ slots)
//------------------------------------------------------------------------------

// Assuming your engine uses a standard Camera/Transform buffer (b0) and a Light buffer (b2 or b3)
// We only define the Fog buffer here (b1)

cbuffer FogBuffer : register(b1)
{
    float4 fogColor;
    float fogDensity;
    float fogHeightFalloff;
    float maxFogDistance;
    float padding; // Ensure 16-byte alignment
};

//------------------------------------------------------------------------------
// Textures and Sampler (Must match C++ slots)
//------------------------------------------------------------------------------

Texture2D depthMap : register(t0);
SamplerState Sampler0 : register(s0);

//------------------------------------------------------------------------------
// Vertex Shader (Standard screen quad setup)
//------------------------------------------------------------------------------

struct VS_INPUT
{
    float3 position : POSITION;
    float2 uv : TEXCOORD0;
};

struct PS_INPUT
{
    float4 position : SV_Position;
    float2 uv : TEXCOORD0;
};

PS_INPUT VS(VS_INPUT input)
{
    PS_INPUT output;
    output.position = float4(input.position, 1.0f);
    output.uv = input.uv;
    return output;
}

//------------------------------------------------------------------------------
// Pixel Shader (Volumetric Raymarching)
//------------------------------------------------------------------------------

// Utility function to reconstruct world position from Depth and UV
// (This function relies on engine-specific projection data, not included here)
float3 GetWorldPosition(float2 uv, float linearDepth)
{
    // Placeholder: You MUST replace this with your engine's actual World Position Reconstruction logic
    // Example concept (requires Inverse ViewProjection matrix, usually in a CameraBuffer):
    // float4 clipPos = float4(uv * 2.0f - 1.0f, linearDepth, 1.0f); 
    // float4 worldPos = mul(clipPos, InverseViewProjectionMatrix);
    // return worldPos.xyz / worldPos.w;
    
    return float3(0, 0, 0); 
}

float4 PS(PS_INPUT input) : SV_Target
{
    float2 uv = input.uv;

    // 1. Get Linear Depth (from rendered scene depth map)
    float depth = depthMap.Sample(Sampler0, uv).r;
    float linearDepth = depth; // Assuming depth map is already linear

    // 2. Reconstruct World Position of the far scene pixel
    float3 worldPos = GetWorldPosition(uv, linearDepth);
    
    // 3. Define Ray
    // Ray starts at Camera Position (camPos) and ends at worldPos
    // camPos must be passed via your CameraBuffer (e.g., from b0)
    // float3 camPos = CameraBuffer.cameraPosition; 
    
    // Placeholder Ray definitions:
    float3 camPos = float3(0, 1.5f, -3.0f); // Use a hardcoded value if CameraBuffer isn't ready
    float3 rayDir = normalize(worldPos - camPos);
    float rayLength = length(worldPos - camPos);

    // 4. Raymarch Parameters
    const int numSteps = 50;
    float stepSize = rayLength / numSteps;
    float totalFog = 0.0f;

    // 5. Raymarching Loop
    for (int i = 0; i < numSteps; ++i)
    {
        float t = i * stepSize;
        float3 currentPos = camPos + rayDir * t;

        // Calculate height attenuation (Exponential Height Fog)
        float heightFactor = exp(-currentPos.y * fogHeightFalloff);
        
        // Calculate density at this point
        float density = fogDensity * heightFactor;
        
        // Accumulate fog attenuation (using Beer's law approximation)
        totalFog += density * stepSize;
        
        // Optimization: Break early if fog is fully opaque
        if (totalFog > 1.0f)
        {
            totalFog = 1.0f;
            break;
        }
    }
    
    // Clamp fog amount and respect max distance
    float fogAmount = 1.0f - exp(-totalFog);
    fogAmount = saturate(fogAmount * (rayLength / maxFogDistance)); // Fade out fog further than maxFogDistance

    // 6. Final Color Calculation (Simple Attenuation)
    // Fog is blended over the existing scene color (which is implicitly the render target).
    
    // NOTE: In a real post-processing pipeline, you would read the rendered scene color (t1), 
    // apply the fog blend, and output the result. Since we don't have the scene color input here,
    // we assume this shader's output will ADD to the existing scene or overwrite it.
    
    // To visualize the fog layer itself (for debugging):
    return float4(fogColor.rgb, fogAmount); 
}