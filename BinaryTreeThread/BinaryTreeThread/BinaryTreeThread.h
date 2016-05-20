#pragma once

#include<iostream>
#include<assert.h>
using namespace std;

enum PointerTag{LINK,THREAD};

template<class T>
struct BinaryTreeNode_Thd
{
	BinaryTreeNode_Thd(const T& d)
	:_data(d)
	, _left(NULL)
	, _right(NULL)
	, _leftTag(LINK)
	, _rightTag(LINK)
	{}
	T _data;
	BinaryTreeNode_Thd<T>* _left;
	BinaryTreeNode_Thd<T>* _right;
	PointerTag _leftTag;
	PointerTag _rightTag;
};
template<class T>
class BinaryTreeThd
{
	typedef  BinaryTreeNode_Thd<T> Node;
public:
	
	BinaryTreeThd(const T* a, size_t size, const T& invalid)
		:_root(NULL)
	{
		size_t index = 0;
		_root=_CreatTree(a, size, index, invalid);
	}
	void InOrderTheading()//中序线索化
	{
		Node* prev = NULL;
		_InOrderTheading(_root,prev);
	}
	void InOrderThd()//中序遍历
	{
		Node* cur = _root;
		while (cur)
		{
			while (cur->_leftTag == LINK)//找树的最左节点
			{
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			while (cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}
			cur = cur->_right;
		}
		cout << endl;
	}
	void PrevOrderTheading()//前序线索化
	{
		Node* prev = NULL;
		_PrevOrderTheading(_root, prev);
	}
	void PrevOrderThd()//前序遍历
	{
		Node* cur = _root;
		while (cur)
		{
			while (cur->_leftTag == LINK)
			{
				cout << cur->_data << " ";
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			cur = cur->_right;
		}
	}
	void PostOrderTheading()//后序线索化
	{
		Node* prev = NULL;
		_PostOrderTheading(_root, prev);
	}
protected:
	Node* _CreatTree(const T *a, size_t size, size_t &index, const T& invalid)//建立二叉树
	{
		assert(a);
		Node* node = NULL;
		if (a[index] != invalid && index < size)
		{
		    node= new Node(a[index]);
			node->_left = _CreatTree(a, size, ++index, invalid);
			node->_right = _CreatTree(a, size, ++index, invalid);
		}
		return node;
	}
	void _InOrderTheading(Node *cur, Node* &prev)//递归方法中序线索化
	{
		if (cur == NULL)
			return;
		_InOrderTheading(cur->_left, prev);
		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}
		if (prev && prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		prev = cur;
		_InOrderTheading(cur->_right, prev);
	}
	void _PrevOrderTheading(Node *cur, Node* &prev)//递归方法中序线索化
	{
		if (cur == NULL)
			return;
		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}
		if (prev && prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		prev = cur;
		if (cur->_leftTag==LINK)
			_PrevOrderTheading(cur->_left, prev);
		if (cur->_rightTag==LINK)
			_PrevOrderTheading(cur->_right, prev);
	}
	void _PostOrderTheading(Node *cur, Node* &prev)//递归方法中序线索化
	{
		if (cur == NULL)
			return;
		_PostOrderTheading(cur->_left, prev);
		_PostOrderTheading(cur->_right, prev);
		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}
		if (prev && prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		prev = cur;
		
	}
private:
	Node* _root;
};