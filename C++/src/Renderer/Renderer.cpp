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

		m_Image->Resize(1280, 720);

		for (int x = 0; x < m_Image->getWidth(); x++)
		{
			for (int y = 0; y < m_Image->getHeight(); y++)
			{
				m_Image->SetPixel(x, y, Core::Color { 1.0f, 1.0f, 1.0f, 1.0f } );
			}
		}
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