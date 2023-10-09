#pragma once

#include <string>

namespace Raytracer::Window
{

	class Layer
	{
		public:
			Layer(const std::string& name = "Layer");
			virtual ~Layer() = default;

			virtual void OnAttach() {}
			virtual void OnDetach() {}
			virtual void OnUpdate() {}
			virtual void OnImGuiRender() {}
			virtual void OnEvent() {}

		private:
			std::string name;
	};
}