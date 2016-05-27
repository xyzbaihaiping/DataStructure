#include"HashTableBucket.h"
void TestInt()
{
	HashTable<int, int> tab(10);
	tab.Insert(51,51);
	tab.Insert(105,105);
	tab.Insert(52,52);
	tab.Insert(3,3);
	tab.Insert(55,55);
	tab.Insert(2,2);
	tab.Insert(106,106);
	tab.Insert(53,53);
	tab.Insert(0,0);
	/*for (int i = 0; i < 53; i++)
	{
		tab.Insert(i,i);
	}
	tab.Insert(54,54);*/
	tab.Print();
	//HashTable<int, int> ht(tab);
	HashTable<int, int> ht(tab);
	ht = tab;
    /*HashTableNode<int,int>* node=tab.Find(54);
	cout << node->_key << " " << node->_value << endl;*/
	cout << ":------------" << endl;
	/*tab.Remove(0);
	tab.Print();*/
	ht.Print();

}
int main()
{
	TestInt();
	getchar();
	return 0;
}