#pragma once
#include<iostream>
#include<vector>
#include<stdarg.h>
#include<fstream>
using namespace std;

class CWriteHandler
{
public:
	CWriteHandler();
	~CWriteHandler();
	// 파일명, 몇개, 스트링
	bool write(const char* textFileName, int count, ...)
	{
		ofstream outFile(textFileName, ios::app);
		if (!outFile)
		{
			cout << "파일이 없습니다." << endl;
			return false;
		}
		va_list Marker;
		va_start(Marker, count);
		
		for (int i = 0; i < count; i++)
		{
			outFile << va_arg(Marker, string).c_str() << '|';
		}
		outFile << '\n';
		outFile.close();
		va_end(Marker);
		return true;
	}



};

