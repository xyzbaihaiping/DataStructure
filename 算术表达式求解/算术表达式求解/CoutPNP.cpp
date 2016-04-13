#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

enum Type
{
	OP_NUM,
	OP_SYMBOL
};
enum SYMBOL
{
	ADD,
	SUB,
	MUL,
	DIV
};

struct Cell
{
	Type _type;
	int value;
};
int CountPNP(Cell *a, int size)
{
	assert(a);
	stack<int> s;
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i]._type == OP_NUM)
		{
			s.push(a[i].value);
		}
		else
		{
			int right = s.top();
			s.pop();
			int left = s.top();
			s.pop();
			switch (a[i].value)
			{
			case ADD:
				s.push(left + right);
				break;
			case SUB:
				s.push(left - right);
				break; 
			case MUL:
				s.push(left *right);
				break; 
			case DIV:
				s.push(left / right);
				break;
			default:
				break;
			}
		}
	}
	return s.top();
}
int main()
{
	Cell a[] = {
		{OP_NUM,12},
		{ OP_NUM,3}, 
		{ OP_NUM, 4 }, 
		{ OP_SYMBOL, ADD },
		{ OP_SYMBOL,MUL }, 
		{ OP_NUM, 6 },
		{ OP_SYMBOL,SUB },
		{ OP_NUM, 8 }, 
		{ OP_NUM, 2 },
		{ OP_SYMBOL, DIV },
		{ OP_SYMBOL, ADD }
	};
	int size = sizeof(a) / sizeof(a[0]);
	cout << CountPNP(a, size) << endl;
	getchar();
	return 0;
}