#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char *my_strcat(char *dest, const char *src)
{
	assert(dest);
	assert(src);
	char *ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char str1[] = "abcd";
	char *p = "efgh";
	char *ret = my_strcat(str1,p);
	printf("%s", ret);
	system("pause");
	return 0;
}