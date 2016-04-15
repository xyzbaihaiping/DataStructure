#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include<assert.h>
using namespace std;

//使用两个队列实现一个栈
template<class T>
class Stack
{
public:
	void Push(const T& d)
	{
		if (!_Qfirst.empty())
			_Qfirst.push(d);
		else
			_Qsecond.push(d);
	}
	void Pop()
	{
		if (!_Qfirst.empty())
		{
			_Pop(_Qfirst, _Qsecond);
		}
		else
			_Pop(_Qsecond, _Qfirst);
	}
	bool Empty()
	{
		if (_Qfirst.empty() && _Qsecond.empty())
		{
			return true;
		}
		else
			return false;
	}
	T& Top()
	{
		if (!_Qfirst.empty())
		{
			return _Qfirst.back();
		}
		else
			return _Qsecond.back();
	}
	size_t Size()
	{
		if (!_Qfirst.empty())
		{
			return _Qfirst.size();
		}
		else
			return _Qsecond.size();
	}
protected:
	void _Pop(queue<T>& Q1, queue<T>& Q2)
	{
		
		while (Q1.size()>1)
		{
			T& data = Q1.front();
			Q2.push(data);
			Q1.pop();
		}
		Q1.pop();
	}
protected:
	queue<T> _Qfirst;
	queue<T> _Qsecond;
};
////两个栈实现一个队列
template<class T>
class Queue
{
public:
	void Push(const T& d)
	{
		sPush.push(d);
	}
	void Pop()
	{
		assert(Size());
		if (sPop.empty())
		{
			ExChange(sPush, sPop);
		}
		sPop.pop();
	
	}
	T& Front()
	{
		assert(Size());
		if (sPop.empty())
		{
			ExChange(sPush, sPop);
		}
		return sPop.top();
	}
	T& Back()
	{
		assert(Size());
		if (sPush.empty())
		{
			ExChange(sPop, sPush);
		}
		return sPush.top();
	}
	bool Empty()
	{
		return Size()==0;
	}
	size_t Size()
	{
		return sPush.size() + sPop.size();
	}
	
private:
	void ExChange(stack<T>& sout, stack<T>& sin)
	{
		while (!sout.empty())
		{
			sin.push(sout.top());
			sout.pop();
		}
	
	}
private:
	stack<T> sPush;
	stack<T> sPop;
};
//验证进栈出栈的合法性
template<class T>
bool CheckStack(const T *sPush,const T *sPop, size_t sizein,size_t sizeout)
{
	assert(sPush && sPop);
	assert(sizein && sizeout);
	if (sizein != sizeout)
		return false;
	stack<T> s;
	int i = 0;
	int j = 0;
	for ( i = 0; i < sizein; i++)
	{
		s.push(sPush[i]);
		while (j<sizeout)
		{	
			if (!s.empty() && s.top() == sPop[j])
			{
				s.pop();
				j++;
			}
			else
			{
				break;
			}
		}

	}
	if (!s.empty())
	{
		return false;
	}
	else
		return true;
}
//实现一个栈，实现入栈，出栈，求最小值，时间复杂度为O(1)；
template<class T>
class Stack
{
public:
	void Push(const T& d)
	{
		s.push(d);
		if (s.size() == 1)
			min.push(s.top());
		else
		{
			if (s.top() <= min.top())
			{
				min.push(s.top());
			}
		}
	}
	void Pop()
	{
		if (!s.empty())
		{
			if (s.top() == min.top())
				min.pop();
			s.pop();
		}
	}
	T& Min()
	{
		return min.top();
	}
	size_t Size()
	{
		return s.size();
	}
	bool Empty()
	{
		return s.empty();
	}
	T& Top()
	{
		return s.top();
	}
private:
	stack<T> s;
	stack<T> min;
};

//一个数组实现两个栈
template<class T>
class TwoStack
{
public:
	TwoStack()
	:_a(NULL)
	, _top1(0)
	, _top2(0)
	, _capacity(0)
	{
		_CheckCapacity();
	}
	~TwoStack()
	{
		if (_a)
			delete[] _a;
	}
	void Push1(const T& d)
	{
		_CheckCapacity();
		_a[_top1++] = d;
	}
	void Push2(const T& d)
	{
		_CheckCapacity();
		_a[_top2--] = d;
	}
	void Pop1()
	{
		if (_top1 > 0)
		--_top1;
	}
	void Pop2()
	{
		if (_top2 < _capacity-1)
			_top2++;	
	}
	size_t Size1()
	{
		return _top1;
	}
	size_t Size2()
	{
		return _capacity -1- _top2;
	}
	bool Empty1()
	{
		return _top1 == 0;
	}
	bool Empty2()
	{
		return _top2 == _capacity - 1;
	}
	T& Top1()
	{
		if (_top1>0)
		{
			return _a[_top1-1];
		}
	}
	T& Top2()
	{
		if (_top2 < _capacity - 1)
			return _a[_top2+1];
	}

private:
	void _CheckCapacity()
	{
		if (_a == NULL)
		{
			_capacity += 3;
			_a = new T[_capacity];
			_top2 = _capacity - 1;
			return;
		}
		if (_top1 == _top2)
		{
			size_t OldCapacity = _capacity;
			_capacity = _capacity * 2;
			T* tmp = new T[_capacity];
			for (size_t i = 0; i < _top1; i++)
			{
				tmp[i] = _a[i];
			}
			for (size_t j = OldCapacity-1,i=_capacity-1; j>_top2;j--,i--)
			{
				tmp[i] = _a[j];
			}
			delete[] _a;
			_a = tmp;
			_top2 += _capacity / 2;
		}
	}

private:
	T* _a;
	size_t _top1;
	size_t _top2;
	size_t _capacity;
};



