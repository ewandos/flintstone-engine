#pragma once

#pragma comment (lib, "dwmapi.lib")
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Flint {
	class FLINT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// to be defined in client
	Application* CreateApplication();
}



