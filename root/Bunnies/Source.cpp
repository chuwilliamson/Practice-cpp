#include "Bunny.h"
#include "BunnyApp.h"

//$(ProjectDir)inc; $(SolutionDir)dep\GLFW\include; $(SolutionDir)dep\imgui
/*
auto         => will copy the vector, but we wanted a reference
auto&        => will only bind to modifiable lvalues
const auto&  => will bind to anything but make it const, giving us const_iterator
const auto&& => will bind only to rvalues
*/
typedef void(*Listener)(const char*);

int main()
{		
	Bunny* rabbit = new Bunny();
	
	rabbit->initialize("ziggity");	

	Application* app = new BunnyApp();
	app->run("Bunny game....", 1200, 800, false);
	return 0;
}
