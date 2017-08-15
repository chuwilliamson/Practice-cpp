#pragma once

class Bunny
{
public:
	Bunny();	
	~Bunny();
	char* m_name;	
	bool m_gender;
	void initialize(const char* name);
};

