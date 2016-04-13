#define _CRT_SECURE_NO_WARNINGS
#include"D_SeqList.h"
void InitSeqList(pSeqList pseq)
{
	assert(pseq);
	pseq->list = (DataType *)malloc(CAPACITY * sizeof(DataType));
	memset(pseq->list, 0, sizeof(pseq->list));
	pseq->size = 0;
	pseq->capacity = CAPACITY;
}
void CheckCapacity(pSeqList pseq)
{
	assert(pseq);
	if (pseq->size == pseq->capacity)
	{
		if (pseq->capacity + INC_CAPACITY < MAX)
		{
			pseq->list = realloc(pseq->list, (pseq->capacity + INC_CAPACITY)*sizeof(DataType));
			pseq->capacity += INC_CAPACITY;
		}
		else if (pseq->capacity<MAX && (pseq->capacity + INC_CAPACITY)>MAX)
		{
			pseq->list = realloc(pseq->list, MAX*sizeof(DataType));
			pseq->capacity = MAX;
		}
	}
}
void PrintSeqList(SeqList seq)
{
	int i = 0;
	for (i = 0; i < seq.size; i++)
	{
		printf("%d ", seq.list[i]);
	}
}
void PushBack(pSeqList pseq, DataType x)
{
	CheckCapacity(pseq);
	if (pseq->size == MAX)
	{
		printf("顺序表已满\n");
		return;
	}
	CheckCapacity(pseq);
	pseq->list[pseq->size] = x;
	pseq->size++;
}
void PopBack(pSeqList pseq)
{
	if (pseq->size == 0)
	{
		printf("顺序表为空\n");
	}
	else
	{
		pseq->size--;
	}
}
void PushFront(pSeqList pseq, DataType x)
{
	int i = 0;
	if (pseq->size == MAX)
	{
		printf("顺序表已满\n");
		return;
	}
	CheckCapacity(pseq);
	for (i = pseq->size; i > 0; i--)
	{
		pseq->list[i] = pseq->list[i - 1];
	}
	pseq->list[0] = x;
	pseq->size++;
}
void PopFront(pSeqList pseq)
{
	int i = 0;
	if (pseq->size == 0)
	{
		printf("顺序表为空\n");
	}
	else
	{
		for (i = 0; i < pseq->size; i++)
		{
			pseq->list[i] = pseq->list[i + 1];
		}
		pseq->size--;
	}
}
void Insert(pSeqList pseq, int pos, DataType x)
{
	int i = 0;
	if (pseq->size == MAX)
	{
		printf("顺序表已满\n");
		return;
	}
	CheckCapacity(pseq);
	for (i = pseq->size; i > pos; i--)
	{
		pseq->list[i] = pseq->list[i - 1];
	}
	pseq->list[pos] = x;
	pseq->size++;
	
}
int Find(SeqList Seq, int pos, DataType x)
{
	int i = 0;
	for (i = pos; i < Seq.size; i++)
	{
		if (Seq.list[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void Remove(pSeqList pseq, DataType x)
{
	int i = 0;
	int pos = Find(*pseq, 0, x);
	if (pos != -1)
	{
		for (i = pos; i < pseq->size; i++)
		{
			pseq->list[i] = pseq->list[i + 1];
		}
		pseq->size--;
	}
	else
		printf("not exit\n");
}
void RemoveAll(pSeqList pseq, DataType x)
{
	int pos = 0;
	int i = 0;
	pos = Find(*pseq, pos, x);
	if (pos == -1)
	{
		printf("not exit\n");
		return;
	}
	while (pos != -1)
	{
		for (i = pos; i < pseq->size; i++)
		{
			pseq->list[i] = pseq->list[i + 1];
		}
		pseq->size--;
		pos = Find(*pseq, pos, x);
	}
}
void ReverseList(pSeqList pSeq)
{
	int start = 0;
	int end = pSeq->size - 1;
	int tmp = 0;

	while (start < end)
	{
		tmp = pSeq->list[start];
		pSeq->list[start] = pSeq->list[end];
		pSeq->list[end] = tmp;
		start++;
		end--;
	}
}
void SortSeqList(pSeqList pseq)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int flag = 0;

	for (i = 0; i < pseq->size; i++)
	{
		flag = 0;
		for (j = 0; j < pseq->size - i - 1; j++)
		{

			if (pseq->list[j] > pseq->list[j + 1])
			{
				tmp = pseq->list[j];
				pseq->list[j] = pseq->list[j + 1];
				pseq->list[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
int BinarySearch(pSeqList pseq, DataType x)
{

	int left = 0;
	int right = pseq->size - 1;

	while (left <= right)
	{
		int mid = left - ((left - right) >> 1);
		if (pseq->list[mid] > x)
		{
			right = mid - 1;
		}
		else if (pseq->list[mid] < x)
		{
			left = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}
