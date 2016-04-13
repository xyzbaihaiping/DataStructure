#include "Maze.h"
int const n = 10;

void TestMaze()
{
	int a[n][n] = {};
	GetMaze((int *)a, n);
	PrintMaze((int *)a, n);
	stack<Pos> path;
	Pos entry = { 2, 0 };
    bool ret = MazePath((int *)a, n, entry, path);
	cout << "是否有通路" << ret << endl;

	PrintMaze((int *)a, n);

}
int main()
{
	TestMaze();
	getchar();
	return 0;
}