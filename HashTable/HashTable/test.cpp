#include<iostream>
#include "HashTable.h"
void testInt()
{
	HashTable<int, int> table(10);
	table.Insert(89, 89);
	table.Insert(18, 18);
	table.Insert(49, 49);
	table.Insert(58, 58);
	table.Insert(9, 9);
	//table.Insert(45, 45);
	//table.Insert(2, 2);
	table.Print();
	HashTable<int, int> table1(table);
	table1.Print();
	bool ret = table.Find(9);
	cout << endl << ret << endl;
	table.Remove(9);
	table.Print();

}
void TestString()
{
	HashTable<string, string> table(10);
	table.Insert("dict", "×Öµä");
	table.Insert("hash", "¹þÏ£");
	table.Insert("function", "º¯Êý");
	table.Insert("abcd", "º¯Êý");
	table.Insert("dcba", "º¯Êý");

	table.Print();
	bool ret = table.Find("function");
	cout << endl << ret << endl;
	table.Remove("hash");
	table.Print();
}
int main()
{
	//testInt();
	TestString();
	getchar();
	return 0;
}