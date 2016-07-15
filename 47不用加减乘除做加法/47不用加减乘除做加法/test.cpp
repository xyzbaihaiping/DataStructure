#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

int Add(int left, int right)
{
	int sum = 0;
	int carry = 0;
	do
	{
		sum = left^right;
		carry = (left & right) << 1;
		left=sum;
		right = carry;
	} while (carry != 0);

	return left;
}


int main()
{
	cout << Add(100, 250) << endl;
	getchar();
	return 0;
}

