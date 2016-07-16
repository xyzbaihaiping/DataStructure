#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

enum Status
{
	Valid = 0,
	InValid = 1
};
int g_Status = Valid;

bool StrIsValid(const char *str)
{
	if (*str >= '0' && *str <= '9')
		return true;
	else
		return false;
}
int MyAtoi(const char *str)
{
	g_Status = InValid;
	if (str == NULL|| *str=='\0')//判断非法值，空指针和空字符串
		return -1;

	long long value = 0;
	int symbol = 1;
	const char *start = str;
	if (*start == '-')//确定符号
	{
		symbol = -1;
		start++;
	}
	else if (*start == '+')
	{
		start++;
	}

	while (*start != '\0')
	{
		if (*start >= '0' && *start <= '9')//判断合法字符(数字合法)
		{
			value = value * 10 + symbol*(*start - '0');
			if ((symbol == -1 && value <= INT_MIN) || (symbol== 1 && value >= INT_MAX))
				break;
		}
		else
		{
			break;
		}
		start++;
	}
	if (*start == '\0')
	{
		g_Status = Valid;
	}
	
	return (int)value;

}
int main()
{
	char *p = "+123456";
	int value=MyAtoi(p);
	cout << value << endl;
	getchar();
	return 0;
}