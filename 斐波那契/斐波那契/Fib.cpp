#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//long long Fib(size_t n)//µÝ¹é
//{
//	return n<2 ? n: Fib(n - 1) + Fib(n - 2);
//}
long long Fib(size_t n)//·ÇµÝ¹é
{
	if (n < 2)
		return n;
	long long first = 0;
	long long second = 1;
	long long ret = 0;
	for (size_t i = 2; i <= n; i++)
	{
		ret = first + second;
		first = second;
		second = ret;
	}
	return ret;
}
long long* FibArray(size_t n)//ì³²¨ÄÇÆõÊýÁÐ
{
	long long* _a = new long long[n + 1];
	_a[0] = 0;
	_a[1] = 1;
	for (size_t i = 2; i <= n; i++)
	{
		_a[i] = _a[i - 1] + _a[i - 2];
	}
	return _a;

}
int main()
{
	cout << Fib(10) << endl;
	long long* ret = FibArray(10);
	for (int i = 0; i <= 10; i++)
	{
		cout << ret[i] << " ";
	}
	getchar();
	return 0;
}