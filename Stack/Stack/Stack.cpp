#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include<string>
int main()
{
	Stack<string> s;
	s.Push("1111111111111");
	s.Push("2222222222222");
	s.Push("3333333333333");
	s.Push("4444444444444");
	s.Push("5555555555555");
	Stack<string> s1(s);
	Stack<string> s2;
	s2 = s;
	while (!s2.Empty())
	{
		cout << s2.Top() << " ";
		s2.Pop();
	}
	getchar();
	return 0;
}