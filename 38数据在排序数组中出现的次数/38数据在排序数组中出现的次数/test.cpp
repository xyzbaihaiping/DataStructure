#include<iostream>
using namespace std;


int GetFirstK(int *a, int n,int k,int start,int end)
{
	if (start > end)
		return -1;
	int mid = end - (end - start) / 2;
	int midData = a[mid];

	if (midData == k)
	{
		if (mid > 0 && a[mid - 1] != k || mid == 0)
			return mid;
		else
			end = mid-1;
	}
	else if (a[mid] < k)
	{
		start = mid + 1;
	}
	else
		end = mid - 1;

	return GetFirstK(a,n,k,start,end);
}

int GetLastK(int *a, int n, int k, int start, int end)
{
	if (start > end)
		return -1;
	int mid = end - (end - start) / 2;
	int midData = a[mid];

	if (midData == k)
	{
		if (mid <n-1 && a[mid + 1] != k || mid == n-1)
			return mid;
		else
			start= mid +1;
	}
	else if (a[mid] < k)
	{
		start = mid + 1;
	}
	else
		end = mid - 1;

	return GetLastK(a, n, k, start, end);
}
int NumberOfK(int *a,int n,int k)
{
	if (a == NULL || n<0)
		return 0;
	int count = 0;
	int first = GetFirstK(a,n,k,0,n-1);
	int last = GetLastK(a,n,k,0,n-1);
	if (first > -1 && last > -1)
		count = last - first + 1;
	return count;
}
int main()
{
	int a[] = {1,2,5,5,5,5,6,6,8,9,10,12};
	cout << NumberOfK(a,12,5) << endl;
	getchar();
	return 0;
}