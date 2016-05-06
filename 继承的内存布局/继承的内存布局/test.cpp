#include<iostream>
using namespace std;
typedef void(*PFUN)();
class B
{
public:
	B() :_b(1){}
	virtual void fun1()
	{
		cout << "B::fun1()" << endl;
	}
     virtual void fun2()
	{
		cout << "B::fun2()" << endl;
	}
private:
	int _b;
};
class B2
{
public:
	B1() :_b1(2){}
	virtual void fun1()
	{
		cout << "B2::fun1()" << endl;
	}
	virtual void fun2()
	{
		cout << "B2::fun2()" << endl;
	}
private:
	int _b2;
};
class D:public B1,public B2
{
public:
	D() :_d(3){}
	void fun1()
	{
		cout << "D::fun1()" << endl;
	}
	virtual void fun3()
	{
		cout << "D::fun3()" << endl;
	}
private:
	int _d;
};
void PrintVT(int b)
{
	PFUN pfun = NULL;
	int *ptr = (int *)b;
	int i = 0;
	while (ptr[i])
	{
		pfun = (PFUN)ptr[i];
		pfun();
		i++;
	}
}

int main()
{
	D d;
	PrintVT(*(int *)&d);
	cout << "---------" << endl;
	PrintVT(*((int *)&d+2));
	getchar();
	return 0;
}
