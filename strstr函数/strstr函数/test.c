#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
char* my_strstr(const char *str1, const char *str2)
{
	char *pstr1 = str1;
	while (*pstr1)
	{
		str1=pstr1;
		while ( *str1== *str2)
		{   
			str1++;
			str2++;
			if (*str2 == '\0')
				return pstr1;
		}
		pstr1++;
	}
	return NULL;
}
int main()
{
	char str1[] = "abc";
	char str2[] = "bcd";
	char *ret = NULL;
	ret=my_strstr(str1, str2);
	if (ret != NULL)
	{
		printf("%s\n", ret);
	}
	else
		printf("not exist!\n");
	system("pause");
	return 0;


}