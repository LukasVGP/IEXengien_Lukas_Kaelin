#include <IExeEngine/Inc/IExeEngine.h>
#include "ShapeState.h"

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
    try
    {
        IExeEngine::AppConfig config;
        config.appName = L"Hello MeshBuilder";

        IExeEngine::App& myApp = IExeEngine::MainApp();

        // Add all states
        myApp.AddState<ShapeState>("ShapeState");
        myApp.AddState<CubeState>("Cube");
        myApp.AddState<PyramidState>("Pyramid");
        myApp.AddState<RectangleState>("Rectangle");

        // The first added state will be the initial state by default
        // If you need to specify a different initial state, check if there's a method like:
        // myApp.SetStartState("ShapeState") or similar in your engine API

        myApp.Run(config);
    }
    catch (const std::exception& e)
    {
        MessageBoxA(nullptr, e.what(), "Error", MB_OK | MB_ICONERROR);
    }
    return 0;
}
