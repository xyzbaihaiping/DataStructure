#pragma once
#include <vector>
#include <assert.h>
#include<iostream>
using namespace std; 

// 仿函数
template <class T>
struct Less
{
	bool operator() (const T& l, const T& r)
	{
		return l < r;
	}

};

template <class T>
struct Greater
{
	bool operator() (const T& l, const T& r)
	{
		return l > r;
	}
};


// 大堆
template<class T, class Compare = Greater<T>>
class Heap
{
public:
	Heap()
	{}

	Heap(const T* a, size_t size)
	{
		assert(a);
		for (size_t i = 0; i < size; ++i)
		{
			_a.push_back(a[i]);
		}

		// 建堆 N*lgN
		for (int i = (_a.size() - 2) / 2; i >0; --i)
		{
			_AdjustDown(i);
		}
	}

	//
	void Push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1);
	}

	// 
	void Pop(const T& x)
	{
		assert(!_a.empty());

		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();

		_AdjustDown(0);
	}
	T& Top()
	{
		return _a[0];
	}
	size_t Size()
	{
		return _a.size();
	}

	bool Empty()
	{
		return _a.empty();
	}

protected:
	void _AdjustDown(size_t parent)
	{
		// 指向左孩子
		size_t child = parent * 2 + 1;

		Compare com;
		while (child < _a.size())
		{
			// 选出左右孩子里面大的那一个

			//if (child+1 < _a.size() 
			//	&&_a[child+1] > _a[child])
			if (child + 1 < _a.size()
				&& com(_a[child + 1], _a[child]))
			{
				++child;
			}

			// 如果孩子比父节点要大，则交换并继续往下调整
			//if (_a[child] > _a[parent])
			if (com(_a[child], _a[parent]))
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}

	void _AdjustUp(int child)
	{
		int parent = (child - 1) / 2;
		Compare com;

		while (child > 0)
			//while(parent >= 0)
		{
			//if (_a[child] > _a[parent])
			if (com(_a[child], _a[parent]))
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

protected:
	//T* _a;
	//size_t _size;
	//size_t _capacity;
	vector<T> _a;

};

void TestHeap()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };

	Heap<int, Less<int>> hp1(a, sizeof(a) / sizeof(a[0]));

	hp1.Push(20);
}


template<class T>
class PriorityQueue
{
public:
	// O(lgN)
	void Push(const T& x)
	{
		_hp.Push(x);
	}

	// O(lgN)
	void Pop()
	{
		_hp.Pop();
	}

protected:
	Heap<T> _hp;
};

void _AdjustDown(int a[], int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1]>a[child])
		{
			++child;
		}

		if (a[parent] < a[child])
		{
			swap(a[parent], a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int a[], size_t n)
{
	assert(a);

	// 建堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		_AdjustDown(a, n, i);
	}

	// 选出一个最大数据交换到末尾，剩下数据进行向下调整
	for (int i = 0; i < n; ++i)
	{
		swap(a[0], a[n - 1 - i]);

		_AdjustDown(a, n - i - 1, 0);
	}
}

void TestHeapSort()
{
	int a[] = { 2, 1, 4, 5, 0, 6, 3, 7, 8, 9 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < 10; i++)
	{
		cout << a[i];
	}
}