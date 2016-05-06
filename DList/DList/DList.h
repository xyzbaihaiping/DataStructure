#pragma once

#include<iostream>
#include<assert.h>
using namespace std;
typedef int DataType;
struct Node
{
	Node(const DataType& d)
	:_data(d)
	,_prev(NULL)
	,_next(NULL)
	{
	}
	Node* _prev;
	DataType _data;
	Node* _next;
};
class DList
{
public:
	DList()
		:_head(NULL)
		, _tail(NULL)
	{
	}
	~DList()
	{
		Node* cur = _head;
		while (cur)
		{
			Node *del = cur;
			cur = cur->_next;
			delete del;
		}
	}
	DList(const DList& dl)
		:_head(NULL)
		, _tail(NULL)
	{
		Node *cur = dl._head;
		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	DList& operator=(DList dl)
	{
		swap(_head, dl._head);
		swap(_head, dl._head);
		return *this;
	}
public:
	void PushBack(const DataType& d);
	void PushFront(const DataType& d);
	void PopBack();
	void PopFront();
	Node* Find(const DataType& d);
	void Insert(Node* pos, const DataType& d);
	void Reverse();
	void Sort();
	void Remove(const DataType& d);
	void RemoveAll(const DataType& d);
	void Erase(Node* pos);
	friend ostream& operator<<(ostream& output, const DList& s);

private:
	Node* _head;
	Node* _tail;
};