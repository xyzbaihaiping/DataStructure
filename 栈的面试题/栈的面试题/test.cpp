#define _CRT_SECURE_NO_WARNINGS
#include "Stack_Queue.h"
#include<string>

void TestStack()
{
	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);

	cout << s1.Size() << endl;
	while (!s1.Empty())
	{
		cout << s1.Top() << " ";
		s1.Pop();
	}
}
void TestQueue()
{
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	cout <<q.Size() << endl;
	while (!q.Empty())
	{
		cout <<q.Front() << " ";
		q.Pop();
	}
}
void TestCheckStack()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = {1,2,3,4,5};
	size_t sizein = sizeof(a) / sizeof(a[0]);
	size_t sizeout = sizeof(a) / sizeof(a[0]);
	cout << CheckStack(a, b, sizein,sizeout) << endl;
}
void TestStackMin()
{
	Stack<int> s;
	s.Push(4);
	s.Push(3);
	s.Push(2);
	s.Push(2);
	cout << s.Size() << endl;
	cout << s.Min() << endl;;
	while (!s.Empty())
	{
		cout << s.Top() << " " << endl;
		cout << "min:"<<s.Min() << endl;
		s.Pop();
	}


}
void TestTwoStack()
{
	TwoStack<int> s;
	s.Push1(1);
	s.Push1(2);
	s.Push1(3);
	s.Push1(4);
	s.Push1(5);
	s.Push2(1);
	s.Push2(2);
	s.Push2(3);
	s.Push2(4);
	s.Push2(5);
	cout << "s1:"<<s.Size1() << endl;;
	cout << "s2:" << s.Size2() << endl;
	while (!s.Empty1())
	{
		cout << s.Top1() << endl;
		s.Pop1();
	}
	while (!s.Empty2())
	{
		cout << s.Top2() << endl;
		s.Pop2();
	}


}
int main()
{
	TestTwoStack();
	getchar();
	return 0;
}
