#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
struct ComplexNode
{
	ComplexNode(const T& d)
	:_data(d)
	, _next(NULL)
	, _random(NULL)
	{}
	T _data;
	ComplexNode<T>* _next;
	ComplexNode<T>* _random;
};
template<class T>
class ComplexList
{public:
	ComplexList()
		:_head(NULL)
		,_tail(NULL)
	{
	}
	~ComplexList()
	{
		ComplexNode<T>* cur = _head;
		while (cur)
		{
			ComplexNode<T> *del = cur;
			cur = cur->_next;
			delete del;
		}
	}
	ComplexList<T>& operator=(ComplexList<T>& c)
	{
		if (this != &c)
		{
			c._CloneNode();
			c._ConnectRandomNodes();
			_ReConnectNodes(c);
		}
		return *this;
	
	}
	void Print()
	{
		ComplexNode<T>* cur = _head;
		while (cur)
		{
			cout << cur->_data<<" ";
			cur = cur->_next;
		}
		cout << endl;
	}
	void PushBack(const T& d)
	{
		ComplexNode<T>* NewNode = new ComplexNode<T>(d);
		if (_head == NULL)
		{
			_head = _tail=NewNode;
		}
		else
		{
			_tail->_next = NewNode;
			_tail = NewNode;
		}
	}
	ComplexNode<T>* Address(int n)
	{
		ComplexNode<int>* cur = _head;
		while (--n)
		{
			cur = cur->_next;
		}
		return cur;
	}
private:
	void _CloneNode()
	{
		if (_head == NULL)
			return;
		ComplexNode<T>* cur = _head;
		while (cur)
		{
			ComplexNode<T>* Node = new ComplexNode<T>(cur->_data);
			Node->_next = cur->_next;
			cur->_next = Node;
			cur = Node->_next;
		}
	}
	void _ConnectRandomNodes()
	{
		ComplexNode<T>* cur = _head;
		while (cur)
		{
			if (cur->_random)
			{
				cur->_next->_random = cur->_random->_next;
			}
			cur = cur->_next->_next;
		}
	}
	void _ReConnectNodes(ComplexList<T>& c)
	{
		assert(c._head);
		ComplexNode<T>* cur = c._head;
		_head = c._head->_next;
		ComplexNode<T>* CloneHead = _head;
		while (CloneHead->_next)
		{
			cur->_next = CloneHead->_next;
			cur = cur->_next;
			CloneHead->_next = cur->_next;
			CloneHead = CloneHead->_next;
			cur->_next = CloneHead->_next;
		}
	}
private:
	ComplexNode<T>* _head;
	ComplexNode<T>* _tail;
};



