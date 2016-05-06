#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//int my_strcmp(const char *str1, const char *str2)
//{
//	assert(str1);
//	assert(str2);
//	while (*str1 == *str2)
//	{
//		if (*str1=='\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}

int MyStrcmp(const char *str1, const char *str2)
{
	assert(str1);
	assert(str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
int main()
{
	char str1[] = "abcd";
	char str2[] = "abcd";

	int ret = my_strcmp(str1, str2);

	if ( ret== 0)
		printf("str1==str2");
	else if (ret < 0)
		printf("str1<str2");
	else
		printf("str1>str2");

	system("pause");
	return 0;

}