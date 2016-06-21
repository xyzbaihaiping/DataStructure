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