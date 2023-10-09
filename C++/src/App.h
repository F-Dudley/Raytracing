#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include <GLFW/glfw3.h>

#include <imgui.h> 
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Renderer.h"
#include "Layer.h"

namespace Raytracer
{
	class App
	{

		public:
			App();
			~App();

			bool Init();
			
			void HandleEvents();
			void Update();
			void RenderGUI();

			bool Clean();

			bool IsRunning() const { return !glfwWindowShouldClose(m_Window); }

			void PushLayer(const std::shared_ptr<Window::Layer>& layer)
			{
				m_LayerStack.push_back(layer);
				layer->OnAttach();
			}

			void Quit() { glfwSetWindowShouldClose(m_Window, true); }

			// get renderer
			std::shared_ptr<Renderer::Renderer> GetRenderer() const { return m_Renderer; }

		private:

			bool InitWindow();


		private:
			GLFWwindow* m_Window = nullptr;
			std::vector<std::shared_ptr<Window::Layer>> m_LayerStack;

			std::shared_ptr<Renderer::Renderer> m_Renderer;

	};
}
