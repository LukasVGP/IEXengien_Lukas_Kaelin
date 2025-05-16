#include <IExeEngine/Inc/IExeEngine.h>
#include "ShapeState.h"
#include <Windows.h>

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    IExeEngine::AppConfig config;
    config.appName = L"Fruit Shapes";
    config.winWidth = 1200;
    config.winHeight = 720;

    IExeEngine::App& myApp = IExeEngine::MainApp();
    myApp.AddState<ShapeState>("ShapeState");

    myApp.Run(config);

    return 0;
}
