#include "BunnyApp.h"
#include "stdio.h"
#include "gl_core_4_4.h"

#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"



BunnyApp::BunnyApp()
{
}


BunnyApp::~BunnyApp()
{
}

bool BunnyApp::startup()
{
	m_timer = 2.0f;
	m_roundNumber = 0;
	
	return true;
}

bool BunnyApp::update(float deltaTime)
{	
	m_timer -= deltaTime;
	
	if (m_timer <= 0)
	{
		m_roundNumber+=1;
		m_timer = 2.0f;
	}
	
	ImGui_ImplGlfwGL3_NewFrame();
	// imgui example
	ImGui::Begin("Rendering Options 1");
	
	ImGui::Text("Quit menu");
	
	
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
