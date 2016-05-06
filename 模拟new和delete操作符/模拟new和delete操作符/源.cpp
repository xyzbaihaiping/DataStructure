#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
using namespace std;

class A
{
public:
	A(int a = 0,int b = 0)
		:_a(a)
		, _b(b)
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
	int _b;
};

int main()
{
	/*A *pa = new A[10];
	delete[] pa;*/
	A *pa = (A*)operator new(10 * sizeof(A)+4);
	*((int *)pa) = 10;//将第一个（占用4个字节）空间赋值为创建对象的个数
	A *pStart = (A*)((int *)pa + 1);
	//new操作符返回的地址是开辟的连续空间的向后移4个字节之后的地址
	for (int i = 0; i < 10; i++)
	{
		new(pStart + i)A(1, 0);// new表达式（placeement new） 形式(place_address)type(initializer-list)
	}
	int count = *((int *)pStart - 1);
	//计算开辟的连续内存空间最前面的占用4个字节的空间中所存的释放空间之前调用析构函数的次数
	for (int i = 0; i < count; i++)
	{
		pStart[i].~A();//delete在释放前自动调用析构函数
	}
	operator delete[]((int *)pStart - 1);//调用operator delete[](char *)函数释放内存空间
	system("pause");
	return 0;
}