#define _CRT_SECURE_NO_WARNINGS
#include "SharedPtr.h"
#include<memory>
struct Node
{
	weak_ptr<Node> _next;
	weak_ptr<Node> _prev;
	/*shared_ptr<Node> _next;
	shared_ptr<Node> _prev;*/
	~Node()
	{
		cout << "delete" << endl;
	}

};
void test_shared_ptr()
{
	shared_ptr<Node> cur(new Node());
	shared_ptr<Node> next(new Node());
	cur->_next = next;
	next->_prev = cur;

}
void TestSharedPtr()
{
	SharedPtr<int> sp1(new int(1));
	/*SharedPtr<int> sp2(sp1);
	SharedPtr<int, Free> sp3((int *)malloc(sizeof(int)*10));
	FILE* pf = fopen("test.txt", "w");
	SharedPtr<FILE, Fclose> sp(pf);*/


}
int main()
{
	test_shared_ptr();
	getchar();
	return 0;
}