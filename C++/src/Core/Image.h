#pragma once

#include <memory>
#include <vector>

#include <glad/glad.h>
#include <gl/GL.h>
#include <glm/vec4.hpp>

#include "Color.h"

namespace Raytracer::Core
{

	class Image
	{
		public:
			
			Image(int width, int height);
			~Image();

			void SetPixel(int x, int y, const Color& color);
			void SetPixel(int x, int y, const glm::vec4& color);
			void SetPixel(int x, int y, float r, float g, float b, float a);

			void Resize(int width, int height);

			int getWidth() const { 
				return m_Width; 
			}
			
			int getHeight() const { 
				return m_Height; 
			}

			void BindTexture() const;

			GLuint GetTextureID() const { 
				return m_TextureID; 
			}

		private:
			void CreateGLTexture();
			void UpdateGLTexture();
			void UpdateGLPixel(int x, int y);

		private:
			uint32_t m_Width = 0, m_Height = 0;
			Color* m_Data;

			GLuint m_TextureID = NULL;
	};
}