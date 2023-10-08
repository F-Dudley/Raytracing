#pragma once

// RaytracingInOneWeekend.cpp : Defines the entry point for the application.
//

#include <iostream>

#include "App.h"

int main()
{
	{
		std::unique_ptr<App> app = std::make_unique<App>();

		if (!app->Init())
		{
			std::cerr << "[ERROR] | App::Init | Failed to Initialize Application." << std::endl;
			
			return -1;
		}

		while (app->IsRunning())
		{
			app->HandleEvents();

			app->Update();

			app->Render();
		}

		if (!app->Clean())
		{
			std::cerr << "[ERROR] | App::Clean | Failed to Cleanup Application." << std::endl;

			return -1;
		}
	}

	return 0;
}
