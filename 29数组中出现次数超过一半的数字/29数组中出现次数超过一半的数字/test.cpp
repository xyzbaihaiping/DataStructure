#include<iostream>
#include<assert.h>
using namespace std;

bool g_InputInvalid = false;
bool CheckMoreThanHalf(int *a, int length,int number)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (a[i] == number)
			count++;
	}
	if (count * 2 <= length)
	{
		g_InputInvalid = true;
		return false;
	}
	return true;
}
int Partition(int *a, int length, int start, int end)
{
	assert(a != NULL || length > 0 || start >=0 || end < length);
	int prev = start - 1;
	for (int i = start; i < end; i++)
	{
		if (a[i] < a[end])
		{
			prev++;
			if (prev != i)
				swap(a[prev], a[i]);
		}

	}
	swap(a[++prev],a[end]);
	return prev;
}
int MoreThanHalfNum(int *a, int length)//法一，基于partition函数的O(N)算法，排列数组以数组中间的值为基准左边都<=该值，右边>=该值
{
	bool g_InputInvalid = false;
	if (a == NULL || length <= 0)
	{
		g_InputInvalid = true;
		return 0;
	}
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(a, length, start, end);

	while (index!=middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = Partition(a, length, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(a, length, start, end);
		}
	}
	int result = a[index];
	if (!CheckMoreThanHalf(a, length, result))
		result = 0;
	return a[index];

}
//int MoreThanHalfNum(int *a,int length)//法二、计数法
//{
//
//	bool g_InputInvalid = false;
//	if (a == NULL || length <= 0)
//	{
//		g_InputInvalid = true;
//		return 0;
//	}
//	int value = 0;
//	int count = 0;
//	for (int i = 1; i < length; i++)
//	{
//		if (count == 0)
//		{
//			value = a[i];
//			count = 1;
//		}
//		if (a[i] == value)
//			count++;
//		else
//			count--;
//	}
//	if(!CheckMoreThanHalf(a, length, value))
//	    value = 0;
//	return value;
//}
int main()
{
	int a[] = {1,5,5};
	int size = sizeof(a) / sizeof(a[0]);
	int ret=MoreThanHalfNum(a, size);
	cout << ret << endl;
	getchar();
	return 0;
}