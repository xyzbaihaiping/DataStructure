#define _CRT_SECURE_NO_WARNINGS
#include "ComplexList.hpp"
void Test()
{
	ComplexList<int> cl;
	cl.PushBack(1);
	cl.PushBack(2);
	cl.PushBack(3);
	cl.PushBack(4);
	cl.PushBack(5);
	cl.Print();
	ComplexNode<int>* n1 = cl.Address(1);
	ComplexNode<int>* n2 = cl.Address(2);
	ComplexNode<int>* n3 = cl.Address(3);
	ComplexNode<int>* n4 = cl.Address(4);
	ComplexNode<int>* n5 = cl.Address(5);
	n1->_random = n2;
	n2->_random = n1;
	n3->_random = n5;
	n4->_random = NULL;
	cl.Print();
	ComplexList<int> c2;
	c2 = cl;
	c2.Print();
	cl.Print();
}
int main()
{
	Test();
	getchar();
	return 0;
}