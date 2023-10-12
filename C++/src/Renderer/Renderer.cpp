#include "Renderer.h"

namespace Raytracer::Renderer
{
	Renderer::Renderer()
	{
		m_Image = std::make_shared<Raytracer::Core::Image>();
	}

	Renderer::Renderer(const std::shared_ptr<Core::Image> image)
	{
		m_Image = image;
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