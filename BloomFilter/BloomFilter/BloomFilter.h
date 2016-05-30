
#pragma once
#include<iostream>
#include "BitMap.h"
#include<string>
using namespace std;

struct _HashFunc1
{

	size_t BKDRHash(const char * str)
	{
		unsigned int seed = 131;
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}
	size_t operator()(const string& key)
	{
		return BKDRHash(key.c_str());
	}
};
struct _HashFunc2
{
	size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}

	size_t operator()(const string& key)
	{
		return BKDRHash(key.c_str());
	}
};
struct _HashFunc3
{

	size_t SDBMHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = 65599 * hash + ch;
		}
		return hash;
	}

	size_t operator()(const string& key)
	{
		return SDBMHash(key.c_str());
	}
};
struct _HashFunc4
{
	size_t FNVHash(const char* str)
	{
		if (!*str)
			return 0;
		register size_t hash = 2166136261;
		while (size_t ch = (size_t)*str++)
		{
			hash *= 16777619;
			hash ^= ch;
		}
		return hash;
	}

	size_t operator()(const string& key)
	{
		return FNVHash(key.c_str());
	}
};
struct _HashFunc5
{

	size_t DEKHash(const char* str)
	{
		if (!*str)
			return 0;
		register size_t hash = 1315423911;
		while (size_t ch = (size_t)*str++)
		{
			hash = ((hash << 5) ^ (hash >> 27)) ^ ch;
		}
		return hash;
	}
	size_t operator()(const string& key)
	{
		return DEKHash(key.c_str());
	}
};
const int _PrimeSize = 28;
const unsigned long _PrimeList[_PrimeSize] =
{
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};
template<class K = string,
class HashFunc1 = _HashFunc1,
class HashFunc2 = _HashFunc2,
class HashFunc3 = _HashFunc3,
class HashFunc4 = _HashFunc4,
class HashFunc5 = _HashFunc5
>
class BloomFilter
{
public:
	BloomFilter(const size_t& capacity=100)
		:_capacity(_GetCapacity(capacity))
	, _a(_capacity)
	{}
	void Set(const K& key)
	{
		_a.Set(HashFunc1()(key) % _capacity);
		_a.Set(HashFunc2()(key) % _capacity);
		_a.Set(HashFunc3()(key) % _capacity);
		_a.Set(HashFunc4()(key) % _capacity);
		_a.Set(HashFunc5()(key) % _capacity);
	}
	bool Test(const K& key)
	{
		bool hash1 = _a.Test(HashFunc1()(key) % _capacity);
		bool hash2 = _a.Test(HashFunc2()(key) % _capacity);
		bool hash3 = _a.Test(HashFunc3()(key) % _capacity);
		bool hash4 = _a.Test(HashFunc4()(key) % _capacity);
		bool hash5 = _a.Test(HashFunc5()(key) % _capacity);

		if (hash1 && hash2 && hash3 && hash4 && hash5)
			return true;
		else
			return false;
	}
	size_t _GetCapacity(const size_t& capacity)
	{
		for (size_t i = 0; i<_PrimeSize; i++)
		{
			if (capacity < _PrimeList[i])
				return _PrimeList[i];
		}
	}
protected:
	size_t _capacity;
	BitMap<size_t> _a;
};