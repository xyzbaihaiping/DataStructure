#include<iostream>
#include<assert.h>

using namespace std;

int InoderMin(int *a, int left, int right)
{
	assert(a);
	while (left < right)
	{
		if ((left + 1) <= right && a[left] > a[left + 1])
			return a[left + 1];
		else
			left++;
	}
	return a[left];
}
int ArrayMin(int *a, int length)
{
	assert(a || length<=0);
	int left = 0;
	int right = length-1;
	int mid=left;

	while (a[left] >= a[right])
	{
		if ((right - left) == 1)
		{
			mid = right;
			break;
		}
		mid = (left + right) / 2;

		if (a[left] == a[right] && a[left] == a[mid])
			return InoderMin(a,left,right);
		if (a[mid] >= a[left])
			left = mid;
		else if (a[mid] <= a[right])
			right=mid;
	}
	return a[mid];
}
int main()
{
	int arr[] = { 3, 4, 5, 1, 2 };
	int arr1[] = { 1, 1, 0, 1, 1, 1 };
	int arr2[] = { 1, 1, 1, 1, 0, 1 };
	int arr3[] = { 1, 1, 1, 1, 1, 1 };
	int size = sizeof(arr3) / sizeof(arr3[0]);
	int ret=ArrayMin(arr1,size);
	cout << ret << endl;
	getchar();
	return 0;
}