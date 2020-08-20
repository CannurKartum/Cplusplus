#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <stdio.h>
#include <vector>

class CFileLastError
{
public:
	static bool bGetLastError() { return b_last_error; }

	CFileLastError();
	CFileLastError(std::string sFileName);

	void vOpenFile(const std::string sFileName);
	void vCloseFile();
	void vPrintLine(std::string sText);
	void vPrintManyLines(std::vector<std::string> sText);
	bool b_FileOpened();

	~CFileLastError();
private:
	static bool b_last_error;

	FILE* pf_file;
};


