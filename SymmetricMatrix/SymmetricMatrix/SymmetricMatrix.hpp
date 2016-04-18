#pragma once

#include<iostream>
using namespace std;

template<class T>
class SymmetricMatrix
{
public:
	SymmetricMatrix(const T* a, size_t size, size_t n)
	:_a(new T[n*(n + 1) / 2])
	, _size(n*(n + 1) / 2)
	, _n(n)
	{
		int index = 0;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (i >= j)
					_a[index++] = a[i*n + j];
				else
					break;
			}
		}
	}
	~SymmetricMatrix()
	{
		if (_a)
			delete[] _a;
	}
	T& Access(int i,int j)
	{
		if (i < j)
			swap(i, j);
		return _a[i*(i + 1) / 2 + j];
	}
	void display()
	{
		for (size_t i = 0; i < _n; i++)
		{
			for (size_t j = 0; j < _n; j++)
			{
				if (i >= j)
					cout << _a[i*(i + 1) / 2 + j] << " ";
				else
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
