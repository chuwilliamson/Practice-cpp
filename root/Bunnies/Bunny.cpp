#include "Bunny.h"
#include <string>
Bunny::Bunny() : m_gender(0), m_name("no name")
{
}



Bunny::~Bunny()
{
}

void Bunny::initialize(const char * name)
{	
	size_t size = strlen(name);
	m_name = new char[size];
	for (int i = 0; i < size; ++i)
		m_name[i] = name[i];
	m_name[size + 1] = '\0';
}

