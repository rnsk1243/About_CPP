
#include<iostream>
#include<vector>
using namespace std;


vector<string> parse(const string& str, const char& ch) {
	string next;
	vector<string> result;

	for (string::const_iterator it = str.begin(); it != str.end(); it++)
	{
		if (*it == ch)
		{
			if (!next.empty())
			{
				result.push_back(next);
				next.clear();
			}
		}
		else
		{
			next += *it;
		}
	}
	if (!next.empty())
	result.push_back(next);
	return result;
}

int main(void)
{
	std::string blah = "this|is|th|e|ste|ing|we|will use|";
	std::vector<std::string> result = parse(blah, '|');

	for (size_t i = 0; i < result.size(); i++)
	{
		cout << result[i].c_str() << endl;
	}
	return 0;
}
