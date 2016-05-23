#include<iostream>
#include<assert.h>
using namespace std;

struct ListNode
{
	ListNode(const int& value)
	:_value(value)
	, _next(NULL)
	{}
	int _value;
	ListNode* _next;
};

ListNode* FindKTheToTail(ListNode* pHead, size_t k)
{
	if (pHead == NULL || k == 0)
		return NULL;
	ListNode* first = pHead;
	ListNode* second = pHead;
	while (first && --k)
	{
		first = first->_next;
	}
	if (first == NULL)
		return NULL;
	while (first->_next)
	{
		first = first->_next;
		second = second->_next;
	}
	return second;
}
int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	node1->_next = node2;
	node2->_next = node3;
	node3->_next = node4;
	ListNode* ret = FindKTheToTail(node1,5);
	if (ret != NULL)
		cout << ret->_value << endl;
	else
		cout << "not find" << endl;
	getchar();
	return 0;
}