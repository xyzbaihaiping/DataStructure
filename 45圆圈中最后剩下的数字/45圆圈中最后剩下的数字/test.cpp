#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<list>
using namespace std;
int LastRemaining_1(unsigned int n, unsigned int m)//约瑟夫环法
{
	if (n <= 0 || m < 1)
		return -1;

	list<int> numbers;

	for (unsigned int i = 0; i < n; i++)
		numbers.push_back(i);

	list<int>::iterator cur = numbers.begin();

	while (numbers.size() > 1)
	{
		for (int i = 1; i < m; i++)
		{
			cur++;
			if (cur == numbers.end())
				cur = numbers.begin();
		}

		list<int>::iterator next = ++cur;
		if (next == numbers.end())
			next = numbers.begin();

		numbers.erase(--cur);
		cur = next;
	}
	return *cur;
}

int LastRemaining_2(unsigned int n, unsigned int m)//循环法
{
	if (n < 1 || m < 1)
		return -1;
	int last = 0;
	for (unsigned int i = 2; i <= n;i++)
	{
		last = (last + m) % i;
	}
	return last;
}
int main()
{
	int ret=LastRemaining_2(5,3);
	cout << ret << endl;
	getchar();
	return 0;
}