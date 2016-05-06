#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

char *strrstr(char const *dst, char const *src)
{
	assert(dst);
	assert(src);

	char *ret = NULL;
	char *tmp = NULL;

	while ((ret = strstr(dst, src)) != NULL)
	{
		tmp = ret;
		ret += strlen(src);
		dst = ret;
	}
	return tmp;
}
int main()
{
	char dst[] = "abdeacabdf";
	char src[] = "abd";
	char *ret = NULL;
	ret=strrstr(dst, src);
	if (ret != NULL)
		printf("%s\n", ret);
	else
	{
		printf("not exist");
	}
	system("pause");
	return 0;
}