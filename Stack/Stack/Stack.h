#pragma once
#include<iostream>

using namespace std;

template<class T>
class Stack
{
public:
	Stack();
	~Stack();
	Stack(const Stack<T>& s);
	//Stack<T>& operator=(Stack<T> s);
	Stack<T>& operator=(const Stack<T>& s);
	void Push(const T& d);
	void Pop();
	T& Top();
	bool Empty();
	size_t Size();
protected:
	void _CheckCapacity();
protected:
	T* _a;
	size_t _top;
	size_t _capacity;
};
template<class T>
void Stack<T>::_CheckCapacity()
{
	if (_a == NULL)
	{
		_capacity = 3;
		_a = new T[_capacity];
		return;
	}
	if (_top == _capacity)
	{
		_capacity += 3;
		T* tmp = new T[_capacity];
		for (size_t i = 0; i < _top; i++)
		{
			tmp[i] = _a[i];
		}
		delete[] _a;
		_a = tmp;
	}
}

template<class T>
Stack<T>::Stack()
:_a(0)
, _top(0)
, _capacity(0)
{}

template<class T>
Stack<T>::~Stack()
{
	if (_a)
	{
		delete[] _a;
	}
}
template<class T>
Stack<T>::Stack(const Stack<T>& s)
:_a(new T[_top])
,_top(s._top)
,_capacity(s._capacity)
{
	
	for (size_t i = 0; i < _top; i++)
	{
		_a[i] = s._a[i];
	}

}

//template<class T>
//Stack<T>& Stack<T>::operator=(Stack<T> s)
//{
//		swap(s._a,_a);
//		_top = s._top;
//		_capacity = s._capacity;	
//	    return *this;
//}
template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s)
{
	if (this != &s)
	{
		T* tmp = new T[s._top];
		for (size_t i = 0; i < s._top; i++)
		{
			tmp[i] = s._a[i];
		}
		delete[] _a;
		_a = tmp;
		_capacity = s._top;
		_top = s._top;
	}
	return *this;
}

template<class T>
void Stack<T>::Push(const T& d)
{
	_CheckCapacity();
	_a[_top++] = d;
}

template<class T>
void Stack<T>::Pop()
{
	assert(_top > 0)
		--_top;
}

template<class T>
T& Stack<T>::Top()
{
	assert(_top>0)
	return _a[_top - 1];
}
template<class T>
bool Stack<T>::Empty()
{
	if (_top == 0)
		return true;
	else
		return false;
}

template<class T>
size_t Stack<T>::Size()
{
	return _top;
}