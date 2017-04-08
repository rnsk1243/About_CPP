#pragma once
#include<iostream>
#include<vector>
#include<stdarg.h>
#include<fstream>
using namespace std;
const int Buff_Size = 256;

//typedef vector<IDandPassWord*> ParsedIDVector;
//typedef ParsedIDVector::iterator ParsedIt;

struct MessageStruct
{
	char* message;
	size_t sendRecvSize;
	MessageStruct() :message(new char[Buff_Size]) {}
	MessageStruct& operator=(const MessageStruct& copyMS)
	{
		if (this == &copyMS)
			return *this;
		cout << "메시지 복사" << endl;
		size_t length = strlen(copyMS.message) + 1;
		message = new char[length];
		strcpy_s(message, length, copyMS.message);
		return *this;
	}
	MessageStruct(const MessageStruct& copyMS) :sendRecvSize(copyMS.sendRecvSize)
	{
		cout << "메시지 복사" << endl;
		size_t length = strlen(copyMS.message) + 1;
		message = new char[length];
		strcpy_s(message, length, copyMS.message);
	}
	~MessageStruct()
	{
		cout << "메시지 소멸자 호출" << endl;
		delete[] message;
		message = nullptr;
	}
};

class CReadHandler
{
public:
	CReadHandler();
	~CReadHandler();
	// 파일명, 전부 일치?, 인자몇개, 스트링
	bool Search(const char* textFileName, bool isFullMatch, int count, ...)
	{
		ifstream inFile(textFileName);
		if (!inFile)
		{
			cout << "파일이 없습니다." << endl;
			return false;
		}
		va_list Marker;
		va_start(Marker, count);

		vector<string> searchTarget;
		for (int i = 0; i < count; i++)
		{
			searchTarget.push_back(va_arg(Marker, string));
		}

		int sameAmount = 0;
		while (!inFile.eof())
		{
			sameAmount = 0;
			char temp[Buff_Size];
			inFile.getline(temp, Buff_Size);
			string tempString = temp;
			vector<string> tempVec = Parse(tempString, '|');

			if (isFullMatch)
			{
				if (searchTarget.size() != tempVec.size())
				{
					cout << "갯수가 일치하지 않습니다." << endl;
					return false;
				}
			}

			for (int i = 0; i < count; i++)
			{
				if (count > tempVec.size()) // tempVec 범위 벗어나는것 방지
					break;
				int compareResult = searchTarget[i].compare(tempVec[i]);
				if (0 == compareResult)
				{
					sameAmount++;
				}
				else
				{
					break;
				}
			}
			if (sameAmount == count)
			{
				break;
			}
		}
		va_end(Marker);
		inFile.close();
		if (sameAmount == count)
		{
			return true;
		}
		return false;
	}
	// 문자열스트링, 나누는기준문자
	vector<string> Parse(const string& str, const char& ch);
	// 스트링id, 스트링password
	bool CheckIDandPassWord(const string& id, const string& password)
	{
		if (Search("test.txt", false, 2, id, password))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// 스트링id
	bool CheckOverlapID(const string& id)
	{
		if (Search("test.txt", false, 1, id))
		{
			// 중복됨 
			return false;
		}
		else
		{
			// 사용가능
			return true;
		}
	}
};

