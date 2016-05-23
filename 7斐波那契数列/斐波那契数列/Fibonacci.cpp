#include<iostream>
using namespace std;

long long Fibonacci(size_t n)//µ›πÈÀ„∑®
{
	return n < 2 ? n : Fibonacci(n - 2) + Fibonacci(n - 1);
}

long long FibonacciNoR(int n)
{
	if (n < 0)
		return 0;
	long long  result[2] = { 0, 1 };

	if (n <= 1)
	{
		return result[n];
	}

	long long first = 0;
	long long second = 1;
	long long fib= 0;
	int i = 0;
	while ( n >= 2 )
	{
		fib = first + second;
		first = second;
		second = fib;
		n--;
	}
	return fib;
}
int main()
{
	int  n = 10;
	long long ret = Fibonacci(n);
	cout << "ret :" << ret << endl;
	getchar();
	return 0;
}
