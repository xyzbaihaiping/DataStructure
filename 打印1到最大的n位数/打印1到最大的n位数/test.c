#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void Print_number(char *p)
//{
//	int flag = 1;
//	int nlength = strlen(p);
//	int i = 0;
//	for (i = 0; i < nlength; i++)
//	{
//		if (flag==1 && p[i]!='0')
//			flag = 0;
//		if (flag == 0)
//			printf("%c", p[i]);
//	}
//	printf("\n");
//}
//int Increament(char *p)
//{
//	int nlength = strlen(p);
//	int number = 0;
//	int overflow = 0;
//	int sum = 0;
//	int i = 0;
//	for (i = nlength - 1; i >= 0; i--)
//	{
//		sum = p[i] - '0' + overflow;
//		if (i == nlength - 1)
//			sum++;
//		if (sum>=10)
//		{
//			if (i==0)
//			{
//				return 0;
//			}
//			else
//			{
//				sum = 0;
//				overflow = 1;
//				p[i] = '0' + sum;
//			}
//		}
//		else
//		{
//			p[i] = '0' + sum;
//			return 1;
//		}
//	}
//
//}
//void print_value(int n)
//{
//	char *p = (char *)malloc((n + 1)*sizeof(char));
//	int i = 0;
//	int number = 0;
//	while (i < n)
//	{
//		p[i] = '0';
//		i++;
//	}
//	p[n] = '\0';
//	while (Increament(p))
//	{
//		Print_number(p);
//	}
//	free(p);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print_value(n);
//	system("pause");
//	return 0;
//}
void Print_number(char *p)
{
	int flag = 1;
	int nlength = strlen(p);
	int i = 0;
	for (i = 0; i < nlength; i++)
	{
		if (flag==1 && p[i]!='0')
			flag = 0;
		if (flag == 0)
			printf("%c", p[i]);
	}
	printf("\n");
}
void increament(char *p, int n, int index)
{
	int i = 0;
	if (index == n-1)
	{
		Print_number(p);
		return;
	}
	for (i = 0; i < 10; i++)
	{
		p[index + 1] = i + '0';
		increament(p, n, index + 1);
	}
}
void print_value(int n)
{
	if (n <= 0)
		return;
	char *p = (char *)malloc((n + 1)*sizeof(char));
	int i = 0;
	p[n] = '\0';
	for (i = 0; i < 10; i++)
	{
		p[0] = i + '0';
		increament(p, n, 0);
	}
	free(p);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	print_value(n);
	system("pause");
	return 0;
}