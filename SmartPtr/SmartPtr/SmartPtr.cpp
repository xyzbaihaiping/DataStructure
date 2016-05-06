#include "SmartPtr.h"
void TestAutoPtr()
{
	int *p1 = new int(1);
	AutoPtr<int> ap1(p1);
	AutoPtr<int> ap2(ap1);
	AutoPtr<int> ap3(new int(2));
	ap3 = ap2;
	*ap3 = 3;
}
void TestScopedPtr()
{
	int *p1 = new int(1);
	int *p2 = new int(2);

	/*ScopedPtr<int> sp1(p1);
	ScopedPtr<int> sp2(sp1);
	ScopedPtr<int> sp3(p2);
	sp3 = sp2;*/
}
void TestSharedPtr()
{
	int *p1 = new int(1);
	int *p2 = new int(2);
	SharedPtr<int> sp1(p1);
	SharedPtr<int> sp2(p2);
	SharedPtr<int> sp3(sp1);
	sp1 = sp2;
	sp1 = sp1;
	sp1 = sp2;
}
void TestScopedArray()
{
	int* p1 = new int[10];
	int* p2 = new int[10];
	ScopedArray<int> sp1(p1);
	//ScopedArray<int> sp2(sp1);
	ScopedArray<int> sp3(p2);
	for (int i = 0; i < 10; i++)
	{
		sp1[i] = i;
	}
}
void TestSharedArray()
{

	int *arr1 = new int[10];
	int *arr2 = new int[10];
	SharedArray<int> sparr1(arr1);
	SharedArray<int> sparr2(arr2);
	SharedArray<int> sparr3(sparr1);
	sparr1 = sparr2;
	sparr1[1] = 10;
}
int main()
{
	TestSharedArray();
	getchar();
	return 0;
}