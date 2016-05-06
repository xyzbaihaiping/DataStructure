
#include"SeqList.h"
template<typename T>
void SeqList<T>::PushBack(const T& d)
{
	_CheckCapacity();
	_data[_size] = d;
	_size++;
}
template<typename T>
void SeqList<T>::PopBack()
{
	_size--;
}
template<typename T>
void SeqList<T>::PushFront(const T& d)
{
	_CheckCapacity();
	for (int i = _size; i >0;; i--)
	{
		_data[i] = _data[i-1];
	}
	_data[0] = d;
	_size++;
}
template<typename T>
void SeqList<T>::PopFront()
{
	
	for (int i = 0; i < _size; i++)
	{
		_data[i] = _data[i + 1];
	}
	_size--;
}

template<typename T>
int SeqList<T>::Find(const T& d)
{
	for (int i = 0; i < _size; i++)
	{
		if (_data[i] == d)
			return i;
	}
	return -1;
}

template<typename T>
void SeqList<T>::Insert(int pos, const T& d)
{
	_CheckCapacity();
	for (int i = _size; i > pos; i++)
	{
		_data[i] = _data[i - 1];
	}
	_data[pos] = d;
	_size++;
}

template<typename T>
void SeqList<T>::Sort()
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < _size; i++)
	{
		flag = 0;
		for (j = 0; j < _size - 1 - i; j++)
		{
		
			if (_data[j]>_data[j + 1])
			{
				T tmp = _data[j];
				_data[j] = _data[j + 1];
				_data[j + 1] = tmp;
				flag = 1;
			}
		}
	
		if (flag == 1)
			break;
	}
}
template<typename T>
ostream& operator<<(ostream& output, const SeqList<T>& s)
{
	for (int i = 0; i < s._size; i++)
	{
		output << s._data[i] << " ";
	}
	return output;
}
