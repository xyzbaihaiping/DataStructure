#pragma once
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

template<class T>
struct Node
{
	Node(const T& d)
	:_data(d)
	,_next(NULL)
	{}
	T _data;
	Node<T>* _next;
};
template<class T>
class Queue
{
public:
	Queue()
		:_head(NULL)
		,_tail(NULL)
		, _size(0)
	{}
	~Queue()
	{
		while (!Empty())
		{
			Pop();
		}
	}
	Queue(const Queue<T>& q) 
		:_head(NULL)
		,_tail(NULL)
		, _size(0)
	{
		Node<T>* cur = q._head;
		while (cur)
		{
			Push(cur->_data);
			cur = cur->_next;
		}
	}
	Queue<T>& operator=(Queue<T> q)
	{
		swap(_head, q._head);
		swap(_tail, q._tail);
		_size = q._size;
		return *this;
	}
	void Push(const T& d)
	{
		Node<T>* NewNode = new Node<T>(d);
		if (_head == NULL)
		{
			_head = NewNode;
			_tail = NewNode;
		}
		else
		{
			_tail->_next = NewNode;
			_tail = NewNode;
		}
		_size++;
	}
	void Pop()
	{
		if (_head == NULL)
			return;
		if (_head == _tail)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
		}
		else
		{
			Node<T>* del = _head;
			_head = _head->_next;
			delete del;
		}
		_size--;
	}
	T& Front() const
	{
		assert(_head);
		return _head->_data;
	}
	T& Back() const
	{
		assert(_tail);
			return _tail->_data;
	}
	bool Empty() const
	{
		return _head == NULL;
	}
	size_t Size() const
	{
		return _size;
	}
protected:
	Node<T>* _head;
	Node<T>* _tail;
	size_t _size;
};
