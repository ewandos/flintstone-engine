#include <Flint.h>

class Sandbox : public Flint::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Flint::Application* Flint::CreateApplication()
{
	return new Sandbox();
}