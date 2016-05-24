#include<iostream>

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

ListNode* ReversrList(ListNode* pHead)
{
	if (pHead->_next == NULL)
	{
		return pHead;
	}
	ListNode* cur = pHead;
	ListNode* prev = NULL;
	ListNode* newHead = NULL;
	while (cur)
	{
		prev = cur;
		cur = cur->_next;
		prev->_next = newHead;
		newHead = prev;
	}
	return newHead;
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
	ListNode* head = ReversrList(NULL);
	if (head!=NULL)
	cout << head->_value << endl;
	getchar();
	return 0;
}