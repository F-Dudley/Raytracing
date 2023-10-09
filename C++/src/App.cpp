
#include "App.h"

namespace Raytracer
{
	App::App()
	{
		m_LayerStack = std::vector<std::shared_ptr<Window::Layer>>();

		m_Renderer = std::shared_ptr<Renderer::Renderer>();
	}

	App::~App()
	{

	}

	bool App::Init()
	{
		if (!glfwInit())
		{
			std::cerr << "[ERROR] | App::Init | GLFW Initialization Failed." << std::endl;
		}

		if (!InitWindow())
		{
			std::cerr << "[ERROR] | App::Init | Window Initialization Failed." << std::endl;
		}

		return true;
	}

	bool App::InitWindow()
	{
		// Decide GL+GLSL versions
		#if defined(IMGUI_IMPL_OPENGL_ES2)
			// GL ES 2.0 + GLSL 100
				const char* glsl_version = "#version 100";
				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
				glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
		#elif defined(__APPLE__)
			// GL 3.2 + GLSL 150
				const char* glsl_version = "#version 150";
				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
				glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
				glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
		#else
			// GL 3.0 + GLSL 130
				const char* glsl_version = "#version 130";
				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
				//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
				//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
		#endif

		// Build GLFW Window
		m_Window = glfwCreateWindow(1280, 720, "Raytracer", NULL, NULL);
		if (m_Window == NULL)
		{
			std::cerr << "[ERROR] | App::InitWindow | Failed to create GLFW window" << std::endl;
			glfwTerminate();
			
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSwapInterval(1); // Enable vsync

		ImGui::CreateContext();


		ImGuiIO& guiIO = ImGui::GetIO(); (void) guiIO;
		guiIO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		guiIO.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		guiIO.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
	
		// ImGui Styling
		ImGui::StyleColorsDark();


		// Setup Window Styling
		ImGuiStyle& style = ImGui::GetStyle();
		if (guiIO.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 4.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		style.FrameRounding = 4.0f;

		ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
		ImGui_ImplOpenGL3_Init(glsl_version);

		return true;
	}

	void App::HandleEvents()
	{
		glfwPollEvents();

		for (auto& layer : m_LayerStack)
		{
			layer->OnEvent();
		}
	}

	void App::Update()
	{
		for (auto& layer : m_LayerStack)
		{
			layer->OnUpdate();
		}
	}

	void App::RenderGUI()
	{
		// Start New Frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		int width, height;
		glfwGetFramebufferSize(m_Window, &width, &height);
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui::DockSpaceOverViewport();
		// ----- //

		for (auto& layer : m_LayerStack)
		{
			layer->OnImGuiRender();
		}

		#ifndef NDEBUG
			ImGui::ShowDemoWindow();
		#endif

		// ----

		ImGui::Render();

		// Render ImGui
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		ImGuiIO& guiIO = ImGui::GetIO();
		// Update and Render additional Platform Windows
		if (guiIO.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}

		// Present buffer
		glfwSwapBuffers(m_Window);
	}

	bool App::Clean()
	{
		for (auto& layer : m_LayerStack)
		{
			layer->OnDetach();
		}

		// Destroy ImGui Backends
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		// Destroy GLFW Window
		glfwDestroyWindow(m_Window);

		// Stop Libraries
		glfwTerminate();

		return true;
	}
}