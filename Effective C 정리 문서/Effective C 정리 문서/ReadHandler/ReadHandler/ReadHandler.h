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
		cout << "�޽��� ����" << endl;
		size_t length = strlen(copyMS.message) + 1;
		message = new char[length];
		strcpy_s(message, length, copyMS.message);
		return *this;
	}
	MessageStruct(const MessageStruct& copyMS) :sendRecvSize(copyMS.sendRecvSize)
	{
		cout << "�޽��� ����" << endl;
		size_t length = strlen(copyMS.message) + 1;
		message = new char[length];
		strcpy_s(message, length, copyMS.message);
	}
	~MessageStruct()
	{
		cout << "�޽��� �Ҹ��� ȣ��" << endl;
		delete[] message;
		message = nullptr;
	}
};

class CReadHandler
{
public:
	CReadHandler();
	~CReadHandler();
	// ���ϸ�, ���� ��ġ?, ���ڸ, ��Ʈ��
	bool Search(const char* textFileName, bool isFullMatch, int count, ...)
	{
		ifstream inFile(textFileName);
		if (!inFile)
		{
			cout << "������ �����ϴ�." << endl;
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
					cout << "������ ��ġ���� �ʽ��ϴ�." << endl;
					return false;
				}
			}

			for (int i = 0; i < count; i++)
			{
				if (count > tempVec.size()) // tempVec ���� ����°� ����
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
	// ���ڿ���Ʈ��, �����±��ع���
	vector<string> Parse(const string& str, const char& ch);
	// ��Ʈ��id, ��Ʈ��password
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
	// ��Ʈ��id
	bool CheckOverlapID(const string& id)
	{
		if (Search("test.txt", false, 1, id))
		{
			// �ߺ��� 
			return false;
		}
		else
		{
			// ��밡��
			return true;
		}
	}
};

