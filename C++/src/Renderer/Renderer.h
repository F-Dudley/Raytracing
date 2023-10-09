#pragma once

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
			~Renderer();

			void StartRender();
			void AbortRender();

			bool IsRunning() const { return m_Running; }

		private:
			void Render();

		public:


		private:
			bool m_Running = false;
	};
}