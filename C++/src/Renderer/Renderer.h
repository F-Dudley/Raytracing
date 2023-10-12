#pragma once

#include <iostream>

#include "Image.h"

namespace Raytracer::Renderer
{
	enum RendererState
	{
		IDLE,
		RENDERING,
		RENDERED,
		ABORTED
	};

	class Renderer
	{
		public:
			Renderer();
			Renderer(const std::shared_ptr<Core::Image> image);

			~Renderer() = default;

			void StartRender();
			void AbortRender();

			bool IsRunning() const { return m_Running; }

			std::shared_ptr<Core::Image> GetImage() const { return m_Image; }
			
			Core::Image* GetImagePtr() const { return m_Image.get(); }

		private:
			void Render();

		public:


		private:
			bool m_Running = false;

			std::shared_ptr<Raytracer::Core::Image> m_Image;
	};
}