#include<iostream>
#include"Sort.h"
using namespace std;

void Print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void TestInsertSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,8 };
	int size = sizeof(a) / sizeof(a[0]);
	InsertSort(a, size);
	Print(a, size);
}
void TestShellSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,8 };
	int size = sizeof(a) / sizeof(a[0]);
	ShellSort(a, size);
	Print(a, size);
}

void TestSelecttSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 8 };
	int size = sizeof(a) / sizeof(a[0]);
	SelecttSort(a, size);
	Print(a, size);
}
void TestBubbleSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 8 };
	int size = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, size);
	Print(a, size);
}

void TestQuickSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 8 };
	//int a[] = {4,7,7,2,8,0,1};
	int size = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0,size-1);
	Print(a, size);
}

void TestMergeSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 8 };
	//int a[] = {4,7,7,2,8,0,1};
	int size = sizeof(a) / sizeof(a[0]);
	MergeSort(a, size);
	Print(a, size);
}

void TestCountSort()
{
	//int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 8 };
	//int a[] = {4,7,7,2,8,0,1};
	int a[] = {22,55,30,67,89,90,100,45,34,67,34,34,67,67,89,55,22,67,90};
	int size = sizeof(a) / sizeof(a[0]);
	CountSort(a, size,22,100);
	Print(a, size);
}
int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelecttSort();
	//TestBubbleSort();
    // TestQuickSort();
	//TestMergeSort();
	TestCountSort();
	getchar();
	return 0;
}