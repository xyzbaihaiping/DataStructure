#include<iostream>
using namespace std;
void SetNumber(char *number, int index,int n,int &count)
{
	
	if (index == n)
	{
		char *num = number;
		while(*num == '0'&& num != number+n-1)
			num++;
		count++;
		cout << num <<endl;
		return;
	}
	int i = 0;
	for ( i=0; i <= 9; i++)
	{
		number[index] = i + '0';
		SetNumber(number, index + 1,n,count);
	}
}
void Print1ToMaxOfNDigits(int n)
{
	int count = 0;
	if (n <= 0)
		return;
	char *number = new char[n + 1];
	memset(number, '\0', sizeof(char)*(n + 1));

	SetNumber(number, 0,n,count);
	cout <<endl<< count << endl;
}

int main()
{
	int n = 3;
	Print1ToMaxOfNDigits(n);
	getchar();
	return 0;
}