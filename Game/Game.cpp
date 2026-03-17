#include"../Engine/Application.h"
int main()
{
	using namespace Engine;
	Application app;
	if (app.Init()) 
	{
		while (app.IsRunning())
		{
			app.Update();
		}
	}
}
