#include "Application.h"

#include "Flint/Events/ApplicationEvent.h"
#include "Flint/Log.h"


namespace Flint {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		FT_TRACE(e);
		while (true);
	}
}