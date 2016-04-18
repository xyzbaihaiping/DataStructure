#define _CRT_SECURE_NO_WARNINGS
#include "GeneralizedList.h"

void TestGeneralized()
{
	char str[] = "(a,b,c,(d,e),(f,(g,(()),h),i))";
	Generalized g1(str);
	g1.Print();
	
	cout << endl;
	cout << g1.Depth() << endl;
	cout << g1.Size() << endl;
	Generalized g2(g1);
	g2.Print();
	cout << endl;
	Generalized g3;
	g3 = g1;
	g3.Print();

}

int main()
{
	TestGeneralized();
	getchar();
	return 0;
}