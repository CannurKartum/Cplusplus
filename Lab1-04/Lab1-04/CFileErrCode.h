#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include <stdio.h>
#include <vector>

class CFileErrCode
{
public:
	CFileErrCode();
	CFileErrCode(std::string sFileName, bool& failedFlag);

	bool vOpenFile(const std::string sFileName);
	bool vCloseFile();
	bool vPrintLine(std::string sText);
	bool vPrintManyLines(std::vector<std::string> sText);
	bool b_FileOpened();

	~CFileErrCode();
private:
	FILE* pf_file;
};