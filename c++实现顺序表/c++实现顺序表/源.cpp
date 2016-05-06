#include<iostream>
using namespace std;

typedef int DataType;
#define DEFAULT_CAPACITY 7
#define DEFAULT_INC 7

class SeqList
{
public:
	SeqList(int capacity = DEFAULT_CAPACITY)
		:_size(0)
		, _capacity(capacity)
		, _pdata(0)
	{
		_pdata = new DataType[_capacity];
	}
	~SeqList()
	{
		if (_pdata != NULL)
		{
			delete[] _pdata;
			_pdata = NULL;
		}
	}
	SeqList(const SeqList& s)
		:_size(s._size)
		, _capacity(s._capacity)
	{
		_pdata = new DataType[s._capacity];
		memcpy(_pdata, s._pdata,s._size*sizeof(DataType));
	}
	SeqList& operator=(const SeqList& s)
	{
		if (this != &s)
		{
			delete[] _pdata;
			_pdata = new DataType[s._capacity];
			memcpy(_pdata, s._pdata, s._size*sizeof(DataType));
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}
public:
	void PushBack(const DataType& d)
	{
		_CheckCapacity();
		_pdata[_size++] = d;
	}
	void PushFront(const DataType& d)
	{
		_CheckCapacity();
		int start = _size - 1;
		while (start >= 0)
		{
			_pdata[start + 1] = _pdata[start];
			start--;
		}
		_pdata[0] = d;
		_size++;
	}
	void PopBack()
	{
		_size--;
	}
	void PopFront()
	{
		int i = 0;
		for (i = 1; i < _size; i++)
		{
			_pdata[i - 1] = _pdata[i];
		}
		_size--;
	}
	void Insert(int pos, const DataType& d)
	{
		_CheckCapacity();
		int start = _size-1;
		while (start >= pos)
		{
			_pdata[start + 1] = _pdata[start];
			start--;
		}
		_pdata[pos] = d;
		_size++;
		
	}
	int Find(const DataType& d)
	{
		int i = 0;
		for (i = 0; i < _size; i++)
		{
			if (_pdata[i] == d)
				return i;
		}
		return -1;
	}
	void Remove(const DataType& d)
	{
		int pos=Find(d);
		if (pos == -1)
			return;
		for (int i = pos; i < _size; i++)
		{
			_pdata[i] = _pdata[i + 1];
		}
		_size--;
	}
	
	void Reserve()
	{
		int left = 0;
		int right = _size - 1;
		while (left < right)
		{
			swap(_pdata[left], _pdata[right]);
			left++;
			right--;
		}
	}
	DataType& operator[](int i)
	{
		return _pdata[i];
	}
	friend ostream& operator<<(ostream& output, const SeqList& s)
	{
		int i = 0;
		for (i = 0; i < s._size; i++)
		{
			output << s._pdata[i]<<" ";
		}
		return output;
	}
public:
	void _CheckCapacity()
	{
		if (_size == _capacity)
		{
			DataType *tmp = new DataType[_capacity + DEFAULT_INC];
			memcpy(tmp, _pdata, _size*sizeof(DataType));
			delete[] _pdata;
			_pdata = tmp;
			_capacity = _capacity + DEFAULT_INC;
		}
	}
	void _swap(DataType& d1, DataType& d2)
	{
		DataType tmp = d1;
		d1 = d2;
		d2 = tmp;
	}
private:
	DataType* _pdata;
	int _size;
	int _capacity;
	
};
int main()
{
	SeqList seqlist;
	seqlist.PushBack(1);
	seqlist.PushBack(2);
	seqlist.PushBack(3);
	seqlist.PushBack(4);
	seqlist.PushBack(5);
	seqlist.PushFront(6);
	seqlist.PushFront(7);
	seqlist.PushFront(8);
	
	cout << seqlist << endl;

	seqlist.Remove(8);
	cout << seqlist << endl;
	int pos=seqlist.Find(5);
	cout <<"seqlist[pos]"<< "="<<seqlist[pos]<< endl;
	seqlist.Reserve();
	cout << seqlist << endl;

	getchar();
	return 0;
}
