#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//
//using namespace std;
//
//class String
//{
//public:
//	/*String()
//		:_str(new char[1])
//	{
//		*_str = '\0';
//	}*/
//	String(char *str="")
//		:
//		:_str(new char[strlen(str)+1])
//	{
//		strcpy(_str, str);
//	}
//	String(const String& str)
//	:_str(new char[strlen(str._str) + 1])
//	{	
//		strcpy(_str, str._str);
//	}
//	String& operator=(const String& str)
//	{
//		if (this != &str)
//		{
//			delete[] _str;
//			_str = new char[strlen(str._str) + 1];
//			strcpy(_str, str._str);
//		}
//		return *this;
//	}
//	~String()
//	{
//		delete[] _str;
//		_str = NULL;
//	}
//   friend ostream& operator<<(ostream& output, const String& str)
//   {
//	  output << str._str;
//	  return output;
//   }
//private:
//	char *_str;
//};

#include<iostream>
using namespace std;
#define DEFAULT_CAPACITY 3
class String
{
public:
	String(char *str = "")
		:_str(new char[strlen(str) + 1 + DEFAULT_CAPACITY])
		, _size(strlen(str))
		, _capacity(_size +1+DEFAULT_CAPACITY)
	{
		strcpy(_str, str);
	}
	~String()
	{
		if (_str != NULL)
		{

			delete[] _str;
			_str = NULL;
			
		}
	}
	String(const String& str)
		:_str(NULL)
		, _size(str._size)
		, _capacity(str._capacity)
	{
		String tmp(str._str);
		swap(_str, tmp._str);
	}
	/*String& operator=(const String& str)
	{
		if (this != &str)
		{
			String tmp(str);
			swap(_str, tmp._str);
		}
		return *this;
	}*/
	String& operator=(String str)
	{
		_size = str._size;
		_capacity = str._capacity;
		swap(_str, str._str);
		return *this;
	}
	bool operator==(const String& str);
	bool operator>(const String& str);
	bool operator<(const String& str);
	void CheckCapacity(int size);
	void insert(int pos, char ch);
	void insert(int pos, char *str);
	void insert(int pos, const String& str);
	void PushBack(int ch);
	friend ostream& operator<<(ostream& output, const String& str);
private:
	char *_str;
	int _size;
	int _capacity;
};


void String::PushBack(int ch)
{
	insert(_size, ch);
}
int MyStrcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;

	    str1++;
		str2++;
	}
	return *str1 - *str2;
}
bool String::operator==(const String& str)
{
	if (MyStrcmp(_str, str._str) == 0)
		return true;
	else
		return false;
}
bool String::operator>(const String& str)
{
	if (MyStrcmp(_str, str._str) > 0)
		return true;
	else
		return false;
}
bool String::operator<(const String& str)
{
	if (MyStrcmp(_str, str._str) > 0)
		return true;
	else
		return false;
}
void String::CheckCapacity(int size)
{
	if (_capacity < size)
	{
		char *str = new char[size + DEFAULT_CAPACITY];
		strcpy(str, _str);
		delete[] _str;
		_str = str;
		_capacity = size + DEFAULT_CAPACITY;
	}
}
void String::insert(int pos, char ch)
{
	CheckCapacity(_size + 2);
	int end = _size;
	while (end >= pos)
	{
		_str[end + 1] = _str[end];
		end--;
	}
	_str[pos] = ch;
	_size += 1;
}
void String::insert(int pos, char *str)
{

	int len = strlen(str);
	CheckCapacity(_size + len+1);
	int end = _size;

	while (end >= pos)
	{
		_str[end +len] = _str[end];
		end--;
	}
	while (*str)
	{
		_str[pos++] = *str++;
	}
	_size = _size + len;
}
void String::insert(int pos, const String& str)
{
	insert(pos, str._str);
}
ostream& operator<<(ostream& output, const String& str)
{
	output << str._str;
	return output;
}
int main()
{
	String str = "qqqqq";
		String str1("ppp");
	String str2;
	//str.insert(5, str1);
	str.PushBack('t');
	cout << str << endl;
	
	getchar();
	return 0;
}
