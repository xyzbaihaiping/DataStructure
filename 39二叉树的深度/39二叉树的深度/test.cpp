#include<iostream>
using namespace std;
struct BinaryTreeNode
{
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	int _value;
	BinaryTreeNode(int value)
		:_value(value)
		, _left(NULL)
		, _right(NULL)
	{}
};

int Depth(BinaryTreeNode* root)
{
	if (root == NULL)
		return 0;
	int left = Depth(root->_left);
	int right = Depth(root->_right);
	return (left > right) ? left + 1 : right + 1;
}

//bool IsBalanced(BinaryTreeNode* root)//判断二叉树是否平衡 效率低
//{
//	if (root == NULL)
//		return true;
//	int left = Depth(root->_left);
//	int right = Depth(root->_right);
//	if (abs(right - left) > 1)
//		return false;
//	return IsBalanced(root->_left) && IsBalanced(root->_right);
//}

bool IsBalance(BinaryTreeNode* root, int& depth)
{
	if (root == NULL)
	{
		depth = 0;
		return true;
	}
	int left = 0;
	int right = 0;
	if (IsBalance(root->_left, left) && IsBalance(root->_right, right))
	{
		if (abs(right - left) < 2)
		{
			depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}
int main()
{
	BinaryTreeNode* root =new BinaryTreeNode(1);
	BinaryTreeNode* left=root->_left = new BinaryTreeNode(2);
	BinaryTreeNode* right = root->_right= new BinaryTreeNode(3);
	BinaryTreeNode* leftl=left->_left = new BinaryTreeNode(4);
	BinaryTreeNode* rightl = right->_left=new BinaryTreeNode(5);
	BinaryTreeNode* rightr =right->_right= new BinaryTreeNode(6);
	BinaryTreeNode* rightrl =rightr->_left= new BinaryTreeNode(7);

	cout << Depth(root) << endl;
	getchar();
	return 0;
}