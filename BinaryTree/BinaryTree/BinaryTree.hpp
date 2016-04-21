#pragma once

#include<iostream>
#include<assert.h>
#include<queue>
using namespace std;

template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode(const T& d)
	:_data(d)
	,_left(NULL)
	,_right(NULL)
	{
	}
	T _data;//数据
	BinaryTreeNode<T>* _left;//左孩子
	BinaryTreeNode<T>* _right;//右孩子
};

template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree(const T *a, const T& invalid, size_t size)//创建二叉树  invalid表示没有值（左孩子或右孩子为空）
		:_root(NULL)
	{
		size_t index = 0;
		_root = _CreatBinaryTree(a, invalid, size, index);//实现递归调用
	}
	BinaryTree()//默认构造函数
		:_root(NULL)
	{}
	BinaryTree(const BinaryTree<T>& t)
		:_root(NULL)
	{
		_root=_CopTree(t._root);
	}
	BinaryTree<T>& operator=(const BinaryTree<T>& t)
	{
		if (this != &t)
		{
			Node* root = _CopTree(t._root);
			Destry(_root);
			_root = root;
		}
		return *this;
	}
	~BinaryTree()
	{
		Destry(_root);
	}
public:
	Node* _CopTree(Node* root)
	{
		Node* head=NULL;

		if (root)
		{
			head = new Node(root->_data);
			head->_left = _CopTree(root->_left);
			head->_right = _CopTree(root->_right);
		}
		return head;
	}
	void PreOrder()//先序遍历
	{
		_PreOrder(_root);
		cout << endl;
	}
	void InOrder()//中序遍历
	{
		_InOrder(_root);
		cout << endl;
	}
	void PostOrder()//后序遍历
	{
		_PostOrder(_root);
		cout << endl;
	}
	void LevelOrder()//层序遍历
	{
		queue<Node*> q1;//永远保存当前打印的一层所有节点
		queue<Node*> q2;//永远保存当前一层节点的子节点
		q1.push(_root); //根节点压入队列

		while (q1.size())//若当前一层节点没有打印完
		{
			cout << (q1.front())->_data << " ";//q1队头的节点是将要打印的节点

			if (q1.front()->_left != NULL)//若该节点的左孩子不为空
				q2.push(q1.front()->_left);//将该结点左孩子入队q2
			if (q1.front()->_right != NULL)//若该节点的右孩子不为空
				q2.push(q1.front()->_right);//将该结点左孩子入队q2

			q1.pop();//将打印过后的节点出队后，队头的元素为该层下一个未打印的节点
			if (q1.size() == 0)//若该层节点全部打印完
			{
				swap(q1, q2);//交换q1,q2,将下一层的节点保存在要打印的队列中
				continue;//继续打印
			}
		}
		cout << endl;
	}
	size_t size()//二叉树元素个数
	{
		return _Size(_root);
	}
	size_t Depth()//二叉树深度
	{
		return _Depth(_root);
	}
	size_t LeafSize()//叶子节点个数
	{
		return _LeafSize(_root);
	}
protected:
	void Destry(Node* root)
	{
		Node* del;
		Node* cur = root;
		if (cur)
		{
			del = cur;
			Destry(cur->_left);
			Destry(cur->_right);
			delete del;
		}
	
	}

	BinaryTreeNode<T>* _CreatBinaryTree(const T* a, const T& invalid, size_t size,size_t &index)
	{
		assert(a);
		Node* node = NULL;
		if (index < size && a[index] != invalid)//数组下标不越界，且有值
		{
			node= new Node(a[index]);//数组a中是前序遍历的二叉树，先创建根节点
			node->_left = _CreatBinaryTree(a, invalid, size, ++index);//创建左子树
			node->_right = _CreatBinaryTree(a, invalid, size, ++index);//创建右子数
			return node;
		}
		return node;
	}
	void _PreOrder(Node* root)
	{
		if (root == NULL)
			return;
		else
		{
			cout << root->_data << " ";
			_PreOrder(root->_left);
		    _PreOrder(root->_right);
		}
	}
	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		else
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}
	void _PostOrder(Node* root)
	{
		if (root == NULL)
			return;
		else
		{
			_PostOrder(root->_left);
			_PostOrder(root->_right);
			cout << root->_data << " ";
		}
	}
	
	size_t _Size(Node* root)
	{
		int size = 0;
		if (root)//节点不为空时，size++
		{
			size++;
			size+=_Size(root->_left);
			size+=_Size(root->_right);
		}
		return size;
	}

	//深度
	//思路：默认每一层深度为1，递归到最后一层后往上返回（每返回一层深度+1）
	size_t _Depth(Node* root)
	{
		size_t depth=1;//最深深度，默认若节点不为空则深度为1
		if (root)//不为空
		{
			size_t trdepth = _Depth(root->_left);//递归计算左子树的深度
			if (trdepth + 1 > depth)//若左子树深度大于当前深度
				depth = trdepth + 1;//重置最深深度
			trdepth = _Depth(root->_right);//递归计算右子树深度
			if (trdepth + 1 > depth)
				depth = trdepth + 1;//重置最深深度
		}
		else
			depth = 0;//若为节点是空节点，深度为0
		return depth;
	}
	size_t _LeafSize(Node* root)//叶子节点个数
	{
		size_t size = 0;
		if (root == NULL)//为空返回
			return size;
		if (root->_left == NULL && root->_right == NULL)//若节点为叶子节点（没有孩子）
			return ++size;//叶子节点个数+1
		else
		{
			size+=_LeafSize(root->_left);//递归寻找左子树的叶子节点
			size+=_LeafSize(root->_right);//递归寻找右子数的叶子节点
		}
	}
protected:
	BinaryTreeNode<T>* _root;
};