#pragma once

template<class K,class V>
struct AVLTreeNode
{
	K _key;
	V _value;
	AVLTreeNode<K, V>* _parent;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	int _bf;//Æ½ºâÒò×Ó
	AVLTreeNode(const K& key, const V& value)
		:_value(value)
		, _key(key)
		, _bf(0)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
	{}
};
template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V>* Node;
public:
	AVLTree()
		:_root(NULL)
	{}
	bool Insert(const K& key,const V& value)
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
				return false;
		}
		cur = new Node(key, value);
		cur->_parent = parent;
		if (parent->_key > key)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		
		while (parent)
		{
			if (parent->_left == cur)
			{
				parent->_bf--;
			}
			else
				parent->_bf++;

			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			else
			{
				if (cur->_bf == 1)
				{
					if (parent->_bf == 2)
					{
						RotateL(parent);
					}
					else
					{
						RotateLR(parent);
					}
				}
				else
				{

					if (parent->_bf == -2)
					{
						RotateR(parent);
					}
					else
					{
						RotateRL(parent);
					}
				}
				break;
			}
		
		}
	}

	void RotateR(Node* parent);
	void RotateRL(Node* parent);
	void RotateLR(Node* parent);
	void RotateL(Node* parent);


private:
	Node* _root;
};
