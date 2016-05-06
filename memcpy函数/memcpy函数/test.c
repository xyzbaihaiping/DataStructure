#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
void* my_memcpy(void *dest, const void *src,int size)
{
	assert(dest);
	assert(src);

	void *ret = dest;
	char *p1 = (char *)dest;
	char *p2 = (char *)src;

	while (size--)
	{
		*p1++ = *p2++;
	}
	return ret;
}
int main()
{
	int arr1[10] = {0};
	int arr[10] = { 0,1,2,3 };
    int i = 0;
	
	int *ret = my_memcpy(arr1, arr, 16);
	
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ret[i]);
	}
	system("pause");
	return 0;
}