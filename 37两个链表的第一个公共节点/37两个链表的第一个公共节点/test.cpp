#include<iostream>
using namespace std;

struct ListNode
{
	ListNode* _next;
	int _value;
	ListNode(int value)
		:_value(value)
		,_next(NULL)
	{}
};
int GetLength(ListNode* pHead)
{
	int length = 0;
	while (pHead != NULL)
	{
		length++;
		pHead = pHead->_next;
	}
	return length;

}
ListNode* FindFistCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	
	int length1 = GetLength(pHead1);
	int length2 = GetLength(pHead2);

	int lengthDif = length1 - length2;
	ListNode* longlist = pHead1;
	ListNode* shortlist = pHead2;
	if (lengthDif < 0)
	{
		lengthDif = length2 - length1;
		longlist = pHead2;
		shortlist = pHead1;
	}
	while (lengthDif--)
	{
		longlist = longlist->_next;
	}
	while (longlist != NULL && shortlist != NULL && longlist != shortlist)
	{
		longlist = longlist->_next;
		shortlist = shortlist->_next;
	}
	return longlist;
}
void TestList()
{
	ListNode* head1 = new ListNode(1);
	ListNode* lnode1 = new ListNode(2);
	ListNode* lnode2 = new ListNode(3);
	ListNode* lnode3 = new ListNode(6);
	ListNode* lnode4 = new ListNode(7);
	head1->_next = lnode1;
	lnode1->_next = lnode2;
	lnode2->_next = lnode3;
	lnode3->_next = lnode4;

	ListNode* head2 = new ListNode(4);
	/*ListNode* snode1 = new ListNode(5);
	head2->_next = snode1;
	snode1->_next = lnode3;*/

	ListNode* node=FindFistCommonNode(head1,head2);
	cout << node->_value << endl;
}
int main()
{
	
	TestList();
	getchar();
	return 0;
}