#pragma once
#include<iostream>
using namespace std;

template<class K, class V>

struct BSTNode
{
	BSTNode<K, V>* _left;
	BSTNode<K, V>* _right;
	K _key;
	V _value;

	BSTNode(const K& key, const V& value)
		:_key(key)
		, _value(value)
		, _left(NULL)
		, _right(NULL)
	{}
};
template<class K, class V>
class BSTree
{
	typedef BSTNode<K, V> Node;

public:
	BSTree()
		:_root(NULL)
	{}

	bool Insert(const K& key, const V& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			return true;
		}
		Node* cur = _root;
		Node* parent = NULL;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return false;
		}
		if (parent->_key > key)
			parent->_left = new Node(key, value);
		else if (parent->_key < key)
			parent->_right = new Node(key, value);
		else
			return false;
		return true;
	}
	bool Insert_R(const K& key, const V& value)
	{
		return _Insert_R(_root, key, value);
	}

	Node* Find(const K& key)
	{



	}
	Node* Find_R(const K& key);
	bool Remove(const K& key);
	bool Remove_R(const K& key);
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	bool _Insert_R(Node* &root, const K& key, const V& value)
	{
		if (root == NULL)
		{
			root = new Node(key, value);
			return true;
		}
		if (root->_key < key)
			return _Insert_R(root->_right, key, value);
		else if (root->_key > key)
			return _Insert_R(root->_left, key, value);
		else
			return false;
   }
private:
	Node* _root;
};

void Test()
{
	BSTree<int, int> t;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	/*for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		t.Insert(a[i], i);
	}
	t.Insert(12,12);*/

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		t.Insert_R(a[i], i);
	}
	t.Insert_R(12, 12);
	t.InOrder();
}