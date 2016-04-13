#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"
#include<string>
void test()
{
	Queue<string> q1;
	q1.Push("111111111111");
	q1.Push("222222222222");
	q1.Push("333333333333");
	q1.Push("444444444444");
	q1.Push("555555555555");
	Queue<string> q2(q1);
	Queue<string> q3;
	q3=q1;
	cout << q3.Size() << endl;
	while (!q3.Empty())
	{
		cout <<q3.Front()<< endl;
		q3.Pop();
	}

}

int main()
{
	test();
	getchar();
	return 0;
}
