#pragma once
#include<iostream>
#include <string>
using namespace std;
enum State
{
	EMPTY,
	EXITS,
	DELETE
};

template<class K, class V>
struct HashTableNode
{
	K _key;
	V _value;
};




template<class K>
struct _HashFunc
{
	size_t operator()(const K& key,const size_t& capacity)
	{
		return key / capacity;
	}

};
template<>
struct _HashFunc<string>
{
private:
	unsigned int _BKDRHash(const char *str)
	{
		unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
		unsigned int hash = 0;

		while (*str)
		{
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}
public:
	size_t operator()(const string& key,const size_t& capacity)
	{

		return _BKDRHash(key.c_str()) % capacity;
	}

};
template<class K, class V,class HashFunc=_HashFunc<K>>
class HashTable
{

	typedef HashTableNode<K, V> Node;
public:
	HashTable(size_t capacity = 10)
		:_tables(new Node[capacity])
		, _states(new State[capacity])
		, _size(0)
		, _capacity(capacity)
	{}
	~HashTable()
	{
		if (_tables != NULL)
		{
			delete[] _tables;
			delete[] _states;
		}
	
	}
	HashTable(const HashTable<K, V>& ht)
	{
		HashTable<K, V> tmp(ht._capacity);
		for (size_t i = 0; i < ht._capacity; i++)
		{
			tmp.Insert(ht._tables[i]._key, ht._tables[i]._value);
		}
		this->Swap(tmp);
	}
	HashTable& operator=(HashTable<K, V> ht)
	{
		this->Swap();
		return *this;
	}
	bool Insert(const K& key, const V& value)
	{
		_CheckCapacity();
		size_t index = Hashfunc(key,_capacity);
		size_t i = 1;
		while (_states[index] == EXITS)
		{
			if (_tables[index]._key == key)
			{
				return false;
			}
			index = index + 2 * i - 1;
			index %= _capacity;
			++i;
		}
		_tables[index]._key = key;
		_tables[index]._value = value;
		_states[index] = EXITS;
		++_size;
		return true;
	}

	bool Find(const K& key)
	{
		size_t index = Hashfunc(key,_capacity);
		size_t start = index;
		size_t i = 1;
		while (_states[index] != EMPTY)
		{
			if (_tables[index]._key == key)
			{
				if (_states[index] != DELETE)
					return true;
				else
					return false;
			}
			index = index + 2 * i - 1;
			index %= _capacity;
			if (start == index)
				return false;
		}
		return false;
	}
	bool Remove(const K& key)
	{
		size_t index = Hashfunc(key,_capacity);
		size_t start = index;
		size_t i = 1;
		while (_states[index] != EMPTY)
		{
			if (_tables[index]._key == key)
			{
				if (_states[index] != DELETE)
				{
					_states[index] = DELETE;
					_size--;
					return true;
				}
				else
					return false;
			}
			index = index + 2 * i - 1;
			index %= _capacity;
			if (start == index)
				return false;
		}
		return false;


	}
	void Print()
	{
		for (size_t i = 0; i < _capacity; i++)
		{
			//printf("%d-[%s:%s] \n", _states[i], _tables[i]._key, _tables[i]._value);
			cout << _states[i] << " " << _tables[i]._key << " " << _tables[i]._value<<endl;
		}
	}
private:
	void Swap(HashTable<K, V>& tmp)
	{
		swap(_tables, tmp._tables);
		swap(_states, tmp._states);
		swap(_size, tmp._size);
		swap(_capacity, tmp._capacity);
	}
	void _CheckCapacity()
	{
		if (_size * 10 / _capacity == 6)
		{
			HashTable<K, V> tmp(_capacity * 2);
			for (size_t i = 0; i < _capacity; i++)
			{
				if (_states[i] == EXITS)
					tmp.Insert(_tables[i]._key, _tables[i]._value);
			}
			this->Swap(tmp);
		}
	}

private:
	Node* _tables;//¹þÏ£±í
	State* _states;//×´Ì¬±í
	size_t _size;
	size_t _capacity;
	HashFunc Hashfunc;
};

