#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char *my_strncat(char *dest, const char *src, int n)
{  
	char *ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (n--)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return ret;
}
int main()
{
	char arr[20] = "abcdefg";
	int n = 0;
	scanf("%d", &n);
	my_strncat(arr, arr, n);
	printf("%s", arr);
	system("pause");
	return 0;
}