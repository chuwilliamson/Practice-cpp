#include "FileRead.h"
#include <cstring>

FileRead::FileRead() : m_data(nullptr)
{
	
}

const char* FileRead::Read(const char* filename)
{
	FILE* fp;
	errno_t success = fopen_s(&fp, "haircuts.txt", "rb");
	if (success < 0)
		perror("no file");
	fseek(fp, 0, SEEK_END);
	size_t size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	m_data = new char[size + 1];

	fread_s(m_data, size, sizeof(char), size, fp);

	m_data[size + 1] = '\0';	
	fclose(fp);
	const char * source = m_data;
	return source;
}


