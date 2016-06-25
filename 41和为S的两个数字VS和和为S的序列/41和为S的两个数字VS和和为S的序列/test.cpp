#include<iostream>
using namespace std;

bool  FindNumsWithSum(int *a, int length, int sum, int *num1, int *num2)
{
	if (a == NULL || length <= 0)
		return false;
	int left = 0;
	int right = length - 1;
	while (left < right)
	{
		int ret = a[left] + a[right];
		if (ret == sum)
		{
			*num1 = a[left];
			*num2 = a[right];
			return true;
		}
		else if (ret > sum)
			right--;
		else
			left++;
	}
	return false;
}
void PrintSequence(int small, int big)
{
	while (small <= big)
	{
		cout << small << " ";
		small++;
	}

	cout << endl;
}
void  FindSequence(int sum)
{
	if (sum < 3)
		return;
	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int cursum = small + big;
	while (small < middle)
	{
		if (cursum == sum)
		{
			PrintSequence(small, big);
			small++;
			cursum -= small - 1;
		}
		else if (cursum < sum)
		{
			big++;
			cursum += big;
		}
		else
		{
			cursum -= small;
			small++;	
		}
	}

}
int main()
{
	int a[] = {1,2,4,7,11,15};
	int num1, num2;
	int size = sizeof(a) / sizeof(a[0]);
	if (FindNumsWithSum(a, size, 19, &num1, &num2))
		cout << num1 << " " << num2 << endl;

	FindSequence(100);
	getchar();
	return 0;
}