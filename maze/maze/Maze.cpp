#define _CRT_SECURE_NO_WARNINGS
#include "Maze.h"

bool CheckPath(int *a, Pos next, int n)
{
	if (next._col < n && next._col >= 0
		&& next._row >= 0 && next._row < n
		&& (a[next._row*n + next._col] == 0))//若行列都合法且该位置元素为0则为真
		return true;
	return false;
}
void GetMaze(int *a, int n)
{
	FILE* fout = fopen("MazeMap.txt", "r");//迷宫地图在放在当前目录下“MazeMap.txt”里
	assert(fout);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n;)
		{
			char ch = fgetc(fout);//读文件
			if ((ch == '0') || (ch == '1'))//若为0或1则放入数组
			{
				a[i*n + j] = ch - '0';
				j++;
			}
			else
			{
				continue;
			}
		}
	}
	fclose(fout);//关闭文件
}
void PrintMaze(int *a, int n)//打印迷宫
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i*n + j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}
bool MazePath(int *a, int n, Pos entry, stack<Pos>& path)//判断迷宫是否有通路
{
	Pos cur = entry;//将出口当做当前位置
	Pos next;
	path.push(cur);
	while (!path.empty())//若栈不为空
	{
		if (cur._col!=entry._col && cur._row!=entry._row
			&&( cur._col==n-1 || cur._col==0 || cur._row ==n-1 || cur._row ==0))
			//若该位置的行是最后一行，代表已走到出口位置
		{
			return true;
		}
		a[cur._row*n + cur._col] = 2;//将该位置置为2，代表已走过的路

		next = cur;
		next._col++;//若下一个位置是当前位置的右边
		if (CheckPath(a, next, n))//若下一个位置的值合法且为0(可以通)，则跳到下一个位置，且压栈
			//若不可以通那么就判断令一个方向的位置的值
		{
			cur = next;
			path.push(cur);
			continue;
		}

		next = cur;
		next._row++;
		if (CheckPath(a, next, n))//同理
		{
			cur = next;
			path.push(cur);
			continue;
		}
		next = cur;
		next._row--;
		if (CheckPath(a, next, n))//同理
		{
			cur = next;
			path.push(cur);

			continue;

		}
		next = cur;
		next._col--;
		if (CheckPath(a, next, n))//同理
		{
			cur = next;
			path.push(cur);
			continue;
		}
		cur = path.top();//当四周都不可以通则回退，将当前位置置为栈顶元素的坐标位置
		path.pop();//顶元素弹出

	}
	return false;//若栈为空，那么迷宫没有通路
}
