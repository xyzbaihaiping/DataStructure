#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<iostream>
using namespace std;

//int NumberOf1(int number)
//{
//	int count = 0;
//	while (number)
//	{
//		if (number % 10 == 1)
//		{
//			count++;
//		}
//		number /= 10;
//	}
//	return count;
//}
//int NumberOf1Between1AndN(int n)//初级算法（不理想）
//{
//	int count = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		count += NumberOf1(i);
//	}
//	return count;
//}

int powerBase10(unsigned int n)
{
	int result = 1;
	for(size_t i = 0; i < n; i++)
	{
		result *= 10;
	}

	return result;
}
int NumberOf1(const char *strN)
{
	if (strN == NULL || *strN < '0' || *strN > '9' || *strN == '\0')
		return 0;

	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));

	if (length == 1 && first == 0)
		return 0;
	if (length == 1 && first > 0)
		return 1;
	int numFirstDigit = 0;
	if (first > 1)
	{
		numFirstDigit = powerBase10(length-1);
	}
	else if (first == 1)
	{
		numFirstDigit = atoi(strN + 1) + 1;
	}
	int numOtherDigits = first*(length - 1)*powerBase10(length - 2);

	int numRecursive = NumberOf1(strN+1);

	return numFirstDigit + numOtherDigits + numRecursive;
}
int NumberOf1Between1AndN(int n)//初级算法（不理想）
{
	if (n < 0)
		return 0;
	char strN[50];
	_itoa(n,strN,10);
	return NumberOf1(strN);
}
int main()
{
	int n = 12;
	int count = NumberOf1Between1AndN(n);
	cout << count << endl;
	getchar();
	return 0;
}