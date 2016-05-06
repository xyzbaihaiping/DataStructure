#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

class A
{
public:
	A(int a=0,int b=0)
		:_a(a)
		, _b(b)
	{
		cout << "A()"<<endl;
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
	A *a2 = new A[10];

	A *p = (A *)(a2 - 0x00000004);
	int count = *((int *)(a2 - 0x04));
	
	for (int i = 0; i < count; i++)
	{
		a2[i].~A();
	}
	operator delete[](a2-1);
	getchar();
	return 0;
}