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

int MoreThanHalfNum(int *a, int length)
{
	bool g_InputInvalid = false;
	if (a == NULL || length <= 0)
	{
		g_InputInvalid = true;
		return 0;
	}
	int middle = length >> 2;
	int start = 0;
	int end = length - 1;
	int index = 0;
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