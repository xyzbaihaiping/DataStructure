#define _CRT_SECURE_NO_WARNINGS
#include"D_SeqList.h"
void Test1()
{
	SeqList mylist;
	InitSeqList(&mylist);
	PushFront(&mylist, 5);
	PushFront(&mylist, 5);
	PushFront(&mylist, 4);
	PrintSeqList(mylist);
}
int main()
{
	Test1();
	system("pause");

}