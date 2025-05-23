#include "ShapeState.h"

using namespace IExeEngine;
using namespace IExeEngine::Math;
using namespace IExeEngine::Graphics;
using namespace IExeEngine::Input;

void ShapeState::Initialize()
{
    mCamera.SetPosition({ 0.0f, 1.0f, -3.0f });
    mCamera.SetLookAt({ 0.0f, 0.0f, 0.0f });
    mTransformBuffer.Initialize(sizeof(Math::Matrix4));

    // Creates a shape out of the vertices
    CreateShape();
    mMeshbuffer.Initialize(mMesh);

    std::filesystem::path shaderFilePath = L"../../Assets/Shaders/DoTexture.fx";
    mVertexShader.Initialize<VertexPX>(shaderFilePath);
    mPixelShader.Initialize(shaderFilePath);

    mTexture.Initialize(L"../../Assets/Textures/skysphere/space.jpg");
    mSampler.Initialize(Sampler::Filter::Linear, Sampler::AddressMode::Wrap);
}

void ShapeState::Terminate()
{
    mTransformBuffer.Terminate();
    mPixelShader.Terminate();
    mVertexShader.Terminate();
    mMeshbuffer.Terminate();
    mSampler.Terminate();
    mTexture.Terminate();
}

void ShapeState::Update(float deltaTime)
{
    // Camera Controls:
    InputSystem* input = InputSystem::Get();
    const float moveSpeed = input->IsKeyDown(KeyCode::LSHIFT) ? 10.0f : 4.0f;
    const float turnSpeed = 0.5f;

    if (input->IsKeyDown(KeyCode::W)) { mCamera.Walk(moveSpeed * deltaTime); }
    else if (input->IsKeyDown(KeyCode::S)) { mCamera.Walk(-moveSpeed * deltaTime); }
    else if (input->IsKeyDown(KeyCode::D)) { mCamera.Strafe(moveSpeed * deltaTime); }
    else if (input->IsKeyDown(KeyCode::A)) { mCamera.Strafe(-moveSpeed * deltaTime); }
    else if (input->IsKeyDown(KeyCode::E)) { mCamera.Rise(moveSpeed * deltaTime); }
    else if (input->IsKeyDown(KeyCode::Q)) { mCamera.Rise(-moveSpeed * deltaTime); }

    if (input->IsMouseDown(MouseButton::RBUTTON))
    {
        mCamera.Yaw(input->GetMouseMoveX() * turnSpeed * deltaTime);
        mCamera.Pitch(input->GetMouseMoveY() * turnSpeed * deltaTime);
    }

    // Scene Change Controls:
    if (Input::InputSystem::Get()->IsKeyPressed(Input::KeyCode::UP))
    {
        IExeEngine::MainApp().ChangeState("Pyramid");
    }
    if (Input::InputSystem::Get()->IsKeyPressed(Input::KeyCode::LEFT))
    {
        IExeEngine::MainApp().ChangeState("Cube");
    }
    if (Input::InputSystem::Get()->IsKeyPressed(Input::KeyCode::RIGHT))
    {
        IExeEngine::MainApp().ChangeState("Rectangle");
    }
}

void ShapeState::Render()
{
    // Prepare GPU
    mVertexShader.Bind();
    mPixelShader.Bind();
    mSampler.BindPS(0);
    mTexture.BindPS(0);

    // Sync Transform Buffer
    mTransformBuffer.BindVS(0);

    // Update the Buffer Data
    Math::Matrix4 matWorld = Math::Matrix4::Identity;
    Math::Matrix4 matView = mCamera.GetViewMatrix();
    Math::Matrix4 matProj = mCamera.GetProjectionMatrix();
    Math::Matrix4 matFinal = matWorld * matView * matProj; // = wvp
    Math::Matrix4 wvp = Math::Transpose(matFinal);
    mTransformBuffer.Update(&wvp);

    // Draw
    mMeshbuffer.Render();
}

void ShapeState::CreateShape()
{
    // Uncomment one of these lines - using a PX mesh to match the vertex shader
    mMesh = MeshBuilder::CreateSpherePX(30, 30, 1.0f);
    // mMesh = MeshBuilder::CreateSkySpherePX(30, 30, 250.0f);
    // mMesh = MeshBuilder::CreatePlanePX(30, 30, 1.0f);
}

// CubeState implementation
void CubeState::Update(float deltaTime)
{
    ShapeState::Update(deltaTime);
    // Any additional cube-specific update code
}

void CubeState::CreateShape()
{
    // Since we're using VertexPX shader, we need a PX mesh
    // If MeshBuilder::CreateCubePX exists, use that instead
    mMesh = MeshBuilder::CreateSpherePX(30, 30, 1.0f); // Placeholder
}

// PyramidState implementation
void PyramidState::Update(float deltaTime)
{
    ShapeState::Update(deltaTime);
    // Any additional pyramid-specific update code
}

void PyramidState::CreateShape()
{
    // Since we're using VertexPX shader, we need a PX mesh
    // If MeshBuilder::CreatePyramidPX exists, use that instead
    mMesh = MeshBuilder::CreateSpherePX(30, 30, 1.0f); // Placeholder
}

// RectangleState implementation
void RectangleState::Update(float deltaTime)
{
    ShapeState::Update(deltaTime);
    // Any additional rectangle-specific update code
}

void RectangleState::CreateShape()
{
    // Since we're using VertexPX shader, we need a PX mesh
    // If MeshBuilder::CreateRectanglePX exists, use that instead
    mMesh = MeshBuilder::CreatePlanePX(30, 30, 1.0f); // Placeholder
}
