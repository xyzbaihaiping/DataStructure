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
		else 
			parent->_right = new Node(key, value);
		return true;
	}
	bool Insert_R(const K& key, const V& value)//递归
	{
		return _Insert_R(_root, key, value);
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
				cur = cur->_right;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				break;
		}
		return cur;
	}
	Node* Find_R(const K& key)
	{
		return _Find_R(_root, key);
	}
	bool Remove(const K& key)
	{
		Node* cur = _root;
		Node* parent = NULL;
		Node* del = NULL;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				break;
			}
		}
		if (cur == NULL)
		{
			return false;
		}
		else
		{
			del = cur;
			if (cur->_left == NULL)//删除节点没有左孩子
			{
				if (parent == NULL)
				{
					_root = cur->_right;

				}
				else
				{
					if (cur == parent->_left)
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
				}
				
			}
			else if (cur->_right == NULL)//删除节点没有右孩子
			{
				if (parent == NULL)
				{
					_root = cur->_left;
				}
				else
				{
					if (cur == parent->_left)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
				
			}
			else//删除节点左右孩子都有
			{
				
				Node* firstLNode = cur->_right;
				Node* parent = cur;
				while (firstLNode->_left)
				{
					parent = firstLNode;
					firstLNode = firstLNode->_left;
				}
				cur->_key = firstLNode->_key;//将该节点的值用右子树的最左节点代替，删除右子树的最左节点
				cur->_value = firstLNode->_value;
				del = firstLNode;

				if (parent->_right == firstLNode)
					parent->_right = firstLNode->_right;
				else
					parent->_left = firstLNode->_right;
			}
		
		}
		delete del;
		return true;
	}
	bool Remove_R(const K& key)
	{
		if (_root == NULL)
			return false;
		else
			return _Remove_R(_root,key);
	
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:

	bool _Remove_R(Node *& root, const K& key)
	{
		if (root == NULL)
			return false;
		Node* del = root;
		if (root->_key == key)
		{
			if (root->_left == NULL)
			{
				root = root->_right;
			}
			else if (root->_right == NULL)
			{
				root = root->_left;
			}
			else
			{
				Node* firstLNode = root->_right;
				while (firstLNode->_left)
				{
					firstLNode = firstLNode->_left;
				}
				swap(root->_key ,firstLNode->_key);
				swap(root->_value , firstLNode->_value);

				return _Remove_R(root->_right, key);
			}
		}
		else if (root->_key < key)
			return _Remove_R(root->_right, key);
		else
			return _Remove_R(root->_left, key);

		delete del;
		return true;
	}
	Node* _Find_R(Node* root, const K& key)
	{
		if (root == NULL)
			return NULL;
		if (root ->_key==key)
			return root;
		else if (root->_key < key)
			return _Find_R(root->_right, key);
		else
			return _Find_R(root->_left, key);
	}

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

void TestInsert()
{
	BSTree<int, int> t;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	//测试插入
	/*for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)//非递归插入
	{
		t.Insert(a[i], i);
	}
	t.Insert(12,12);*/

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)//递归插入
	{
		t.Insert_R(a[i], i);
	}
	t.Insert_R(12, 12);
	t.InOrder();
}

void TestFind()
{
	BSTree<int, int> t;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		t.Insert(a[i], i);
	}
	t.Insert(12, 12);

	//测试查找
	/*cout << t.Find(4)->_key << " " << t.Find(4)->_value << endl;//非递归查找
	cout << t.Find(9)->_key <<" "<<t.Find(9)->_value<< endl;
	BSTNode<int,int>* val = t.Find(10);
	if (val == NULL)
	cout << "not find" << endl;*/

	cout << t.Find_R(4)->_key << " " << t.Find_R(4)->_value << endl;//递归查找
	cout << t.Find_R(9)->_key << " " << t.Find_R(9)->_value << endl;
	BSTNode<int, int>* val = t.Find_R(10);
	if (val == NULL)
	cout << "not find" << endl;
	t.InOrder();
}
void TestRemove()
{
	//测试删除
	BSTree<int, int> t;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		t.Insert(a[i], i);
	}
	t.Insert(12, 12);

	/*for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)//非递归删除
	{
	t.Remove(a[i]);
	}
	t.Remove(12);
	t.InOrder();*/

	t.InOrder();
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)//递归删除
	{
		t.Remove_R(a[i]);
	}
	t.Remove_R(12);
	t.InOrder();

}