#pragma once

#include <glm/vec4.hpp>

namespace Raytracer::Core
{
	struct Color : public glm::vec4
	{
		Color() : glm::vec4(0.0f, 0.0f, 0.0f, 1.0f) 
		{}

		Color(glm::vec4& color) : glm::vec4(color) 
		{}
		Color(const glm::vec4& color) : glm::vec4(color)
		{}

		Color(float r, float g, float b, float a = 1.0f) 
			: glm::vec4(r, g, b, a) 
		{}

		Color& operator=(const Color& other)
		{
			if (this != &other)
			{
				// Copy over the members from the other object
				r = other.r;
				g = other.g;
				b = other.b;
				a = other.a;
			}
			return *this;
		}

		float& a = w;
		float& b = z;
		float& g = y;
		float& r = x;
	};
}