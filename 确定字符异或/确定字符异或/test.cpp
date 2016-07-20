#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

	bool checkDifferent(string iniString) {
		// write code here
		const char *p = iniString.c_str();
		bool ret[256] = { false };
		while (*p != '\0')
		{
			if (ret[*p] == false)
				ret[*p] = true;
			else
				return false;
			p++;
		}
		return true;
	}

int main()
{
	string str = "abcdef";
	cout << checkDifferent(str) << endl;
	getchar();
	return 0;
}