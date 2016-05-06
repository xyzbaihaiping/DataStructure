#pragma once

#include<assert.h>
#include<iostream>
using namespace std;

typedef int DataType;
struct Node
{
	Node(const DataType& d)
	:_data(d)
	,_next(NULL)
	{}
	DataType _data;
	Node* _next;
};

class SList
{
public:
	SList()
		:_head(NULL)
		,_tail(NULL)
	{
	}
	~SList()
	{
		Node* cur = _head;
		while (cur)
		{
			Node* del = cur;
			cur = cur->_next;
			delete del;
		}
	}
	SList(const SList& s)
		:_head(NULL)
		,_tail(NULL)
	{
		Node* cur = s._head;
		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	SList& operator=(SList s)
	{
		swap(_head,s._head);
		swap(_tail,s._tail);
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

	friend ostream& operator<<(ostream& output, const SList& s);

	//链表常见的面试题
	//删除非尾节点-----1
	void EraseNotTail(Node* pos);

	// 在当前节点前插入一个数据x-----5
	void InsertFrontNode(Node* pos, DataType d);

	//合并两个有序列表-----6
	void SList::Merge(SList l1);



	//查找链表的中间节点---7
	Node* FindMidNode();

	//约瑟夫环
	Node* JoseCycle(int num);

	// 删除单链表的倒数第k个节点(k > 1 && k < 链表的总长度)----9
	// 时间复杂度O(N)
	void DelKNode(int k);

	// 【链表带环问题】-----10
	// 判断链表是否带环 ,若带环返回相遇节点，不带环返回NULL
	Node* CheckCycle();
	//若链表带环则求环的长度
	int GetCircleLength(Node* meet);
	//获取环入口点
	Node* FindEntryNMeetNodeode(Node* MeetNode);


	// 【链表相交问题】
	//
	// 判断两个链表是否相交，假设两个链表都不带环。

	int CheckCross(SList list1, SList list2);
	// 求链表的交点，长链表先走n步（n为两链表的长度差），然后再一起走，第一个相遇点则为交点。
	Node* LinkCrossNode(SList list1, SList list2);
private:
	Node* _head;
	Node* _tail;
};