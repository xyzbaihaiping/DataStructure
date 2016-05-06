#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
char *my_strcpy(char *dst, const char *src)
{
	assert(dst);
	assert(src);
	char *ret = dst;
	while (*dst++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char dst[] = "adsd";
	char src[] = "abcd";
	char *ret = NULL;
	ret=my_strcpy(dst, src);
	printf("%s", ret);
	system("pause");
	return 0;
}


