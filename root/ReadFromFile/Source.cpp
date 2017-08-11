
#include "FileRead.h"


int main()
{
	FileRead * fr = new FileRead();
	const char* code = 	fr->Read("haircuts.txt");
	const char* code2 = fr->m_data;	
	return 0;
}
