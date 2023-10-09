
#include <memory>
#include <imgui.h>

#include "Renderer.h"
#include "Layer.h"

namespace Raytracer
{
	class RendererLayer : public Window::Layer
	{
		public:
			RendererLayer(const std::shared_ptr<Renderer::Renderer> renderer) : Layer() , m_Renderer(renderer)
			{
		
			}

			virtual void OnAttach() override;
			virtual void OnDetach() override;

			virtual void OnUpdate() override;
			virtual void OnEvent() override;
			virtual void OnImGuiRender() override;

		private:
			std::shared_ptr<Renderer::Renderer> m_Renderer;
	};
}