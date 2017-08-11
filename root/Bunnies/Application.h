#pragma once
struct GLFWwindow;
class Application
{
public:
	Application();
	virtual ~Application();
	GLFWwindow * m_window;
	virtual bool draw() = 0;
	virtual bool startup() = 0;
	virtual bool update(float time) = 0;
	virtual bool shutdown() = 0;
	virtual bool createWindow(const char* title, int width, int height, bool fullscreen) ;
	void run(const char* title, int width, int height, bool fullscreen);
protected:
	bool m_gameover;
	
};



