#include "BunnyApp.h"
#include "stdio.h"
#include "gl_core_4_4.h"

#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"
#include "FileRead.h"
#include "Bunny.h"


BunnyApp::BunnyApp() : m_bunnies(nullptr), m_timer(0), m_roundNumber(0)
{
}


BunnyApp::~BunnyApp()
{
}

bool BunnyApp::startup()
{
	m_bunnies = new std::vector<Bunny>[40];
	m_timer = 2.0f;
	m_roundNumber = 0;
	FILE* fp;
	fopen_s(&fp, "names.bunnies", "r");
	char line[25];

	while (fgets(line, 25, fp) != nullptr)
	{
		size_t last = strlen(line) - 1;
		line[last] = '\0';
		char name[25];
		strcpy_s(name, line);
		Bunny *b = new Bunny();
		b->initialize(name);
		m_bunnies->push_back(*b);
	}

	return true;
}

bool BunnyApp::update(float deltaTime)
{
	m_timer -= deltaTime;

	if (m_timer <= 0)
	{
		m_roundNumber += 1;
		m_timer = 2.0f;
	}

	ImGui_ImplGlfwGL3_NewFrame();
	// imgui example
	ImGui::Begin("Rendering Options 1");

	ImGui::Text("Quit menu");
	int count = 0;
	for (auto& iter : *m_bunnies)
	{		
		if (count < 20)
			ImGui::Text("%i: name = %s => female", count, iter.m_name);
		else
			ImGui::Text("%i: name = %s => male", count, iter.m_name);
		count++;
	}

	ImGui::Text("Round number is %i", m_roundNumber);
	ImGui::Checkbox("quit?", &m_gameover);
	ImGui::End();


	return true;
}

bool BunnyApp::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	ImGui::Render();
	return true;
}

bool BunnyApp::shutdown()
{
	return true;
}

bool BunnyApp::createWindow(const char* title, int width, int height, bool fullscreen)
{
	Application::createWindow(title, width, height, fullscreen);

	ImGui_ImplGlfwGL3_Init(m_window, true);
	ImGuiIO& io = ImGui::GetIO();
	io.DisplaySize.x = width;
	io.DisplaySize.y = height;

	return true;
}
