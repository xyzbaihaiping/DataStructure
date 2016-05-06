#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//int my_strlen(const char *str)
//{
//	assert(str);
//	const char *p = str;
//	while (*p++)
//	{
//		;
//	}
//	return p - str - 1;
//}
//int my_strlen(const char *str)
//{
//	assert(str);
//	int count = 0;
//	while (*str++)
//	{
//		count++;
//		
//	}
//	return count;
//}
int my_strlen(const char *str)
{
	assert(str);
	if (*str == '\0')
		return 0;
	else
	    return 1 + my_strlen(str+1);
}
int main()
{
	char str[] = "abc";
	int ret = my_strlen(str);
	printf("%d ", ret);
	system("pause");
	return 0;
}