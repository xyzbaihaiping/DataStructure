#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int check_system()
//{
//	int i = 1;
//	char *p = (char *)&i;
//	if (*p == 1)
//	{
//		return 0;
//	}
//	else
//		return 1;
//}
int check_system()
{
	union
	{
		int i;
		char ch;

	}a = {1};
	if (a.ch == 1)
		return 0;
	else
		return 1;
}

int main()
{
	int  ret = 0;
	ret=check_system();
	if (ret == 0)
		printf("little\n");
	else
		printf("big");
	system("pause");
	return 0;
}