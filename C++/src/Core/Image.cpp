#include "Image.h"

namespace Raytracer::Core
{
	Image::Image()
		: m_Width(NULL), m_Height(NULL), 
		m_Data(std::vector<Color>()), m_TextureID(NULL)
	{

		CreateGLTexture();
	}

	Image::Image(int width, int height)
		: m_Width(width), m_Height(height)
	{
		m_Data = std::vector<Color>(width * height);

		CreateGLTexture();
		UpdateGLTexture();
	}

	Image::~Image()
	{
		glDeleteTextures(1, &m_TextureID);
	}

	#pragma region Pixel Setters

	void Image::SetPixel(int x, int y, const Color& color)
	{
		m_Data[y * m_Width + x] = color;
		
		UpdateGLPixel(x, y);
	}

	void Image::SetPixel(int x, int y, const glm::vec4& color)
	{
		m_Data[y * m_Width + x] = Color(color);

		UpdateGLPixel(x, y);
	}

	void Image::SetPixel(int x, int y, float red, float green, float blue, float alpha)
	{
		m_Data[y * m_Width + x] = Color(red, green, blue, alpha);
		
		UpdateGLPixel(x, y);
	}

	void Image::Resize(int width, int height)
	{
		m_Width = width;
		m_Height = height;

		m_Data.resize(static_cast<size_t>(width) * static_cast<size_t>(height));
	}

	#pragma endregion

	#pragma region OpenGL Functions

	void Image::BindTexture() const
	{
		glBindTexture(GL_TEXTURE_2D, m_TextureID);
	}

	void Image::CreateGLTexture()
	{
		glGenTextures(1, &m_TextureID);

		glBindTexture(GL_TEXTURE_2D, m_TextureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_FLOAT, &m_Data);
	
		glBindTexture(GL_TEXTURE_2D, NULL);
	}

	void Image::UpdateGLTexture()
	{
		glBindTexture(GL_TEXTURE_2D, m_TextureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_Width, m_Height, GL_RGBA, GL_FLOAT, &m_Data);
		glBindTexture(GL_TEXTURE_2D, NULL);
	}

	void Image::UpdateGLPixel(int x, int y)
	{
		glBindTexture(GL_TEXTURE_2D, m_TextureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexSubImage2D(GL_TEXTURE_2D, 0, x, y, 1, 1, GL_RGBA, GL_FLOAT, &m_Data[y * m_Width + x]);
		glBindTexture(GL_TEXTURE_2D, NULL);
	}

	#pragma endregion
}