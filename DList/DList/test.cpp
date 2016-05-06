#include "DList.h"
void Test1()
{
	DList dlist;
	dlist.PushBack(1);
	dlist.PushBack(2);
	dlist.PushBack(3);
	dlist.PushBack(4);
	//dlist.PopBack();
	//cout << dlist << endl;
	//dlist.PopBack();
	//dlist.PopBack();
	//cout << dlist << endl;
	//dlist.PopBack();

	cout << dlist << endl;
	dlist.Reverse();
	cout << dlist << endl;
}
void Test2()
{
	DList dlist;
	dlist.PushFront(1);
	dlist.PushFront(2);
	dlist.PushFront(4);
	dlist.PushFront(3);
	dlist.PushFront(5);
	cout << dlist << endl;
	
	//dlist.Insert(dlist.Find(1), 5);
	dlist.Erase(dlist.Find(5));
	/*dlist.PopFront();
	dlist.PopFront();
	cout << dlist << endl;
	dlist.PopFront();
	dlist.PopFront();
	cout << dlist << endl;*/
/*
	dlist.PopFront();*/
	/*dlist.Reverse();*/
	/*dlist.RemoveAll(4);*/
	cout << dlist << endl;
}
int main()
{
	Test2();
	getchar();
	return 0;
}