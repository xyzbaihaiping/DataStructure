#pragma once

#include<vector>
using namespace std;

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

template<class K>
class BitMap
{
public:
	BitMap(size_t size)
	{
		_a.resize((size >> 5) + 1);
	}
	void Set(const K& key)
	{
		int num = key >> 5;
		int bit = key % 32;
		_a[num] |= 1 << bit;
	}
	void ReSet(const K& key)
	{
		int num = key >> 5;
		int bit = key % 32;
		_a[num] &= ~(1 <<bit);
	}
	bool Test(const K& key)
	{
		int num = key >> 5;
		int bit = key % 32;
		return _a[num] & (1<<bit);
	}
protected:
	vector<size_t> _a;
};

