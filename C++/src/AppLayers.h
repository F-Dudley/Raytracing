#pragma once

#include <memory>
#include <imgui.h>

#include "Renderer.h"
#include "Layer.h"
#include "Image.h"

namespace Raytracer
{
	class RendererLayer : public Window::Layer
	{
		public:
			RendererLayer() = default;
			RendererLayer(const std::shared_ptr<Renderer::Renderer> renderer);

			virtual void OnAttach() override;
			virtual void OnDetach() override;

			virtual void OnUpdate() override;
			virtual void OnEvent() override;
			virtual void OnImGuiRender() override;

		private:
			std::shared_ptr<Raytracer::Renderer::Renderer> m_Renderer;
			std::shared_ptr<Raytracer::Core::Image> m_Image;

			uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;
	};
}