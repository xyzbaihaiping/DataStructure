#include<iostream>
#include<stack>
using namespace std;

struct ListNode
{
	ListNode(int data)
	:_data(data)
	, _next(NULL)
	{}
	int _data;
	ListNode* _next;
};

void PrintListReverse(ListNode *pHead)
{
	stack<ListNode*> s;
	ListNode* cur = pHead;
	while (cur)
	{
		s.push(cur);
		cur = cur->_next;
	}

	while (!s.empty())
	{
		cout << s.top()->_data<< " ";
		s.pop();
	}
}
//void PrintListReverse(ListNode *pHead)
//{
//      if (pHead)
//	{
//		  if (pHead->_next)
//		  {
//			  PrintListReverse(pHead->_next);
//		  }
//		cout << pHead->_data << " ";
//	}
//}

int main()
{
	ListNode* pHead=new ListNode(1);
	ListNode* n1 = new ListNode(2);
	ListNode* n2=new ListNode(3);
	ListNode* n3 = new ListNode(4);
	ListNode* n4 = new ListNode(5);
	pHead->_next = n1;
	n1->_next = n2;
	n2->_next = n3;
	n3->_next = n4;
	PrintListReverse(pHead);
	getchar();
	return 0;
}