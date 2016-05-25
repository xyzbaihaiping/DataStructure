#include<iostream>
using namespace std;

struct ListNode
{
	ListNode(const int& value)
	:_value(value)
	, _next(NULL)
	{
	}
	int _value;
	ListNode* _next;
};

//ListNode* Merage(ListNode* pHead1,ListNode* pHead2)//·ÇµÝ¹é
//{
//	if (pHead1 == NULL)
//		return pHead2;
//	else if (pHead2==NULL)
//		return pHead1;
//
//	ListNode* newHead = NULL;
//	if (pHead1->_value > pHead2->_value)
//	{
//		newHead = pHead2;
//		pHead2 = pHead2->_next;
//	}
//	else
//	{
//		newHead = pHead1;
//		pHead1 = pHead1->_next;
//	}
//	ListNode* cur = newHead;
//	while (pHead1&& pHead2)
//	{
//		if (pHead1->_value > pHead2->_value)
//		{
//			cur->_next = pHead2;
//			pHead2 = pHead2->_next;
//		}
//		else
//		{
//			cur->_next = pHead1;
//			pHead1 = pHead1->_next;
//		}
//		cur = cur->_next;
//	}
//	if (pHead1 == NULL)
//		cur->_next = pHead2;
//	else
//		cur->_next = pHead1;
//	return newHead;
//}

ListNode* Merage(ListNode* pHead1, ListNode* pHead2)//µÝ¹é
{
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	ListNode* newHead = NULL;
	if (pHead1->_value > pHead2->_value)
	{
		newHead = pHead2;
		newHead->_next = Merage(pHead1, pHead2->_next);
	}
	else
	{
		newHead = pHead1;
		newHead->_next = Merage(pHead1->_next, pHead2);
	}

	return newHead;
}
void Test()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	node1->_next = node2;
	node2->_next = node3;
	node3->_next = node4;
	node4->_next = node5;

	ListNode* node21 = new ListNode(1);
	ListNode* node22 = new ListNode(1);
	ListNode* node23 = new ListNode(4);
	ListNode* node24 = new ListNode(7);
	ListNode* node25 = new ListNode(8);
	node21->_next = node22;
	node22->_next = node23;
	node23->_next = node24;
	node24->_next = node25;
	ListNode* node=Merage(node1,node22);
}
int main()
{
	Test();
	getchar();
	return 0;
}