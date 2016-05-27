#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class K>
struct _HashFunc
{
	size_t operator()(const K& key,size_t capacity)
	{
		return key%capacity;
	}
};
template<>
struct _HashFunc<string>
{

	static size_t _BKDRHash(const char * str)
	{
		unsigned int seed = 131; // 31 131 1313 13131 131313
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}
	size_t operator()(const string& key, size_t capacity)
	{
		return _BKDRHash(key.c_str()) % capacity;
	}
};

template<class K,class V>
struct HashTableNode
{
	HashTableNode(const K& key, const V& value)
	:_key(key)
	, _value(value)
	,_next(NULL)
	{}
	K _key;
	V _value;
	HashTableNode<K,V>* _next;
};

const int _PrimeSize = 28;
static const unsigned long _PrimeList[_PrimeSize] =
{
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};
template<class K, class V, class HashFunc = _HashFunc<K> >
class HashTable
{
public:

	typedef HashTableNode<K, V> Node;

	HashTable(const HashTable<K,V>& ht)
		:_size(0)
	{
		_tables.resize(ht._tables.size());
		for (size_t i = 0; i < ht._tables.size(); i++)
		{
			Node* cur = ht._tables[i];
			while (cur)
			{
				Insert(cur->_key, cur->_value);
				cur = cur->_next;
				_size++;
			}
		}

	}
	HashTable& operator=(HashTable<K, V> ht)
	{
		swap(_tables, ht._tables);
		return *this;
	}
	~HashTable()
	{
		for (size_t i = 0; i < _tables.size(); i++)
		{
			Node* cur = _tables[i];
			while (cur)
			{
				Node* del = cur;
				cur = cur->_next;
				delete del;
			}
		}

	}
	HashTable(const size_t& capacity)
		:_size(0)
	{
		_tables.resize(_GetCapacity(0));
	}
	bool Insert(const K& key,const V& value)
	{
		_CheckCapacity();
		size_t index = HashFunc()(key,_tables.size());
		Node* cur = _tables[index];
		while (cur)
		{
			if (cur->_key == key)
				return false;
			cur = cur->_next;
		}
		Node* NewNode = new Node(key, value);
		NewNode->_next = _tables[index];
		_tables[index] = NewNode;
		_size++;
	}
	Node* Find(const K& key)
	{
		size_t index = HashFunc()(key, _tables.size());
		Node* cur = _tables[index];
		while (cur)
		{
			if (cur->_key == key)
				return cur;
			cur = cur->_next;
		}
		return NULL;
	}
	bool Remove(const K& key)
	{
		size_t index = HashFunc()(key, _tables.size());
		Node* cur = _tables[index];
		if (cur == NULL)
			return false;
		if (cur->_key == key && cur)
		{
			_tables[index] = cur->_next;
			delete cur;
			cur = NULL;
			return true;
		}
		Node* prev = NULL;
		while (cur)
		{
			prev = cur;
			cur = cur->_next;
			if (cur->_key == key)
			{
				prev->_next = cur->_next;
				delete cur;
				return true;
			}
		
		}
		return false;
	}

	void Print()
	{
		for (size_t i = 0; i < _tables.size(); i++)
		{
			Node* cur = _tables[i];
			while (cur)
			{
				cout << cur->_key << ":" << cur->_value << "->";
				cur = cur->_next;
			}
			cout << "NULL" << endl;
		}
	}
private:
	void _CheckCapacity()
	{
		if (_size == _tables.size())
		{
			size_t capacity = _GetCapacity(_size);
			vector<Node*> tab;
			tab.resize(capacity);
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* tmp = cur;
					cur = cur->_next;
					size_t index = HashFunc()(tmp->_key, tab.size());
					tmp->_next = tab[index];
					tab[index] = tmp;
				}
				_tables[i] = NULL;
			}
			_tables.swap(tab);
		}
		
	}

	size_t _GetCapacity(const size_t& capacity)
	{
		for (size_t i = 0; i<_PrimeSize; i++)
		{
			if (capacity < _PrimeList[i])
				return _PrimeList[i];
		}
	}

private:
	vector<Node*> _tables;
	size_t _size;
};