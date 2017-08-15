#pragma once
#include "Application.h"
#include <vector>
struct Bunny;
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
	std::vector<Bunny>* m_bunnies;
	float m_timer;
	unsigned int m_roundNumber;
};
