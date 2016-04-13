#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct LinkNode
{
	DataType data;
	struct LinkNode *next;
}LinkNode, *pLinkNode, *pList;

void InitLinkList(pList* pHead);//单链表的初始化
void Destroy(pList *pHead);//销毁（动态开辟的内存释放）
void PushBack(pList* pHead, DataType x);//尾插
void PopBack(pList* pHead);//尾删
void PushFront(pList* pHead, DataType x);//头插
void PopFront(pList* pHead);//头删
void PrintList(pList list);//打印单链表的元素

int GetListLength(pList head);//获取单链表的长度
pLinkNode Find(pList head, DataType x);//查找元素
void Insert(pList *pHead, pLinkNode pos, DataType x);//插入元素
void Remove(pList *pHead, DataType x);//删除指定元素
void RemoveAll(pList *pHead, DataType x);//删除单链表中所有指定元素
void Erase(pList *pHead, pLinkNode pos);//按位置删除


//链表常见的面试题
//删除非尾节点-----1
void EraseNotTail(pLinkNode pos);
//反转（逆序）链表--2
void ReverseList(pList* pplist);
//排序链表（冒泡）--3
void BubbleSort(pList * pplist);

// 在当前节点前插入一个数据x-----5
void InsertFrontNode(pLinkNode pos, DataType x);

//合并两个有序列表-----6
pLinkNode Merge(pList l1, pList l2);


//查找链表的中间节点---7
pLinkNode FindMidNode(pList head);

//约瑟夫环
pLinkNode JoseCycle(pList *pHead, int num);

// 删除单链表的倒数第k个节点(k > 1 && k < 链表的总长度)----9
// 时间复杂度O(N)
void DelKNode(pList *pHead, int k);

// 【链表带环问题】-----10
// 判断链表是否带环 ,若带环返回相遇节点，不带环返回NULL
pLinkNode CheckCycle(pList pList);
//若链表带环则求环的长度
int GetCircleLength(pLinkNode meet);
//获取环入口点
pLinkNode FindEntryNMeetNodeode(pList head, pLinkNode MeetNode);


// 【链表相交问题】
//
// 判断两个链表是否相交，假设两个链表都不带环。

int CheckCross(pList list1, pList list2);
// 求链表的交点，长链表先走n步（n为两链表的长度差），然后再一起走，第一个相遇点则为交点。
pLinkNode LinkCrossNode(pList list1, pList list2);

#endif//__LINKLIST_H__
