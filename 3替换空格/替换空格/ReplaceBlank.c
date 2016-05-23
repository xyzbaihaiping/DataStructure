#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

void ReplaceBlank(char *str,int length)
{
	assert(str);
	char *pstr = str;
	int blank = 0;
	int newlength = 0;

	while (*pstr !='\0')
	{
		if (*pstr == ' ')
		{
			blank++;
		}
		pstr++;
	}
	newlength = 2 * blank + strlen(str);

	if (newlength > length)
		return;
	while (pstr != str)
	{
		if (*pstr == ' ')
		{
			str[newlength] = '%';
			str[--newlength] = '0';
			str[--newlength] = '2';
		}
		else
		{
			str[newlength] = *pstr;
		}
		newlength--;
		pstr--;
	}
}
int main()
{
	char str[20] = "we are happy";
	ReplaceBlank(str,20);
	printf("%s", str);
	system("pause");
	return 0;
}