#pragma once

#pragma comment (lib, "dwmapi.lib")
#include "Core.h"
#include "Events/Event.h"
#include "Flint/Events/ApplicationEvent.h"
#include "Window.h"

namespace Flint {
	class FLINT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// to be defined in client
	Application* CreateApplication();
}



