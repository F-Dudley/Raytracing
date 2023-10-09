#pragma once

// RaytracingInOneWeekend.cpp : Defines the entry point for the application.
//

#include <iostream>

#include "App.h"
#include "AppLayers.h"

int main()
{
	{
		std::unique_ptr<Raytracer::App> app = std::make_unique<Raytracer::App>();

		if (!app->Init())
		{
			std::cerr << "[ERROR] | App::Init | Failed to Initialize Application." << std::endl;
			
			return -1;
		}

		// ------------------------------
		// Add Layers To Application Here

		app->PushLayer(std::make_unique<Raytracer::RendererLayer>(app->GetRenderer()));

		// ------------------------------

		while (app->IsRunning())
		{
			app->HandleEvents();

			app->Update();

			app->RenderGUI();
		}

		if (!app->Clean())
		{
			std::cerr << "[ERROR] | App::Clean | Failed to Cleanup Application." << std::endl;

			return -1;
		}
	}

	return 0;
}
