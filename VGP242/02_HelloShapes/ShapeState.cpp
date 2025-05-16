#include "ShapeState.h"
#include <cmath> // For sin and cos functions

using namespace IExeEngine;
using namespace IExeEngine::Math;
using namespace IExeEngine::Graphics;

void ShapeState::Initialize()
{
    // Creates a shape out of the vertices
    CreateShape();
    auto device = GraphicsSystem::Get()->GetDevice();
    // Need to create a buffer to store the vertices
    // STORES DATA FOR THE OBJECT
    D3D11_BUFFER_DESC bufferDesc{};
    bufferDesc.ByteWidth = static_cast<UINT>(mVertices.size()) * sizeof(Vertex);
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bufferDesc.MiscFlags = 0;
    bufferDesc.StructureByteStride = 0;
    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = mVertices.data();
    HRESULT hr = device->CreateBuffer(&bufferDesc, &initData, &mVertexBuffer);
    ASSERT(SUCCEEDED(hr), "Failed to create Vertex Buffer");
    //====================================================================================================
    // BIND TO FUNCTION IN SPECIFIED SHADER FILE
    std::filesystem::path shaderFilePath = L"../../Assets/Shaders/DoColor.fx";
    DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
    ID3DBlob* shaderBlob = nullptr;
    ID3DBlob* errorBlob = nullptr;
    hr = D3DCompileFromFile(
        shaderFilePath.c_str(),
        nullptr,
        D3D_COMPILE_STANDARD_FILE_INCLUDE,
        "VS", "vs_5_0",
        shaderFlags, 0,
        &shaderBlob,
        &errorBlob);
    if (errorBlob != nullptr && errorBlob->GetBufferPointer() != nullptr)
    {
        LOG("%s", static_cast<const char*>(errorBlob->GetBufferPointer()));
    }
    ASSERT(SUCCEEDED(hr), "Failed to create Vertex Shader");
    hr = device->CreateVertexShader(
        shaderBlob->GetBufferPointer(),
        shaderBlob->GetBufferSize(),
        nullptr,
        &mVertexShader);
    ASSERT(SUCCEEDED(hr), "Failed to create Vertex Shader");
    //======================================================================================================
    // STATE WHAT THE VERTEX VARIABLES ARE
    std::vector<D3D11_INPUT_ELEMENT_DESC> vertexLayout;
    vertexLayout.push_back({ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,0,D3D11_APPEND_ALIGNED_ELEMENT });
    vertexLayout.push_back({ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT,0,D3D11_APPEND_ALIGNED_ELEMENT });
    hr = device->CreateInputLayout(
        vertexLayout.data(),
        static_cast<UINT>(vertexLayout.size()),
        shaderBlob->GetBufferPointer(),
        shaderBlob->GetBufferSize(),
        &mInputLayout);
    ASSERT(SUCCEEDED(hr), "Failed to create Input Layout");
    SafeRelease(shaderBlob);
    SafeRelease(errorBlob);
    //======================================================================================================
    // BIND TO PIXEL FUNCTION IN SPECIFIED SHADER FILE
    hr = D3DCompileFromFile(
        shaderFilePath.c_str(),
        nullptr,
        D3D_COMPILE_STANDARD_FILE_INCLUDE,
        "PS", "ps_5_0",
        shaderFlags, 0,
        &shaderBlob,
        &errorBlob);
    if (errorBlob != nullptr && errorBlob->GetBufferPointer() != nullptr)
    {
        LOG("%s", static_cast<const char*>(errorBlob->GetBufferPointer()));
    }
    ASSERT(SUCCEEDED(hr), "Failed to create Pixel Shader");
    hr = device->CreatePixelShader(
        shaderBlob->GetBufferPointer(),
        shaderBlob->GetBufferSize(),
        nullptr,
        &mPixelShader);
    ASSERT(SUCCEEDED(hr), "Failed to create Pixel Shader");
    SafeRelease(shaderBlob);
    SafeRelease(errorBlob);
}

void ShapeState::Terminate()
{
    mVertices.clear();
    SafeRelease(mPixelShader);
    SafeRelease(mInputLayout);
    SafeRelease(mVertexShader);
    SafeRelease(mVertexBuffer);
}

void ShapeState::Render()
{
    auto context = GraphicsSystem::Get()->GetContext();
    // Bind buffers
    context->VSSetShader(mVertexShader, nullptr, 0);
    context->IASetInputLayout(mInputLayout);
    context->PSSetShader(mPixelShader, nullptr, 0);
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    // Draw
    UINT stride = sizeof(Vertex);
    UINT offset = 0;
    context->IASetVertexBuffers(0, 1, &mVertexBuffer, &stride, &offset);
    context->Draw(static_cast<UINT>(mVertices.size()), 0);
}

void ShapeState::Update(float deltaTime)
{
    // Check for key presses to change the displayed fruit
    if (Input::InputSystem::Get()->IsKeyPressed(Input::KeyCode::UP))
    {
        LOG("Changing to Apple");
        if (mCurrentFruit != FruitType::Apple)
        {
            mCurrentFruit = FruitType::Apple;
            mVertices.clear();
            CreateShape();

            // Recreate the vertex buffer with the new vertices
            auto device = GraphicsSystem::Get()->GetDevice();
            SafeRelease(mVertexBuffer);

            D3D11_BUFFER_DESC bufferDesc{};
            bufferDesc.ByteWidth = static_cast<UINT>(mVertices.size()) * sizeof(Vertex);
            bufferDesc.Usage = D3D11_USAGE_DEFAULT;
            bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
            bufferDesc.MiscFlags = 0;
            bufferDesc.StructureByteStride = 0;
            D3D11_SUBRESOURCE_DATA initData = {};
            initData.pSysMem = mVertices.data();
            HRESULT hr = device->CreateBuffer(&bufferDesc, &initData, &mVertexBuffer);
            ASSERT(SUCCEEDED(hr), "Failed to create Vertex Buffer");
        }
    }
    else if (Input::InputSystem::Get()->IsKeyPressed(Input::KeyCode::LEFT))
    {
        LOG("Changing to Banana");
        if (mCurrentFruit != FruitType::Banana)
        {
            mCurrentFruit = FruitType::Banana;
            mVertices.clear();
            CreateShape();

            // Recreate the vertex buffer with the new vertices
            auto device = GraphicsSystem::Get()->GetDevice();
            SafeRelease(mVertexBuffer);

            D3D11_BUFFER_DESC bufferDesc{};
            bufferDesc.ByteWidth = static_cast<UINT>(mVertices.size()) * sizeof(Vertex);
            bufferDesc.Usage = D3D11_USAGE_DEFAULT;
            bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
            bufferDesc.MiscFlags = 0;
            bufferDesc.StructureByteStride = 0;
            D3D11_SUBRESOURCE_DATA initData = {};
            initData.pSysMem = mVertices.data();
            HRESULT hr = device->CreateBuffer(&bufferDesc, &initData, &mVertexBuffer);
            ASSERT(SUCCEEDED(hr), "Failed to create Vertex Buffer");
        }
    }
    else if (Input::InputSystem::Get()->IsKeyPressed(Input::KeyCode::RIGHT))
    {
        LOG("Changing to Orange");
        if (mCurrentFruit != FruitType::Orange)
        {
            mCurrentFruit = FruitType::Orange;
            mVertices.clear();
            CreateShape();

            // Recreate the vertex buffer with the new vertices
            auto device = GraphicsSystem::Get()->GetDevice();
            SafeRelease(mVertexBuffer);

            D3D11_BUFFER_DESC bufferDesc{};
            bufferDesc.ByteWidth = static_cast<UINT>(mVertices.size()) * sizeof(Vertex);
            bufferDesc.Usage = D3D11_USAGE_DEFAULT;
            bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
            bufferDesc.MiscFlags = 0;
            bufferDesc.StructureByteStride = 0;
            D3D11_SUBRESOURCE_DATA initData = {};
            initData.pSysMem = mVertices.data();
            HRESULT hr = device->CreateBuffer(&bufferDesc, &initData, &mVertexBuffer);
            ASSERT(SUCCEEDED(hr), "Failed to create Vertex Buffer");
        }
    }
    else if (Input::InputSystem::Get()->IsKeyPressed(Input::KeyCode::DOWN))
    {
        LOG("Changing to All Fruits");
        if (mCurrentFruit != FruitType::All)
        {
            mCurrentFruit = FruitType::All;
            mVertices.clear();
            CreateShape();

            // Recreate the vertex buffer with the new vertices
            auto device = GraphicsSystem::Get()->GetDevice();
            SafeRelease(mVertexBuffer);

            D3D11_BUFFER_DESC bufferDesc{};
            bufferDesc.ByteWidth = static_cast<UINT>(mVertices.size()) * sizeof(Vertex);
            bufferDesc.Usage = D3D11_USAGE_DEFAULT;
            bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
            bufferDesc.MiscFlags = 0;
            bufferDesc.StructureByteStride = 0;
            D3D11_SUBRESOURCE_DATA initData = {};
            initData.pSysMem = mVertices.data();
            HRESULT hr = device->CreateBuffer(&bufferDesc, &initData, &mVertexBuffer);
            ASSERT(SUCCEEDED(hr), "Failed to create Vertex Buffer");
        }
    }
}

void ShapeState::CreateShape()
{
    switch (mCurrentFruit)
    {
    case FruitType::Apple:
        CreateApple();
        break;
    case FruitType::Banana:
        CreateBanana();
        break;
    case FruitType::Orange:
        CreateOrange();
        break;
    case FruitType::All:
    default:
        CreateAllFruits();
        break;
    }
}

void ShapeState::CreateApple()
{
    LOG("Creating Apple shape");

    // Create a very simple red circle for the apple
    Color appleRed = { 1.0f, 0.0f, 0.0f, 1.0f };
    Color stemBrown = { 0.5f, 0.3f, 0.0f, 1.0f };
    Color leafGreen = { 0.0f, 0.8f, 0.0f, 1.0f };

    // Create a simple circle for the apple body
    const int numSegments = 12;
    const float radius = 0.4f;

    for (int i = 0; i < numSegments; ++i) {
        float angle1 = 2.0f * 3.14159f * i / numSegments;
        float angle2 = 2.0f * 3.14159f * (i + 1) / numSegments;

        float x1 = radius * std::cos(angle1);
        float y1 = radius * std::sin(angle1);
        float x2 = radius * std::cos(angle2);
        float y2 = radius * std::sin(angle2);

        mVertices.push_back({ { 0.0f, 0.0f, 0.0f }, appleRed });
        mVertices.push_back({ { x1, y1, 0.0f }, appleRed });
        mVertices.push_back({ { x2, y2, 0.0f }, appleRed });
    }

    // Add a stem (simple rectangle)
    mVertices.push_back({ { -0.05f, radius, 0.0f }, stemBrown });
    mVertices.push_back({ { 0.05f, radius, 0.0f }, stemBrown });
    mVertices.push_back({ { 0.05f, radius + 0.2f, 0.0f }, stemBrown });

    mVertices.push_back({ { -0.05f, radius, 0.0f }, stemBrown });
    mVertices.push_back({ { 0.05f, radius + 0.2f, 0.0f }, stemBrown });
    mVertices.push_back({ { -0.05f, radius + 0.2f, 0.0f }, stemBrown });

    // Add a leaf (simple triangle)
    mVertices.push_back({ { 0.05f, radius + 0.1f, 0.0f }, leafGreen });
    mVertices.push_back({ { 0.25f, radius + 0.15f, 0.0f }, leafGreen });
    mVertices.push_back({ { 0.05f, radius + 0.2f, 0.0f }, leafGreen });
}

void ShapeState::CreateBanana()
{
    LOG("Creating Banana shape");

    // Define colors for the banana
    Color bananaYellow = { 1.0f, 0.9f, 0.0f, 1.0f };
    Color bananaDarkYellow = { 0.8f, 0.7f, 0.0f, 1.0f };
    Color stemBrown = { 0.45f, 0.32f, 0.0f, 1.0f };

    // Create a simple curved banana shape
    // Main banana body (curved yellow shape)

    // Create the curved banana shape using a simple crescent
    // Top part of the banana
    mVertices.push_back({ { -0.4f, 0.1f, 0.0f }, bananaYellow });
    mVertices.push_back({ { -0.2f, 0.3f, 0.0f }, bananaYellow });
    mVertices.push_back({ { 0.0f, 0.4f, 0.0f }, bananaYellow });

    mVertices.push_back({ { -0.4f, 0.1f, 0.0f }, bananaYellow });
    mVertices.push_back({ { 0.0f, 0.4f, 0.0f }, bananaYellow });
    mVertices.push_back({ { 0.2f, 0.3f, 0.0f }, bananaYellow });

    mVertices.push_back({ { -0.4f, 0.1f, 0.0f }, bananaYellow });
    mVertices.push_back({ { 0.2f, 0.3f, 0.0f }, bananaYellow });
    mVertices.push_back({ { 0.4f, 0.0f, 0.0f }, bananaYellow });

    // Bottom part of the banana
    mVertices.push_back({ { -0.4f, 0.1f, 0.0f }, bananaYellow });
    mVertices.push_back({ { 0.4f, 0.0f, 0.0f }, bananaYellow });
    mVertices.push_back({ { 0.2f, -0.2f, 0.0f }, bananaYellow });

    mVertices.push_back({ { -0.4f, 0.1f, 0.0f }, bananaYellow });
    mVertices.push_back({ { 0.2f, -0.2f, 0.0f }, bananaYellow });
    mVertices.push_back({ { -0.2f, -0.1f, 0.0f }, bananaYellow });

    // Add stem at the top
    mVertices.push_back({ { -0.4f, 0.1f, 0.0f }, stemBrown });
    mVertices.push_back({ { -0.5f, 0.2f, 0.0f }, stemBrown });
    mVertices.push_back({ { -0.3f, 0.2f, 0.0f }, stemBrown });

    // Add some dark yellow spots
    mVertices.push_back({ { 0.0f, 0.2f, 0.0f }, bananaDarkYellow });
    mVertices.push_back({ { 0.1f, 0.1f, 0.0f }, bananaDarkYellow });
    mVertices.push_back({ { -0.1f, 0.1f, 0.0f }, bananaDarkYellow });

    mVertices.push_back({ { 0.2f, 0.0f, 0.0f }, bananaDarkYellow });
    mVertices.push_back({ { 0.1f, -0.1f, 0.0f }, bananaDarkYellow });
    mVertices.push_back({ { 0.3f, -0.1f, 0.0f }, bananaDarkYellow });
}

void ShapeState::CreateOrange()
{
    LOG("Creating Orange shape");

    // Define colors for the orange
    Color orangeColor = { 1.0f, 0.5f, 0.0f, 1.0f };
    Color orangeDark = { 0.8f, 0.4f, 0.0f, 1.0f };
    Color stemBrown = { 0.45f, 0.32f, 0.0f, 1.0f };
    Color leafGreen = { 0.0f, 0.6f, 0.0f, 1.0f };

    // Create a simple circle for the orange
    const int numSegments = 16;
    const float radius = 0.4f;

    for (int i = 0; i < numSegments; ++i) {
        float angle1 = 2.0f * 3.14159f * i / numSegments;
        float angle2 = 2.0f * 3.14159f * (i + 1) / numSegments;

        float x1 = radius * std::cos(angle1);
        float y1 = radius * std::sin(angle1);
        float x2 = radius * std::cos(angle2);
        float y2 = radius * std::sin(angle2);

        mVertices.push_back({ { 0.0f, 0.0f, 0.0f }, orangeColor });
        mVertices.push_back({ { x1, y1, 0.0f }, orangeColor });
        mVertices.push_back({ { x2, y2, 0.0f }, orangeColor });
    }

    // Add texture details (darker orange segments)
    for (int i = 0; i < 8; ++i) {
        float angle = 2.0f * 3.14159f * i / 8;
        float x = (radius * 0.7f) * std::cos(angle);
        float y = (radius * 0.7f) * std::sin(angle);

        mVertices.push_back({ { 0.0f, 0.0f, 0.0f }, orangeDark });
        mVertices.push_back({ { x, y, 0.0f }, orangeDark });
        mVertices.push_back({ { x * 0.5f, y * 0.5f, 0.0f }, orangeDark });
    }

    // Add a small stem at the top
    mVertices.push_back({ { -0.02f, radius, 0.0f }, stemBrown });
    mVertices.push_back({ { 0.02f, radius, 0.0f }, stemBrown });
    mVertices.push_back({ { 0.0f, radius + 0.05f, 0.0f }, stemBrown });

    // Add a small leaf
    mVertices.push_back({ { 0.0f, radius, 0.0f }, leafGreen });
    mVertices.push_back({ { 0.1f, radius + 0.1f, 0.0f }, leafGreen });
    mVertices.push_back({ { 0.0f, radius + 0.05f, 0.0f }, leafGreen });
}

void ShapeState::CreateAllFruits() {
    LOG("Creating all three fruits");

    // Colors
    Color appleRed = { 1.0f, 0.0f, 0.0f, 1.0f };
    Color bananaYellow = { 1.0f, 0.9f, 0.0f, 1.0f };
    Color orangeColor = { 1.0f, 0.5f, 0.0f, 1.0f };
    Color stemBrown = { 0.45f, 0.32f, 0.0f, 1.0f };
    Color leafGreen = { 0.0f, 0.6f, 0.0f, 1.0f };
    Color bananaDarkYellow = { 0.8f, 0.7f, 0.0f, 1.0f };
    Color orangeDark = { 0.8f, 0.4f, 0.0f, 1.0f };

    // Draw a red apple on the left
    const float appleRadius = 0.25f;
    const int numSegments = 12;

    // Position for the apple (left side)
    float appleX = -0.6f;
    float appleY = 0.0f;

    for (int i = 0; i < numSegments; ++i) {
        float angle1 = 2.0f * 3.14159f * i / numSegments;
        float angle2 = 2.0f * 3.14159f * (i + 1) / numSegments;

        float x1 = appleRadius * std::cos(angle1) + appleX;
        float y1 = appleRadius * std::sin(angle1) + appleY;
        float x2 = appleRadius * std::cos(angle2) + appleX;
        float y2 = appleRadius * std::sin(angle2) + appleY;

        mVertices.push_back({ { appleX, appleY, 0.0f }, appleRed });
        mVertices.push_back({ { x1, y1, 0.0f }, appleRed });
        mVertices.push_back({ { x2, y2, 0.0f }, appleRed });
    }

    // Add stem and leaf to apple
    mVertices.push_back({ { appleX - 0.03f, appleY + appleRadius, 0.0f }, stemBrown });
    mVertices.push_back({ { appleX + 0.03f, appleY + appleRadius, 0.0f }, stemBrown });
    mVertices.push_back({ { appleX, appleY + appleRadius + 0.1f, 0.0f }, stemBrown });

    mVertices.push_back({ { appleX + 0.03f, appleY + appleRadius, 0.0f }, leafGreen });
    mVertices.push_back({ { appleX + 0.15f, appleY + appleRadius + 0.05f, 0.0f }, leafGreen });
    mVertices.push_back({ { appleX + 0.03f, appleY + appleRadius + 0.1f, 0.0f }, leafGreen });

    // Draw a yellow banana in the middle
    // Position for the banana (middle)
    float bananaX = 0.0f;
    float bananaY = 0.0f;

    // Create a simple curved banana shape
    mVertices.push_back({ { bananaX - 0.2f, bananaY + 0.1f, 0.0f }, bananaYellow });
    mVertices.push_back({ { bananaX, bananaY + 0.2f, 0.0f }, bananaYellow });
    mVertices.push_back({ { bananaX + 0.2f, bananaY, 0.0f }, bananaYellow });

    mVertices.push_back({ { bananaX - 0.2f, bananaY + 0.1f, 0.0f }, bananaYellow });
    mVertices.push_back({ { bananaX + 0.2f, bananaY, 0.0f }, bananaYellow });
    mVertices.push_back({ { bananaX, bananaY - 0.2f, 0.0f }, bananaYellow });

    // Add stem to banana
    mVertices.push_back({ { bananaX - 0.2f, bananaY + 0.1f, 0.0f }, stemBrown });
    mVertices.push_back({ { bananaX - 0.3f, bananaY + 0.15f, 0.0f }, stemBrown });
    mVertices.push_back({ { bananaX - 0.15f, bananaY + 0.15f, 0.0f }, stemBrown });

    // Add some dark yellow spots
    mVertices.push_back({ { bananaX, bananaY + 0.1f, 0.0f }, bananaDarkYellow });
    mVertices.push_back({ { bananaX + 0.1f, bananaY, 0.0f }, bananaDarkYellow });
    mVertices.push_back({ { bananaX - 0.1f, bananaY, 0.0f }, bananaDarkYellow });

    // Draw an orange on the right
    const float orangeRadius = 0.25f;

    // Position for the orange (right side)
    float orangeX = 0.6f;
    float orangeY = 0.0f;

    for (int i = 0; i < numSegments; ++i) {
        float angle1 = 2.0f * 3.14159f * i / numSegments;
        float angle2 = 2.0f * 3.14159f * (i + 1) / numSegments;

        float x1 = orangeRadius * std::cos(angle1) + orangeX;
        float y1 = orangeRadius * std::sin(angle1) + orangeY;
        float x2 = orangeRadius * std::cos(angle2) + orangeX;
        float y2 = orangeRadius * std::sin(angle2) + orangeY;

        mVertices.push_back({ { orangeX, orangeY, 0.0f }, orangeColor });
        mVertices.push_back({ { x1, y1, 0.0f }, orangeColor });
        mVertices.push_back({ { x2, y2, 0.0f }, orangeColor });
    }

    // Add texture details (darker orange segments)
    for (int i = 0; i < 4; ++i) {
        float angle = 2.0f * 3.14159f * i / 4;
        float x = (orangeRadius * 0.7f) * std::cos(angle) + orangeX;
        float y = (orangeRadius * 0.7f) * std::sin(angle) + orangeY;

        mVertices.push_back({ { orangeX, orangeY, 0.0f }, orangeDark });
        mVertices.push_back({ { x, y, 0.0f }, orangeDark });
        mVertices.push_back({ { (x + orangeX) * 0.5f, (y + orangeY) * 0.5f, 0.0f }, orangeDark });
    }

    // Add a small stem at the top of the orange
    mVertices.push_back({ { orangeX - 0.02f, orangeY + orangeRadius, 0.0f }, stemBrown });
    mVertices.push_back({ { orangeX + 0.02f, orangeY + orangeRadius, 0.0f }, stemBrown });
    mVertices.push_back({ { orangeX, orangeY + orangeRadius + 0.05f, 0.0f }, stemBrown });

    // Add a small leaf
    mVertices.push_back({ { orangeX, orangeY + orangeRadius, 0.0f }, leafGreen });
    mVertices.push_back({ { orangeX + 0.1f, orangeY + orangeRadius + 0.1f, 0.0f }, leafGreen });
    mVertices.push_back({ { orangeX, orangeY + orangeRadius + 0.05f, 0.0f }, leafGreen });
}
