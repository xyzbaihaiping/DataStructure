
#include<iostream>

using namespace std;

int NumberOf1(int value)//最优解法，有几个1循环几次
{
	int count = 0;
	while (value)
	{
		count++;
		value = value & (value - 1);
	}
	return count;
}
int NumberOf1(int value)//循环32次
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (value & flag)
			count++;
		flag = flag<<1;
	}
	return count;
}
int main()
{
	int value=-1;
	int count=NumberOf1(value);
	cout << count << endl;
	getchar();
	return 0;
}