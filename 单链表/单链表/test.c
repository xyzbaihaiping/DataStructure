#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"

void Test1()
{
	pList mylist;
	InitLinkList(&mylist);
	PushBack(&mylist,1);
	PushBack(&mylist, 2);
	PushBack(&mylist, 3); 
	printf("list is:");
	PrintList(mylist);
}
void Test2()
{
	pList mylist;
	InitLinkList(&mylist);
	PushBack(&mylist, 1);
	PushBack(&mylist, 1);
	PushBack(&mylist, 1);
	PushBack(&mylist, 1);
	printf("list is:");
	PrintList(mylist);
	PopBack(&mylist);
	printf("list is:");
	PrintList(mylist);
	PopFront(&mylist);
	printf("list is:");
	PrintList(mylist);
}
void Test3()
{
	pList mylist;
	InitLinkList(&mylist);
	PushFront(&mylist, 4);
	PushFront(&mylist, 5);
	PushFront(&mylist, 6);
	PushFront(&mylist, 7);
	PrintList(mylist);
	Destroy(&mylist);
	PrintList(mylist);
}
	void Test4()
{
	pList mylist;
	InitLinkList(&mylist);
	PushFront(&mylist, 4);//546781
	PushFront(&mylist, 5);
	PushBack(&mylist, 8);
	PushBack(&mylist, 1);
	printf("list is:");
	PrintList(mylist);
	printf("linklist length is %d ",GetListLength(mylist));
}
void Test5()
{
		pList mylist;
		InitLinkList(&mylist);
		PushFront(&mylist, 4);//546781
		PushFront(&mylist, 5);
		PushBack(&mylist, 8);
		PushBack(&mylist, 1);
		printf("list is:");
		PrintList(mylist);
		printf("linklist length is %d ", GetListLength(mylist));
	}
void Test6()
{
	pList mylist;
	InitLinkList(&mylist);
	PushFront(&mylist, 4);
	PushFront(&mylist, 5);
	PushBack(&mylist, 8);
	PushFront(&mylist, 4);
	PushBack(&mylist, 8);
	PushFront(&mylist, 5);
	PrintList(mylist);
	pLinkNode pos = Find(mylist, 8);
	Erase(&mylist, pos);
	pLinkNode pos1 = Find(mylist, 8);
	Erase(&mylist, pos1);
	/*RemoveAll(&mylist, 5);*/
	PrintList(mylist);
}
void Test7()
{
	pList mylist;
	InitLinkList(&mylist);
	PushFront(&mylist, 4);
	PushFront(&mylist, 5);
	PushBack(&mylist, 8);
	PrintList(mylist);
	pLinkNode pos= Find(mylist, 5);
	EraseNotTail(pos);
	PrintList(mylist);
}
void Test8()
{
	pList mylist;
	InitLinkList(&mylist);
	PushFront(&mylist, 4);
	PushFront(&mylist, 5);
	PushFront(&mylist, 6);
	PrintList(mylist);
	ReverseList(&mylist);
	PrintList(mylist);
}
void Test9()
{
	pList mylist;
	InitLinkList(&mylist);
	PushFront(&mylist, 4);
	PushFront(&mylist, 5);
	PushFront(&mylist, 6);
	PrintList(mylist);
	BubbleSort(&mylist);
	PrintList(mylist);
}
void Test10()
{
	pList mylist;
	InitLinkList(&mylist);
	PushFront(&mylist, 4);
	PushFront(&mylist, 5);
	PushBack(&mylist, 8);
	PrintList(mylist);
	pLinkNode pos = Find(mylist, 5);
	InsertFrontNode(pos, 7);
	PrintList(mylist);
}
void Test11()
{
	pList l1;
	InitLinkList(&l1);
	PushFront(&l1, 10);
	PushFront(&l1, 8);
	PushFront(&l1, 6);
	PushFront(&l1, 3);
	pList l2;
	InitLinkList(&l2);
	PushFront(&l2, 9);
	PushFront(&l2, 7);
	PushFront(&l2, 4);
	PushFront(&l2, 2);
	pLinkNode head=_Merge(l1, l2);
	PrintList(head);
}
void Test12()//查找链表中间节点
{
	pList l1;
	InitLinkList(&l1);
	PushFront(&l1, 10);
	PushFront(&l1, 8);
	PushFront(&l1, 6);
	PushFront(&l1, 3);
	PushFront(&l1, 6);
	PrintList(l1);
	pLinkNode pos=FindMidNode(l1);
	printf("%d\n", pos->data);
}
void Test13() //约瑟夫环
{
	pList l1;
	int i = 0;
	InitLinkList(&l1);
	for (i = 1; i <= 41; i++)
	{
		PushBack(&l1, i);
	}
	pLinkNode pos = Find(l1,41);
	pos->next = l1;
	pos=JoseCycle(&l1,3);
	printf(" %d \n", pos->data);
	printf(" %d \n", pos->next->data);

}
void Test14()//删除链表倒数第K个节点
{
	pList l1;
	InitLinkList(&l1);
	PushFront(&l1, 10);
	PushFront(&l1, 8);
	PushFront(&l1, 6);
	PushFront(&l1, 3);
	PushFront(&l1, 6);
	PrintList(l1);
	DelKNode(&l1,6);
	PrintList(l1);

}
void Test15() // 判断链表是否带环, 若链表带环则求环的长度和相遇节点，不带环返回-1
{
	pList l1;
	int i = 0;
	pLinkNode entry = NULL;
	InitLinkList(&l1);
	for (i = 1; i <= 7; i++)
	{
		PushBack(&l1, i);
	}
	pLinkNode pos1 = Find(l1, 4);
	pLinkNode pos2 = Find(l1, 7);
	pos2->next = pos1;
	pLinkNode pos = CheckCycle(l1);
	printf("%d\n", pos->data);
	printf("length = %d\n",GetCircleLength(pos));
	entry = _FindEntryNode(l1, pos);
	printf("entry = %d\n", entry->data);
}
void Test16() // 判断链表相交问题
{
	pList l1;
	pList l2;
	int i = 0;
	InitLinkList(&l1);
	InitLinkList(&l2);

	for (i = 1; i <= 7; i++)
	{
		PushBack(&l1, i);
	}
	for (i = 3; i <= 8; i++)
	{
		PushBack(&l2, i);
	}
	pLinkNode pos1 = Find(l1, 5);
	pLinkNode pos2 = Find(l2, 8);
	pos2->next = pos1;
	int ret=CheckCross(l1, l2);
	if (ret == 1)
	{
		printf("相交\n");
	}
	pLinkNode pos = LinkCrossNode(l1, l2);
	printf("%d\n", pos->data);
}
int main()
{
	Test2();
	system("pause");
}