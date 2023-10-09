#include "AppLayers.h"

namespace Raytracer
{
	void RendererLayer::OnAttach()
	{

	}

	void RendererLayer::OnDetach()
	{

	}

	void RendererLayer::OnUpdate()
	{

	}

	void RendererLayer::OnEvent()
	{

	}

	void RendererLayer::OnImGuiRender()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
		// -- Renderer Viewport --
		ImGui::Begin("Viewport");
		{
			// ImGui::Image();

			// An ImGui button locked to the bottom right of the viewport window.
			// This button will start or abort the render.
			ImGui::SetCursorPos(ImVec2(ImGui::GetWindowSize().x - 125, ImGui::GetWindowSize().y - 75));
			if (ImGui::Button("Render", ImVec2(100, 50)))
			{
				m_Renderer->StartRender();
			}

		}
		ImGui::End();
		ImGui::PopStyleVar();

		// -- Renderer Settings --
		ImGui::Begin("Settings");
		{
			
		}
		ImGui::End();
	}
}