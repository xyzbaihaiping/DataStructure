#include<iostream>
using namespace std;

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};
bool DoesSubTree(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;
	return DoesSubTree(root1->_left, root1->_left) && DoesSubTree(root1->_right, root2->_right);

}
bool HasSubTree(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
	bool result = false;
	if (root1 && root2)
	{
		if (root1->_value == root2->_value)
			result = DoesSubTree(root1, root2);
		if (!result)
			result = HasSubTree(root1->_left, root2->_left);
		if (!result)
			result = HasSubTree(root1->_right, root2->_right);
	}
	return result;
}
