#pragma once
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

struct Pos
{
	int _row; //行
	int _col;//列
};

bool CheckPath(int *a, Pos next, int n);//检查路径是否合法（边界、通路）
void GetMaze(int *a, int n);//获得地图
void PrintMaze(int *a, int n);//打印地图
bool MazePath(int *a, int n, Pos entry, stack<Pos>& path);
