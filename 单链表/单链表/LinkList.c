#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"
void InitLinkList(pList* pHead)//单链表的初始化
{
	assert(pHead);
	*pHead = NULL;
}


void Destroy(pList *pHead)//销毁（动态开辟的内存释放）
{
	assert(pHead);
	pLinkNode del = NULL;
	pLinkNode cur = *pHead;
	while (*pHead)
	{
		del = *pHead;
		*pHead = (*pHead)->next;
		free(del);
		del = NULL;
	}
}


pLinkNode BuyNode(DataType x)//创建新节点
{
	pLinkNode NewNode = (pLinkNode)malloc(sizeof(LinkNode));
	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}


void PushBack(pList* pHead, DataType x)
{
    assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode NewNode=BuyNode(x);

	if (cur == NULL)
	{
		*pHead = NewNode;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = NewNode;
	}
}


void PrintList(pList list)
{
	pLinkNode cur = list;
	printf("list is: ");
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}


void PopBack(pList* pHead)
{
	assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode del = NULL;
	if (cur == NULL)
	{
		return;
	}
	else if (cur->next == NULL)
	{
		free(cur);
		*pHead = NULL;
	}
	else
	{
		while (cur->next->next)
		{
			cur = cur->next;
		}
		del = cur->next;
		cur->next = NULL;
		free(del);
		del = NULL;
	}
}


void PushFront(pList* pHead, DataType x)
{
	assert(pHead);
	pLinkNode NewNode = BuyNode(x);
	pLinkNode cur = *pHead;

	if (cur == NULL)
	{
		*pHead = NewNode;
	}
	else
	{
		NewNode->next = *pHead;
		*pHead = NewNode;
	}
}


void PopFront(pList* pHead)
{
	assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode del = cur;
	if (cur == NULL)
	{
		return;
	}
	else
	{
		*pHead = cur->next;
		free(del);
		del = NULL;
	}
}


int GetListLength(pList head)
{
	
	int count = 0;
	pLinkNode cur = head;
	
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}


pLinkNode Find(pList head, DataType x)
{
	pLinkNode cur = head;
	
	while (cur)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}


void Insert(pList *pHead, pLinkNode pos, DataType x)
{
	assert(pHead);
	assert(pos);
	pLinkNode cur = *pHead;
	pLinkNode NewNode = BuyNode(x);

	if (cur ==pos)
	{
		NewNode->next = cur;
		*pHead = NewNode;
	}
	else
	{
		while (cur->next!=pos)
		{
			cur = cur->next;
		}
		NewNode->next =cur->next;
		cur->next = NewNode;
	}
}


void Remove(pList *pHead, DataType x)
{
	assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode prev = NULL;
	pLinkNode del = NULL;
	while (cur)
	{
		if (cur->data == x)
		{	
			del = cur;
			if (cur == *pHead)
			{
				*pHead = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			free(del);
			del = NULL;
			break;
		}
		prev = cur;
		cur = cur->next;
	}
}


void Erase(pList *pHead, pLinkNode pos)
{
	assert(pHead);
	assert(pos);
	pLinkNode cur = *pHead;
	pLinkNode del = cur;
	pLinkNode prev = NULL;
	while (cur)
	{
		del = cur;
		if (cur == pos)
		{
			if (cur == *pHead)
			{
				*pHead = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			free(del);
			del = NULL;
			break;
		}
		prev = cur;
		cur = cur->next;
	}
}


void RemoveAll(pList *pHead, DataType x)
{
	assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode prev = NULL;
	pLinkNode del = NULL;
	while (cur)
	{
		if (cur->data == x)
		{
			del = cur;
			if (cur == *pHead)
			{
				*pHead = cur->next;
				cur = *pHead;
			}
			else
			{
				prev->next = cur->next;
				cur = prev->next;
			}
			free(del);
			del = NULL;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}



//链表常见的面试题
//删除非尾节点-----1
void EraseNotTail(pLinkNode pos)
{
	assert(pos);
	pLinkNode del = NULL;

	pos->data = pos->next->data;
	del = pos->next;
	pos->next = pos->next->next;
	free(del);
    del = NULL;
}
//反转（逆序）链表--2
void ReverseList(pList* pHead)
{
	assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode prev = NULL;
	pLinkNode NewHead = NULL;

	while (cur)
	{
		prev = cur;
		cur = cur->next;
		prev->next = NewHead;
		NewHead = prev;
	    
	}
	*pHead = NewHead;
}
//排序链表（冒泡）--3
void BubbleSort(pList * pHead)
{
	assert(pHead);
	pLinkNode cur = *pHead;
	pLinkNode end = NULL;
	DataType tmp = 0;

	while (cur != end)
	{
		while (cur && cur->next != end)
		{
			if (cur->data > cur->next->data)
			{
				tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
			}
			cur = cur->next;
		}
		end = cur;
		cur = *pHead;
	}
}

// 在当前节点前插入一个数据x-----5
void InsertFrontNode(pLinkNode pos, DataType x)
{
	assert(pos);
	pLinkNode NewNode = BuyNode(x);
	DataType tmp = 0;
	NewNode->next = pos->next;
	pos->next = NewNode;

	tmp = NewNode->data;
	NewNode->data = pos->data;
	pos->data = tmp;
}
//合并两个有序链表-----6
pLinkNode Merge(pList l1, pList l2)
{

	pList NewHead = NULL;
	pLinkNode cur = NULL;

	//if (l1 == l2)
	//{
	//	return l1;
	//}
	//if (l1 == NULL && l2 != NULL)
	//{
	//	return l2;
	//}
	//if (l1 != NULL && l2 == NULL)
	//{
	//	return l1;
	//}
	if (l1 == NULL || l2 == NULL)
	{
		if (l1)
			return l1;
		else
	        return l2;
		
	}
	if (l1->data < l2->data)
	{
		NewHead = l1;
		l1 = l1->next;
	}
	else
	{
		NewHead = l2;
		l2 = l2->next;
	}
	cur = NewHead;
	while (l1 && l2)
	{
		if (l1->data < l2->data)
		{
			cur->next = l1;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	if (l1)
	{
		cur->next = l1;
	}
	else
	{
		cur->next = l2;
	}
	return NewHead;
}
pLinkNode _Merge(pList l1, pList l2)
{

	pList NewHead = NULL;
	pLinkNode cur = NULL;

	if (l1 == NULL || l2 == NULL)
	{
		if (l1)
			return l1;
		else
			return l2;

	}
	if (l1->data < l2->data)
	{
		NewHead = l1;
		NewHead->next = _Merge(l1->next, l2);
	}
	else
	{
		NewHead = l2;
		NewHead->next = _Merge(l1, l2->next);
	}
	return NewHead;
}

//查找链表的中间节点---7
pLinkNode FindMidNode(pList head)
{
	pLinkNode fast = head;
	pLinkNode slow = head;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
//约瑟夫环
pLinkNode JoseCycle(pList *pHead, int num)
{
	assert(pHead);

	pLinkNode cur = *pHead;
	pLinkNode del = NULL;
	int count = 0;

	while (1)
	{
		count = num;
		if (cur == cur->next->next) //当前节点的后一个节点的next是当前节点时，结束循环
		{
			break;
		}	
			while (--count)    //找到第num个元素
			{
				cur = cur->next;
			}
			del = cur->next;
			cur->data = cur->next->data;
			cur->next = cur->next->next;
			free(del); //删除第num个元素
			del == NULL;
	}
	*pHead = cur;
	return cur;
}
// 删除单链表的倒数第k个节点(k > 1 && k < 链表的总长度)----9
// 时间复杂度O(N)
void DelKNode(pList *pHead, int k)
{
	assert(k > 1);

	pLinkNode l1 = *pHead;
	pLinkNode l2 = *pHead;
	pLinkNode del = NULL;

	while (--k && l2->next) 
	{
		l2 = l2->next;
	}
	if (l2->next == NULL) //k>=链表总长度
	{
		return;
	}
	while (l2->next)
	{
		l2 = l2->next;
		l1 = l1->next;
	}
		del = l1->next;
		l1->data = l1->next->data;
		l1->next = l1->next->next;
		free(del);
		del = NULL;
}

// 判断链表是否带环 ,若带环返回相遇节点，不带环返回NULL
pLinkNode CheckCycle(pList head)
{
	pLinkNode fast = head;
	pLinkNode slow = head;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return slow;
		}
	}
	return NULL;
}

//若链表带环则求环的长度
int GetCircleLength(pLinkNode meet)
{
	pLinkNode cur = meet;
	int count = 0;

	do
	{
		cur = cur->next; 
		count++;
	} while (cur != meet);

	return count;
}

//获取环入口点
pLinkNode GetCycleEntryNode(pList head, pLinkNode MeetNode)
{
	pLinkNode Entry= head;
	pLinkNode meet = MeetNode;

	while (meet != Entry)
	{
		Entry = Entry->next;
		meet = meet->next;
	}
	return Entry;
}
pLinkNode _GetCycleEntryNode(pList head, pLinkNode MeetNode)//链表带环转化为链表相交问题获取入口
{
	pLinkNode Entry = head;
	pLinkNode meet = MeetNode->next;
	int len_head = 0;
	int len_meet = 0;
	int len = 0;

	while (Entry != MeetNode) //求链表长度
	{
		len_head++;
		Entry = Entry->next;
	}
	while (meet != MeetNode)//求链表长度
	{
		len_meet++;
		meet = meet->next;
	}

	 Entry = head;
	 meet = MeetNode->next;

	if (len_head > len_meet)  
	{
		len = len_head - len_meet;
		while (len--)
		{
			Entry = Entry->next;
		}//较长链表先走len=|len_l1 - len_l2|步
	}
	else
	{
		len = len_meet - len_head;
		while (len--)
		{
			meet = meet->next;
		}//较长链表先走len=|len_l1 - len_l2|步
	}

	while (meet != Entry)
	{
		Entry = Entry->next;
		meet = meet->next;
	} //两指针同时走，相遇节点就是环入口点
	return Entry;
}



// 判断两个链表是否相交，假设两个链表都不带环。
int CheckCross(pList list1, pList list2)
{
	pLinkNode l1 = list1;
	pLinkNode l2 = list2;

	if (l1 == NULL || l2 == NULL)
	{
		return 0;
	}
	while (l1->next) 
	{
		l1 = l1->next;
	} //遍历l1链表至链表末尾
	while (l2->next)
	{
		l2 = l2->next;
	}//遍历l2链表至链表末尾
	if (l1 == l2) //判断两链表最后的一个节点是否相同，相同则相交返回1
	{
		return 1;
	}
	else
		return 0;//不同则返回0
}
// 求链表的交点，长链表先走n步（n为两链表的长度差），然后再一起走，第一个相遇点则为交点。
pLinkNode LinkCrossNode(pList list1, pList list2)
{
	int len_l1=0;
	int len_l2 = 0;
	int len = 0;
	pLinkNode l1 = list1;
	pLinkNode l2 = list2;
	pLinkNode longlink = NULL;
	pLinkNode shortlink = NULL;
	while (l1)
	{
		len_l1++;
		l1 = l1->next;
	}//记录第一个链表长度
	while (l2)
	{
		len_l2++;
		l2 = l2->next;
	}//记录第二个链表长度

	if (len_l1 > len_l2)
	{
		len = len_l1 - len_l2;
	  while (len--)
	  {
			list1 = list1->next;
	  }//较长链表先走len = |len_l1 - len_l2|步
	}
	else
	{
		len = len_l2 - len_l1;
		while (len--)
		{
			list2 = list2->next;
		}//较长链表先走len = |len_l1 - len_l2|步
	}
	
	while (list1!= list2)//两指针同时走，相遇点就是两个链表的交点
	{
		list1 = list1->next;
		list2 = list2->next;
	}
	return list1;
}
//从尾到头打印链表
