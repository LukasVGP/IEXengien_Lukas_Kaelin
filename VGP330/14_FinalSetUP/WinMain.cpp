// WinMain.cpp (for 14_FinalSetUP)
#include "GameState.h"

using namespace IExeEngine;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	AppConfig config;
	// Change the application name to reflect the new project
	config.appName = L"14_FinalSetUP - Battlefield Vignette";

	App& myApp = MainApp();

	myApp.AddState<GameState>("GameState");

	myApp.Run(config);

	return 0;
}