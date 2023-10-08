#pragma once

#pragma region Test
	class App
	{
		public:


		private:
			bool m_Running = true;

		public:
			App();
			~App();

			bool Init();
			
			void HandleEvents();
			void Update();
			void Render();

			bool Clean();

			bool IsRunning() const { return m_Running; }

		private:
			

	};
#pragma endregion
