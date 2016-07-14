#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;



//解法一：构造函数法
class Temp
{
public:
	Temp()
	{
		N++;
		sum += N;
	}
	static void Reset()
	{
		N = 0;
		sum = 0;
	}
	static unsigned int GetSum()
	{
		return sum;
	}
private:
	static unsigned int N;
	static unsigned int sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::sum = 0;

unsigned int SumSolution1(unsigned int n)
{
	Temp::Reset();
	Temp* tmp = new Temp[n];

	delete tmp;
	tmp = NULL;
	return Temp::GetSum();
}

//解法二：虚函数法

class A;
A* g_arr[2];

class A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}

};

class B : public A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return g_arr[!!n]->Sum(n - 1) + n;
	}
};
unsigned int SumSolution2(unsigned int n)
{
	A a;
	B b;

	g_arr[0] = &a;
	g_arr[1] = &b;

	int value = g_arr[1]->Sum(n);

	return value;
}

//解法三：利用函数指针实现

typedef unsigned int(*fun)(unsigned int);
unsigned int Sum(unsigned int n)
{
	return 0;
}

unsigned int SumSolution3(unsigned int n)
{
	static fun f[2] = {Sum,SumSolution3};
	return n + f[!!n](n-1);

}
//解法四：利用模板类型求解

template<unsigned int n>
struct SumSolution4
{
	enum value
	{
		N = SumSolution4<n - 1>::N + n;
	};

};

template<>
struct SumSolution4<1>
{
	enum value
	{
		N = 1
	};
};

int main()
{
	cout << SumSolution3(5) << endl;

	getchar();
	return 0;
}