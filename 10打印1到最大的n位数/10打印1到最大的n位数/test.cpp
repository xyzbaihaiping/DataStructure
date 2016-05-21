#include<iostream>
using namespace std;

//法一：递归法
//void SetNumber(char *number, int index,int n,int &count)
//{
//	
//	if (index == n)
//	{
//		char *num = number;
//		while(*num == '0')
//			num++;
//		count++;
//		cout << num <<endl;
//		return;
//	}
//	int i = 0;
//	for ( i=0; i <= 9; i++)
//	{
//		number[index] = i + '0';
//		SetNumber(number, index + 1,n,count);
//	}
//}
//void Print1ToMaxOfNDigits(int n)
//{
//	int count = 0;
//	if (n <= 0)
//		return;
//	char *number = new char[n + 1];
//
//	number[n]='\0';
//
//	SetNumber(number, 0,n,count);
//	cout <<endl<< count << endl;
//	delete[] number;
//}

//法二：非递归
bool InCrement(char* number)
{
	bool IsOverFlow = false;
	int TakeOver = 0;
	
	int length = strlen(number);
	
	for (int i = length - 1; i >= 0; i--)
	{
		int sum = number[i] + TakeOver - '0';
		if (i == length - 1)
			sum++;
		if (sum >= 10)
		{
			if (i == 0)
			{
				IsOverFlow = true;
			}
			else
			{
				sum -= 10;
				number[i] = sum + '0';
				TakeOver = 1;
			}

		}
		else
		{
			number[i] = sum + '0';
			TakeOver = 0;
		}
		
	}
	return IsOverFlow;
}
void PrintNumber(char *number)
{
	char *p = number;
	while (*p == '0')
	{
		p++;
	}
	cout << p << endl;
}
void Print1ToMaxOfNDigits(int n)
{
	int count = 0;
	if (n <= 0)
		return;
	char *number = new char[n + 1];
	number[n] = '\0';
	memset(number, '0', sizeof(char)*n);
	while (!InCrement(number))
	{
		PrintNumber(number);
	}
	cout <<endl<< count << endl;
	delete[] number;
}


int main()
{
	int n = 2;
	Print1ToMaxOfNDigits(n);
	getchar();
	return 0;
}