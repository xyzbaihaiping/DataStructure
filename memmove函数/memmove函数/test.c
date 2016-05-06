#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
void* my_memmove(void *dest, void const *src, int count)
{
	assert(dest);
	assert(src);

	void *ret = dest;
	char *p1 = (char *)dest;
	char *p2 = (char *)src;

	if (p1 > p2  &&  p1 < p2 + count)
	{
		while (count--)
		{
			*(p1 + count) = *(p2 + count);
		}
	}
	else
	   while (count--)
	{
		*p1++ = *p2++;
	}

	return ret;
}
int main()
{
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int i = 0;
 
    my_memmove(arr + 5, arr + 2, 16);
	
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}




