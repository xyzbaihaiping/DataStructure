#pragma once

#include<iostream>
using namespace std;

enum Colour
{
	RED,
	BLACK
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _parent;
	K _key;
	V _value;
	Colour _col;
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const K& key, const V& value)
	{
	
	}
	bool Remove(const K& key);
	Node* Find(const K& key);
	void RotateR(Node* parent);
	void Rotatel(Node* parent);
	bool CheckRBTerr();

protected:
	Node* _root;
};
