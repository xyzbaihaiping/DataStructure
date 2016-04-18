#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class T>
struct Triple
{
	Triple(const T& value=T(), size_t row=0, size_t col=0)
	:_value(value)
	, _row(row)
	, _col(col)
	{}
	T _value;
	size_t _row;
	size_t _col;
};
template<class T>
class SparseMatrix
{
public:
	SparseMatrix(size_t m, size_t n, const T& invaild)
		:_RowSize(n)
		, _ColSize(m)
		, _invaild(invaild)
	{}
	SparseMatrix(const T* a, size_t m, size_t n, const T& invaild)
	:_RowSize(m)
	, _ColSize(n)
	, _invaild(invaild)
	{
		int index = 0;
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (a[i*n + j] != _invaild)
				{
					_a.push_back(Triple<T>(a[i*n + j],i,j));
				}
			}
		}
	}
	void display()
	{
		int index = 0;
		for (size_t i = 0; i < _RowSize; i++)
		{
			for (size_t j = 0; j < _ColSize; j++)
			{
				if (index != _a.size() && _a[index]._row == i && _a[index]._col == j)
				{
					cout << _a[index++]._value << " ";
				}
				else
					cout << _invaild << " ";
			}
			cout << endl;
		}
	}
	SparseMatrix<T> Transport()
	{
		int index = 0;
		SparseMatrix<T> tmp(_RowSize, _ColSize, _invaild);
		for (size_t j = 0; j < _RowSize; j++)
		{
			for (size_t i = 0; i < _a.size(); i++)
			{
				if (_a[i]._col == j)
				{
					tmp._a.push_back(Triple<T>(_a[i]._value, _a[i]._col, _a[i]._row));
					index++;
				}
			}

		}
		return tmp;
	}
	SparseMatrix<T> FastTransport()
	{
		int index = 0;
		SparseMatrix<T> tmp(_RowSize, _ColSize, _invaild);
		int *RowCount=new int[tmp._RowSize];//每行有效元素的个数
		int *RowStart=new int[tmp._RowSize];//每行有效元素的起始位置
		memset(RowCount, 0, sizeof(int)*tmp._RowSize);//初始化
		memset(RowStart, 0, sizeof(int)*tmp._RowSize);

		while (index != _a.size())//设置数组RowCount的数据
		{
			RowCount[_a[index]._col]++;
			index++;
		}

		index = 1;
		RowStart[0] = 0;
		while (index < tmp._RowSize)//设置数组RowSize的数据
		{
			RowStart[index] = RowStart[index - 1] + RowCount[index - 1];
			index++;
		}
		index = 0;
		tmp._a.resize(_a.size());
		while (index < _a.size())
		{
			Triple<T> t(_a[index]._value, _a[index]._col, _a[index]._row);
			tmp._a[RowStart[_a[index]._col]++] = t;
			index++;
		}
		return tmp;
	}
protected:
	vector<Triple<T> > _a;
	size_t _RowSize;
	size_t _ColSize;
    T _invaild;
};