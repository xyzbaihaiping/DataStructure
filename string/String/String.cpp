#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class String
{
public:
	String(char *str=NULL)
	{
		if (str == NULL)
		{
			_str = new char[1];
			*_str = '\0';
		}
		else
		{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		}
		
	}
	String(const String& str)
	{
		_str = new char[strlen(str._str) + 1];
		strcpy(_str, str._str);
	}
	String& operator=(const String& str)
	{
		if (this != &str)
		{
			delete[] _str;
			_str = new char[strlen(str._str) + 1];
			strcpy(_str, str._str);
		}
		return *this;
	}
	friend ostream& operator<<(ostream& output, const String& str)
	{
		output << str._str;
		return output;
	}
	~String()
	{
		delete[] _str;
		_str = NULL;
	}
	private:
		char *_str;
};
int main()
{
	String str;
	String str2("hello");
	String str3 = str2;
	cout << str<<endl;
	cout << str2<<endl;
	cout << str3 << endl;

	getchar();
	return 0;
}