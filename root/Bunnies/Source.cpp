#include "Bunny.h"
#include "BunnyApp.h"


//$(ProjectDir)inc; $(SolutionDir)dep\GLFW\include; $(SolutionDir)dep\imgui
int main()
{
	Application* app = new BunnyApp();
	app->run("Bunny game....", 1200, 800, false);
	return 0;
}
