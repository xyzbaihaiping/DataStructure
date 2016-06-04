#include<iostream>
using namespace std;

struct ComplexListNode
{
	ComplexListNode(const int& d)
	:_value(d)
	,_next(NULL)
	,_sibling(NULL)
	{}
	int _value;
	ComplexListNode* _next;
	ComplexListNode* _sibling;
};

void CloneNodes(ComplexListNode* pHead)
{
	if (pHead == NULL)
		return;
	ComplexListNode* cur = pHead;
	while (cur)
	{
		ComplexListNode* node = new ComplexListNode(cur->_value);
		node->_next = cur->_next;
		cur->_next = node;
		cur = node->_next;
	}
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{
	if (pHead == NULL)
		return;
	ComplexListNode* cur = pHead;
	while (cur)
	{
		if (cur->_sibling != NULL)
			cur->_next->_sibling = cur->_sibling->_next;
		cur = cur->_next->_next;
	}

}
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	ComplexListNode* cur = pHead;
	ComplexListNode* newNode = pHead->_next;
	ComplexListNode* cloneNode = newNode;

	while (cur)
	{
		cur->_next = cloneNode->_next;
		cur = cur->_next;
		if (cur)
		{
			cloneNode->_next = cur->_next;
			cloneNode = cloneNode->_next;
		}
	}
	return newNode;
}
ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

void Test()
{
	ComplexListNode* node1 = new ComplexListNode(1);
	ComplexListNode* node2 = node1->_next = new ComplexListNode(2);
	ComplexListNode* node3 = node2->_next = new ComplexListNode(3);
	ComplexListNode* node4 = node3->_next = new ComplexListNode(4);
	ComplexListNode* node5 = node4->_next = new ComplexListNode(5);
	node1->_sibling = node4;
	node2->_sibling = node1;
	node3->_sibling = node5;
	node4->_sibling = NULL;
	node5->_sibling = node2;
	ComplexListNode* newHead=Clone(node1);
	ComplexListNode* cur = newHead;
	while (cur)
	{
		cout << cur->_value << " ";
		cur = cur->_next;
	}
}
int main()
{
	Test();
	getchar();
	return 0;
}