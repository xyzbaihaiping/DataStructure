#include<iostream>
using namespace std;

struct BinaryTreeNode
{
	BinaryTreeNode(const int& value)
	:_value(value)
	, _left(NULL)
	, _right(NULL)
	{}
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

void MirrorRecursively(BinaryTreeNode* root)
{
	if (root == NULL || (root->_left==NULL && root->_right==NULL))
		return;
	if (root->_left != NULL || root->_right!=NULL)
	{
		BinaryTreeNode* tmp = root->_left;
		root->_left = root->_right;
		root->_right = tmp;
		if (root->_left)
		MirrorRecursively(root->_left);
		if (root->_right)
		MirrorRecursively(root->_right);
	}
}
void Test()
{
	BinaryTreeNode* root = new BinaryTreeNode(8);
	BinaryTreeNode* left1 = new BinaryTreeNode(6);
	BinaryTreeNode* right1 = new BinaryTreeNode(10);
	BinaryTreeNode* left2 = new BinaryTreeNode(5);
	BinaryTreeNode* right2 = new BinaryTreeNode(7);
	BinaryTreeNode* left3 = new BinaryTreeNode(9);
	BinaryTreeNode* right3 = new BinaryTreeNode(11);
	root->_left = left1;
	root->_right = right1;
	left1->_left = left2;
	left1->_right = right2;
	right1->_left = left3;
	right1->_right = right3;
	MirrorRecursively(root);

}
int main()
{
	Test();
	return 0;
}