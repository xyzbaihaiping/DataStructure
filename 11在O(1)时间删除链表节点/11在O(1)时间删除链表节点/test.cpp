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

void DeleteNode(ListNode** pHead, ListNode* pNode)
{
	assert(pHead);
	assert(pNode);
	ListNode* cur = *pHead;
	if (pNode == cur && cur->_next==NULL)
	{
		delete pNode;
		pHead = NULL;
	}
	else if (pNode->_next != NULL)
	{
		ListNode* del = pNode->_next;
		pNode->_value = pNode->_next->_value;
		pNode->_next = del->_next;
		delete del;
		del = NULL;
	}
	else
	{
		while (cur->_next != pNode)
		{
			cur = cur->_next;
		}
		cur->_next = NULL;
		delete pNode;
		pNode = NULL;
	}
}

int main()
{
	/*ListNode* Node1 = new ListNode(1);
	ListNode* Node2 = new ListNode(2);
	ListNode* Node3 = new ListNode(3);
	ListNode* Node4 = new ListNode(4);
	Node1->_next = Node2;
	Node2->_next = Node3;
	Node3->_next = Node4;*/
	ListNode* Node1 = new ListNode(1);
	DeleteNode(&Node1, Node1);

	return 0;
}