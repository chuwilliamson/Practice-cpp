#pragma once
#include "Application.h"
#include <vector>
class BunnyApp :
	public Application
{
public:
	BunnyApp();
	~BunnyApp();
	bool startup() override;
	bool update(float time) override;
	bool shutdown() override;
	bool createWindow(const char* title, int width, int height, bool fullscreen) override;
	bool draw() override;

	std::vector<std::string>* m_names;
	float m_timer;
	unsigned int m_roundNumber;
};
