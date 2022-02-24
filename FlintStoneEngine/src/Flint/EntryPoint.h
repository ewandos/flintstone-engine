#pragma once

#ifdef FT_PLATFORM_WINDOWS

extern Flint::Application* Flint::CreateApplication();

int main(int argc, char** argv)
{
	printf("Flint Engine");
	auto app = Flint::CreateApplication();
	app->Run();
	delete app;
}

#endif