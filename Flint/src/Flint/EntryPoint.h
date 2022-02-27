#pragma once

#ifdef FT_PLATFORM_WINDOWS

extern Flint::Application* Flint::CreateApplication();

int main(int argc, char** argv)
{
	Flint::Log::Init();
	FT_CORE_WARN("Initialized Log!");
	FT_INFO("Info");

	printf("Flint Engine");
	auto app = Flint::CreateApplication();
	app->Run();
	delete app;
}

#endif