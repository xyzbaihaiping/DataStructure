#ifndef __SEQLIST_H__
#define __SEQLIST_H__


#include<iostream>
using namespace std;

template<typename T>

class SeqList
{
public:
	SeqList()
	:_size(0)
	, _capacity(0)
	{}
	void PushBack(const T& d);
	void PopBack();
	void PushFront(const T& d);
	void PopFront();
	int Find(const T& d);
	void Insert(int pos, const T& d);
	void Sort();
	template<typename T>
	friend ostream& operator<<<T>(ostream& output, const SeqList<T>& s);
private:
	void _CheckCapacity()
	{
		if (_size == _capacity)
		{
			T* tmp = new T[2 * _capacity + 3];
			memcpy(tmp, _data, sizeof(T)*_size);
            delete[] _data;
			_data = tmp;
			_capacity = 2 * _capacity + 3;
		}
	}
private:
	T* _data;
	int _size;
	int _capacity;
};
#endif//__SEQLIST_H__