#include "BitMap.h"
#include<iostream>
using namespace std;

void Test()
{
	BitMap<int> map(100);
	map.Set(10);
	map.Set(99);
	map.Set(30);
	cout << "10?" << map.Test(10) << endl;
	cout << "99?" << map.Test(99) << endl;
	cout << "30?" << map.Test(30) << endl;
	map.ReSet(99);
	cout << "99?" << map.Test(99) << endl;

}
int main()
{
	Test();
	getchar();
	return 0;
}