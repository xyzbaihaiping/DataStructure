#pragma once

#include<iostream>
using namespace std;

template<class T>
class SymmetricMatrix
{
public:
	SymmetricMatrix(const T* a, size_t size, size_t n)//构造函数，压缩存储矩阵元素
	:_a(new T[n*(n + 1) / 2])//开辟空间，下三角元素一共有（n*(n + 1) / 2）个
	, _size(n*(n + 1) / 2)//设置一维数组大小
	, _n(n)//矩阵大小（维数）
	{
		int index = 0;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)//遍历
			{
				if (i >= j)   //若为下三角元素
					_a[index++] = a[i*n + j];//存储
				else;         //若不是下三角元素
					break      //直接跳出循环（此步骤优化，若不是下三角元素，则该行剩余元素一定也不是下三角元素）
			}
		}
	}
	~SymmetricMatrix()//析构函数
	{
		if (_a)
			delete[] _a;
	}
	T& Access(int i,int j)//访问元素
	{
		if (i < j)
			swap(i, j);
		return _a[i*(i + 1) / 2 + j];//根据对称矩阵和压缩存储的对应关系访问元素
	}
	void display()//还原打印矩阵
	{
		for (size_t i = 0; i < _n; i++)
		{
			for (size_t j = 0; j < _n; j++)
			{
				if (i >= j)//若要打印下三角元素，则直接根据对称矩阵和压缩存储的对应关系访问元素，打印
					cout << _a[i*(i + 1) / 2 + j] << " ";
				else      //若打印上三角元素，则交换元素行列（根据对称矩阵性质），就可以看做该元素是下三角元素并打印
					cout << _a[j*(j + 1) / 2 + i] << " ";
			}
			cout << endl;
		}
	}
protected:
	T* _a;
	size_t _size;
	size_t _n;
};
