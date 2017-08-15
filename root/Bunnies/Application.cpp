#include "Application.h"
#include "gl_core_4_4.h"
#include "glfw3.h"
#include <cassert>



Application::Application() : m_window(nullptr), m_gameover(false)
{
}


Application::~Application()
{
}

bool Application::draw()
{
	return false;
}

bool Application::createWindow(const char* title, int width, int height, bool fullscreen)
{
	if (glfwInit() == GL_FALSE)
		return false;

	GLFWmonitor* monitor = (fullscreen) ? glfwGetPrimaryMonitor() : nullptr;
	m_window = glfwCreateWindow(width, height, title, monitor, nullptr);

	assert(m_window != nullptr);

	glfwMakeContextCurrent(m_window);

	// Close window on pressing ESC
	glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
	});

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return false;
	}


	glClearColor(0.5f, .05f, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

void Application::run(const char* title, int width, int height, bool fullscreen)
{
	if (createWindow(title, width, height, fullscreen) && startup())
	{
		double prevTime = glfwGetTime();
		double currTime = 0;
		double deltaTime = 0;
		
		while (!m_gameover)
		{
			currTime = glfwGetTime();
			deltaTime = currTime - prevTime;
			prevTime = currTime;
			glfwPollEvents();
			update(deltaTime);
			draw();
			glfwSwapBuffers(m_window);
			m_gameover = m_gameover || glfwWindowShouldClose(m_window) == GLFW_TRUE;
		}
	}
}
