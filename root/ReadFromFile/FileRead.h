#pragma once
#include "stdio.h"
#include "errno.h"
class FileRead
{
public:
	FileRead();
	const char* Read(const char* filename);
	char* m_data;
private:
};


