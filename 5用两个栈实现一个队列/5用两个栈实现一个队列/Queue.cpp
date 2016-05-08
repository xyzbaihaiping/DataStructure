#include<iostream>
#include<stack>
using namespace std;

template<class T>
class Queue
{
public:
	void appendTail(const T& x);
	void DeleteHead();
private:
	stack<T> s1;
	stack<T> s2;
};

template<class T>
void Queue<T>::appendTail(const T& x)
{
     while(!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
	 s1.push(x);
}
template<class T>
void Queue<T>::DeleteHead()
{
	if (s2.empty())
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	s2.pop();
}


int main()
{
	Queue<int> q;
	q.appendTail(1);
	q.appendTail(2);
	q.appendTail(3);
	q.appendTail(4);
	q.DeleteHead();
	q.DeleteHead();
	q.appendTail(5);
	q.appendTail(6);
	q.appendTail(7);
	getchar();
	return 0;
}
