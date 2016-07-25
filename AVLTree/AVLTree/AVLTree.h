#pragma once

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	K _key;
	V _value;

	int _bf;			// 平衡因子

	AVLTreeNode(const K& key, const V& value)
		:_bf(0)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
		,_key(key)
		,_value(value)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef  AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(NULL)
	{}

	~AVLTree()
	{
		_Destory(_root);
		_root = NULL;
	}

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
				return false;
			}
		}

		cur = new Node(key, value);

		if (parent->_key < key)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 检查树是否平衡
		// 1.更新平衡因子，不满足条件时，进行旋转
		while(parent)
		{
			if (cur == parent->_left)
				parent->_bf--;
			else 
				parent->_bf++;

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == -1 || parent->_bf == 1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			else // 2 -2
			{
				// 旋转处理
				if (cur->_bf == 1)
				{
					if (parent->_bf == 2)
						RotateL(parent);
					else // -2
						RotateLR(parent);
				}
				else
				{
					if (parent->_bf == -2)
						RotateR(parent);
					else //2
						RotateRL(parent);
				}

				break;
			}
		}

		return true;
	}


	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;

		Node* ppNode = parent->_parent;
		parent->_parent = subR;
		subR->_parent = ppNode;

		if (ppNode == NULL)
		{
			_root = subR;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;
		}

		parent->_bf = subR->_bf = 0;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppNode = parent->_parent;

		parent->_parent = subL;
		subL->_parent = ppNode;

		if (ppNode == NULL)
		{
			_root = subL;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;
		}

		parent->_bf = subL->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		// 根据subLR的平衡因子修正其他节点的平衡因子
		if (bf == -1)
		{
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)
		{
			subL->_bf = -1;
			parent->_bf = 0;
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			subR->_bf = 1;
			parent->_bf = 0;
		}
	}

	void InOrder()
	{
		_InOrder(_root);
		cout<<endl;
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		_InOrder(root->_left);
		cout<<root->_key<<" ";
		_InOrder(root->_right);
	}

	bool IsBlance()
	{
		return _IsBlance(_root);
	}

	int _Height(Node* root)
	{
		if (root == NULL)
			return 0;

		int left = _Height(root->_left);
		int right = _Height(root->_right);

		return left>right ? left+1:right+1;
	}

	bool _IsBlance(Node* root)
	{
		if (root == NULL)
			return true;

		int left = _Height(root->_left);
		int right = _Height(root->_right);
		
		if (right - left != root->_bf || abs(right-left) > 1)
		{
			cout<<"节点的平衡因子异常:";
			cout<<root->_key<<endl;

			return false;
		}

		return _IsBlance(root->_left) && _IsBlance(root->_right);
	}

	void _Destory(Node* root)
	{
		if (root == NULL)
			return;

		_Destory(root->_left);
		_Destory(root->_right);

		delete root;
	}


protected:
	Node* _root;
};

void TestTree()
{
	int a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
	AVLTree<int, int> t;

	for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
	{
		t.Insert(a[i], i);
	}

	t.InOrder();

	cout<<"是否平衡?"<<t.IsBlance()<<endl;
}

void TestTree_SP()
{
	int a[] = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
	AVLTree<int, int> t;

	for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
	{
		t.Insert(a[i], i);
	}

	t.InOrder();

	cout<<"是否平衡?"<<t.IsBlance()<<endl;
}
