#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
using namespace std;

class String
{
public:
	String(char *str = "")
		:_str(new char[strlen(str) + 5])
	{
		*(int *)_str = 1;
		_str += 4;
		strcpy(_str, str);
	}

	~String()
	{
		if (_str != NULL)
		{
		    _Release();
		}
	}
	String(const String& str)
	{
		_str = str._str;
		++_GetRefCount();
	}
	String& operator=(const String& str)
	{
		if (this != &str)
		{
			_Release();
			_str = str._str;
			++_GetRefCount();
		}
		return *this;
	}
	char& operator[](int index)//写时拷贝
	{
	
		if (_GetRefCount()>1)//当引用次数大于1时新开辟内存空间
		{
			--_GetRefCount();//原来得空间引用计数器减1
			char *str = new char[strlen(_str) + 5];
			strcpy(str+4, _str);
			_str = str+4;
			_GetRefCount()++;
		}
		return _str[index];
	}
	friend ostream& operator<<(ostream& output, const String& str)
	{
		output << str._str;
		return output;
	}

	
private:
	int& _GetRefCount()
	{
		return *(int *)(_str - 4);
	}
	void _Release()
	{
		if (--_GetRefCount() == 0)
		{
			delete[] (_str-4);
		}
	}
private:
	char *_str;
};

int main()
{
	String str1("aaaaaaaaaaaaaaaaaaaaaaa");

	String str3("xyzsd");
	String str4(str3);

	/*cout << str2<<endl;*/
	str1[4] = 'f';
	cout << str1<<endl;
	
	system("pause");
	return 0;
}


