#include "Renderer.h"

#include <iostream>
#include <thread>

namespace Raytracer::Renderer
{
	Renderer::Renderer()
	{

	}

	void Renderer::StartRender()
	{
		// Start the Render Functionality on alternitive thread, so no GUI blocking.
		std::clog << "Starting Render" << std::endl;
	}

	void Renderer::AbortRender()
	{
		m_Running = false;

		// Abort the Render Functionality on alternitive thread, so no GUI blocking.
		std::clog << "Aborting Render" << std::endl;
	}

	void Renderer::Render()
	{
		std::cout << "Render Started" << std::endl;
		
		std::cout << "Render Done!" << std::endl;
	}
}