#include "SList.h"

void Test1()
{
	SList slist;
	slist.PushBack(4);
	slist.PushBack(2);
	slist.PushBack(4);
	slist.PushBack(3);
	slist.PushBack(4);
	/*slist.PopBack();
	cout << slist << endl;
	slist.PopBack();
	cout << slist << endl;
	slist.PopBack();*/
	cout << slist << endl;
	/*slist.Reverse();
	cout << slist << endl;*/
	//slist.Remove(4);
	//cout << slist << endl;

	/*slist.RemoveAll(4);*/
	cout << slist << endl;


}
void Test2()
{
	SList slist;
	slist.PushFront(5);
	slist.PushFront(4);
	slist.PushFront(3);
	slist.PushFront(2);
    //cout << slist << endl;
	/*Node* pos=slist.Find(5);*/
	/*slist.Insert(pos, 5);*/
	/*slist.Erase(pos);
	cout << slist << endl;*/
	//slist.Sort();
	//cout << slist << endl;
	/*SList slist1=slist;*/
	//slist.EraseNotTail(slist.Find(5));
	
	/*slist.InsertFrontNode(slist.Find(6),3);*/
   /*   SList slist1(slist);
	  cout << slist << endl;*/

	/* slist.Merge(slist1);*/
    // Node* mid=slist.FindMidNode();
       //slist.DelKNode(2);
  
	 cout << slist<< endl;
}
void Test3()
{
	SList slist;
	slist.PushFront(1);
	slist.PushFront(2);
	slist.PushFront(3);
	slist.PushFront(4);
	slist.PushFront(5);
	slist.PushFront(6);
	slist.PushFront(7);
	slist.PushFront(8);
	cout << slist << endl; 
	Node* pos = slist.Find(1);
	Node* pos1 = slist.Find(4);
	pos->_next = pos1;
	Node *ret=slist.CheckCycle();
	cout << ret->_data<<endl;
	/*int len=slist.GetCircleLength(ret);
	cout << len << endl;*/
	Node* entry=slist.FindEntryNMeetNodeode(ret);
	cout << entry->_data << endl;
	/*int i = 0;
	for (i = 0; i <= 41; i++)
	{
		slist.PushBack(i);
	}
	Node *pos = slist.Find(41);
	Node *ret = slist.Find(0);
	pos->_next = ret;
	Node *pos1=slist.JoseCycle(3);
	cout << pos1->_data << " " << pos1->_next->_data;*/
}
int main()
{
	Test3();
	getchar();
	return 0;
}