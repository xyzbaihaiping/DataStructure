#pragma once

#include<iostream>
#include<assert.h>
#include<queue>
#include<stack>
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
	//void PreOrder()//递归实现先序遍历
	//{
	//	_PreOrder(_root);
	//	cout << endl;
	//}
	//void InOrder()//递归实现中序遍历
	//{
	//	_InOrder(_root);
	//	cout << endl;
	//}
	//void PostOrder()//递归实现后序遍历
	//{
	//	_PostOrder(_root);
	//	cout << endl;
	//}
	void PrevOrderNonR()//非递归
	{
		stack<Node*> s; //利用栈的先进后出，后进先出的性质保存二叉树节点
		Node* cur = _root;
		if (cur == NULL)
			return;
		s.push(cur);//若根节点不为空，则将根节点入栈
		
		while (!s.empty())//栈为空表示二叉树已访问完
		{
			cur = s.top();//访问栈顶的元素
			cout << cur->_data << " ";
			s.pop();//栈顶元素出栈
			if (cur->_right)//将访问过的元素的右节点压栈（后访问的先压栈）
				s.push(cur->_right);
			if (cur->_left)//左节点压栈
				s.push(cur->_left);
		}

		cout << endl;
	}
	void InOrderNonR()//非递归
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())//若节点不为空或栈不为空
		{
			while(cur)//若节点不为空
			{
				s.push(cur);//将节点入栈
				cur = cur->_left;//若该节点有左节点，则将左节点入栈
			}
			cur = s.top();
			cout << cur->_data << " ";//访问最左节点（代表该节点左节点为空或已访问）
			s.pop();
			cur = cur->_right;//访问右节点
		}

		cout << endl;
	}

	void PostOrderNonR()//非递归
	{
		stack<Node*> s;
		Node* cur = _root;
		Node* prev = NULL;//上一个访问过的节点

		while (cur || !s.empty())//若节点不为空或栈不为空
		{
			while(cur)
			{
				s.push(cur);
				cur = cur->_left;
			}//栈顶元素为最左节点，第一个访问
			Node* top= s.top();//取到栈顶元素
			if (top->_right == NULL || prev == top->_right)//若栈顶元素的右节点为空，或它的右节点已访问过，则访问该节点
			{
				cout << top->_data << " ";
				s.pop();
				prev = top;//更新prev
			}
			else
				cur = top->_right;//若给元素的右节点没有访问过，则将该元素的右节点压栈
		}
		cout << endl;
	}
	//思路：利用队列先进先出的特点,访问上一层节点时，将它的下一层节点入队，访问完上一层节点后，
	//将其出队，然后可访问下一层节点
	void LevelOrder()//层序遍历
	{
		queue<Node*> q;
		Node* cur = _root;
		if (cur)
			q.push(cur);//若根节点不为空，将根节点入队
		while (!q.empty())//层序遍历完的结束条件是队列为空
		{
			cur = q.front();
			cout <<cur->_data << " ";//访问队头元素
			if (cur->_left)
			{
				q.push(cur->_left);//将该元素的左节点入队
			}
			if (cur->_right)
			{
				q.push(cur->_right);//将该元素的右节点入队
			}
			q.pop();//访问过的节点出队
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
	Node* Find(const T& x)//查找元素
	{
		return _Find(_root,x);
	}
	/*size_t GetKlevel(size_t k)
	{
		size_t size = 0;
		size_t level = 1;
		_GetKlevel(_root, k, level, size);
		return size;
	}*/
	size_t GetKlevel(size_t k)
	{
		return _GetKlevel(_root,k);
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
		if (root == NULL)
			return 0;
		return 1 + _Size(root->_left) + _Size(root->_right);
	}

	//深度(高度)
	//思路：若根节点不为空，则二叉树深度取左子树深度和右子数深度中的最大值，
	size_t _Depth(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		size_t Ldepth = _Depth(root->_left);//计算左子树深度
		size_t Rdepth = _Depth(root->_right);//计算右子树深度
		if (Ldepth > Rdepth)//取最深的值
		{
			return Ldepth+1;//当前深度是左子树深度+1
		}
		else
			return Rdepth+1;//当前深度是右子树深度+1
	}
	size_t _LeafSize(Node* root)//叶子节点个数
	{
		if (root == NULL)//为空返回
			return 0;
		if (root->_left == NULL && root->_right == NULL)//若节点为叶子节点（没有孩子）
			return 1;
		return _LeafSize(root->_left) + _LeafSize(root->_right);//叶子节点的个数是左子树的叶子节点个数+右子树叶子节点的个数
	}
	Node* _Find(Node* root, const T& x)//查找节点
	{
		if (root == NULL)//若节点为空
			return NULL;//返回空
		if (root->_data == x)//若节点值等于要查找的值
			return root;//返回该节点
		Node* ret = _Find(root->_left, x);//若不等于，则递归在左子树中查找
		if (ret)
		        return ret;//若查找结果不为空，则返回查找的节点地址
		else
			return _Find(root->_right, x);//若为空（代表左子树中没有该节点），则在右子树中查找
	
	}
	//void _GetKlevel(Node* root, size_t k,size_t level,size_t& size)//第k层节点数，传值法
	//{
	//	if (root == NULL)
	//		return;
	//	if (level == k)//若k等于当前层数
	//	{
	//		++size;
	//		return ;//返回size+1;
	//	}
	//	_GetKlevel(root->_left, k, level + 1, size);//访问下一层
	//	_GetKlevel(root->_right, k, level + 1, size);//访问下一层

	//}
	size_t _GetKlevel(Node* cur,size_t k)
	{
		if (cur == NULL)
			return 0;
		if (k == 1)
			return 1;
		else
			return _GetKlevel(cur->_left, k - 1) + _GetKlevel(cur->_right, k - 1);
	}
protected:
	BinaryTreeNode<T>* _root;
};