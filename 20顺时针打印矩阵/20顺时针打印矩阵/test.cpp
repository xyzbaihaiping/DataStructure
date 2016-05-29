#include<iostream>
#include<assert.h>
using namespace std;


void PrintMatriaInCircle(int (*a)[4], int row, int col, int start)
{

	int endX = row - start - 1;
	int endY = col - start - 1;


	for (int i = start; i <= endY; i++)
	{
		printf("%d ", a[start][i]);
	}

	if (endX > start)
	{
		for (int i = start + 1; i <= endX; i++)
		{
			printf("%d ", a[i][endY]);
		}
	}
	if (endY > start)
	{
		for (int i = endY - 1; i >= start; i--)
		{
			printf("%d ", a[endX][i]);
		}
	}
	if (endX > start)
	{
		for (int i = endX - 1; i>start; i--)
		{
			printf("%d ", a[i][start]);
		}
	}

}
void PrintMatria(int(*a)[4], int row, int col)
{
	assert(a);
	if (row <= 0 || col <= 0)
		return;
	
	int start = 0;
	if (col > start * 2 && row > start * 2)
	{
		PrintMatriaInCircle(a,row,col,start);
		++start;
	}
}


int main()
{
	int a[5][3] = {
		1,2,3,
		4,5,6,
		7,8,9,
		1,2,3,
		4,5,6,
	};
	int b[4][5] = {
		1, 2, 3,4,5,
		4, 5, 6,7,8,
		7, 8, 9,8,9,
		1, 2, 3,7,6,

	};
	int c[3][4] = {
		1, 2, 3, 4, 
		4, 5, 6, 7,
		7, 8, 9, 8,
	};
	PrintMatria(c, 3, 4);
	getchar();
	return 0;
}