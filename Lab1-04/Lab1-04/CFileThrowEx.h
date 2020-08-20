#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <stdio.h>
#include <vector>
#define GLOBAL_ERROR 1
//const int GLOBAL_ERROR = 1;

class CFileThrowEx
{
public:
	CFileThrowEx();
	CFileThrowEx(std::string sFileName);

	void vOpenFile(const std::string sFileName);
	void vCloseFile();
	void vPrintLine(std::string sText);
	void vPrintManyLines(std::vector<std::string> sText);
	bool b_FileOpened();

	~CFileThrowEx();
private:
	FILE* pf_file;
};




