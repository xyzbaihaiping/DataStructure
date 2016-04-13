#ifndef __D_SEQLIST_H__
#define __D_SEQLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX 6
#define INC_CAPACITY 3
#define CAPACITY 3

typedef int DataType;

typedef  struct SeqList
{
	DataType *list;
	int size;
	int capacity;
}SeqList, *pSeqList;

void InitSeqList(pSeqList pseq);
void PrintSeqList(SeqList seq);
void PushBack(pSeqList pseq, DataType x);
void PopBack(pSeqList pseq);
void PushFront(pSeqList pseq, DataType x);
void PopFront(pSeqList pseq);
void Insert(pSeqList pseq, int pos, DataType x);
void Remove(pSeqList pseq, DataType x);
void RemoveAll(pSeqList pseq, DataType x);
int Find(SeqList Seq, int pos, DataType x);
void ReverseList(pSeqList Seq);
void SortSeqList(pSeqList pseq);
int BinarySearch(pSeqList pseq, DataType x);





#endif