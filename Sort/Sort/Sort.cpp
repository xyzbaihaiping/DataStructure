#include<assert.h>
#include<iostream>
#include<string.h>
using namespace std;
#include"Sort.h"
void InsertSort(int *a, int n)//插入排序
{
	assert(a || n > 0);

	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (a[end] > tmp && end >= 0)//若前一个元素比当前元素值大，那么就将前一个元素向后移
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = tmp;//将当前元素值放进比它小的元素的后面
	}

}
void ShellSort(int *a, int n)//希尔排序 同时对多个组进行排序
{
	assert(a || n > 0);
	int gap = n;
	while (gap > 1)//最后一次排序组中元素个数为1
	{
		gap =gap/3 + 1;
		for (int i = 1; i < n; i++)
		{
			int tmp = a[i];
			int end = i - gap;
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}
//void SelecttSort(int *a, int n)//选择排序
//{
//	assert(a || n > 0);
//	int maxindex = 0;
//	for (int j = n - 1; j > 0; j--)
//	{
//		maxindex = 0;
//		for (int i = 1; i <= j; i++)//选出一个最大数
//		{
//			if (a[i] > a[maxindex])
//				maxindex = i;
//
//		}
//		swap(a[j], a[maxindex]);//与交换到a[j]位置上
//	}
//}
void SelecttSort(int *a, int n)//选择排序
{
	assert(a || n > 0);
	int maxindex = 0;
	int minindex = 0;
	int right = n - 1;
	int left = 0;
	while (left < right)
	{
		minindex = left;
		maxindex = right;
		for (int i = left; i <= right; i++)
		{
			if (a[maxindex] < a[i])
				maxindex = i;
			if (a[minindex] > a[i])
				minindex = i;
		}
		swap(a[maxindex], a[right]);
		if (minindex == right)
			minindex = maxindex;
		swap(a[minindex], a[left]);
		left++;
		right--;
	}
}
void AdjustDown(int *a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child]>a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}

}
void HeapSort(int *a, int n)
{
	assert(a);
	for (int i = (n-2)/2; i >=0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(a[0],a[end]);
		AdjustDown(a,end,0);
		--end;
	}

}
int GetKey(int *a, int left,int right)//三数取中法确定key值
{

	int mid = left + (right - left) / 2;
	if (a[left] > a[mid])
	{
		if (a[left] > a[right])
		{
			if (a[mid] < a[right])
				return right;
			else
				return mid;
		}
		else
		{
			return left;
		}
	}
	else
	{
		if (a[right] > a[left])
		{
			if (a[mid] > a[right])
				return right;
			else
				return mid;
		}
		else
		{
			return left;
		}
	}
}
//快速排序分块 方法一
//int PartSort(int *a,int left,int right)
//{
//	int mid = GetKey(a, left,right);
//	swap(a[mid], a[right]);
//	
//	int key= a[right];
//	int start = left;
//	int end = right - 1;
//	while (start < end)
//	{
//		while (start < end && a[start] <= key)//找大于a[key]值
//			start++;
//
//		while (start < end && a[end] >= key)//找小于a[key]值
//			end--;
//		if (start < end)
//		swap(a[end], a[start]);//将大于a[key]和小于a[key]交换，使得左边小于a[key],右边大于a[key]
//	}
//	if (a[start] > a[right])//保证start左边小于a[key]，右边大于a[key]
//	{
//		swap(a[start], a[right]);
//	}
//	return start;
//}

//int PartSort(int *a, int left, int right)//快速排序 方法二挖坑法
//{
//		int key = GetKey(a, left,right);
//		swap(a[key], a[right]);
//		int keyValue = a[right];//将最右边值a[right]保存起来，并看做一个坑
//		while (left < right)
//		{
//			//从左边找起，找大于keyValue的值，填入坑中，并形成一个坑
//			while (left < right && a[left] < keyValue)
//				left++;
//			if (left<right)
//				a[right--] = a[left];//填入坑中
//			//从右边找起，找小于keyValue的值，填入坑中，并形成一个坑
//			while (left < right && a[right] > keyValue)
//				right--;
//			if (left<right)
//		       a[left++] = a[right];//填入坑中
//		}
//		a[left] = keyValue;//将keyValue填入最后一个坑中
//		return left;
//}

int PartSort(int *a, int left, int right)//快速排序方法三
{
	int key = GetKey(a, left, right);
	swap(a[key], a[right]);
	
	int prev = left - 1;
	int cur = left;
	while (cur < right)
	{
		if (a[cur] < a[right] && ++prev != cur )
			swap(a[cur], a[prev]);
		++cur;
	}
	swap(a[++prev], a[right]);
	return prev;
}
void QuickSort(int *a, int left,int right)//快速排序
{
	assert(a);
	if (left < right)
	{
		int div = PartSort(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}
void BubbleSort(int *a, int n)//冒泡排序
{
	assert(a || n>0);
	bool flag = true;
	for (int i = 0; i < n-1; i++)
	{
		bool flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = true;
			}

		}
		if (flag == false)
			break;
	}

}
void Merge(int *a, int *tmp, int begin1, int end1, int begin2, int end2)
{
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

}
void _MergeSort(int *a, int *tmp, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	_MergeSort(a, tmp, left,mid);
	_MergeSort(a, tmp, mid + 1, right);
	Merge(a, tmp, left, mid, mid + 1, right);
	memcpy(a + left,tmp + left, (right - left + 1)*sizeof(int));
}
void MergeSort(int *a, int n)
{
	assert(a || n);
	int *tmp = new int[n];
	_MergeSort(a,tmp,0,n-1);
	delete[] tmp;
}

void CountSort(int *a, int n,int min,int max)
{
	assert(a || n > 0 || min < max);
	int cap = max - min + 1;
	int *tmp = new int[cap];
	memset(tmp, 0, sizeof(int)*cap);
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		assert(a[i] >= 0);
		index = a[i] - min;
		++tmp[index];
	}
	index = 0;
	for (int i = 0; i < cap; i++)
	{
		while (tmp[i]--)
		{
			a[index++] = i+min;
		}
	}
	delete[] tmp;
}

int GetDigit(int *a, int n)
{
	int count = 1;
	int base = 10;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= base)
		{
			count++;
			base *= 10;
		}
	}
	return count;
}
void RadixSort(int *a, int n)
{
	assert(a || n > 0);
	int count[10] = {0};
	int start[10] = {0};
	int *bucket = new int[n];
	int digit = GetDigit(a,n);
	int base = 1;
	while (digit > 0)
	{
		memset(count, 0, sizeof(int)* 10);

		for (int j = 0; j < n; j++)
		{
			int index = (a[j]/base) % 10;
			++count[index];
		}
		start[0] = 0;
		for (int i = 1; i < 10; i++)
		{
			 start[i] = start[i - 1]+count[i-1];
		}
		for (int i = 0; i < n; i++)
		{
			int num = (a[i] / base) % 10;
			int& index = start[num];
			bucket[index++] = a[i];
		}
		digit--;
		base *= 10;
		memcpy(a,bucket,sizeof(int)*n);
	}
	
	delete[] bucket;
}

