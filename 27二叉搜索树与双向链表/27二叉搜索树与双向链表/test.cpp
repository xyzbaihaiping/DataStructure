#include<iostream>

using namespace std;

struct BinaryTreeNode
{
	BinaryTreeNode(const int& d)
	:_value(d)
	, _left(NULL)
	, _right(NULL)
	{
	}
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};
void ConvertNode(BinaryTreeNode* Node, BinaryTreeNode** LastListNode)
{
	if (Node == NULL)
		return;
	BinaryTreeNode* cur = Node;
	if (cur->_left != NULL)
		ConvertNode(cur->_left, LastListNode);
	cur->_left = *LastListNode;
	if (*LastListNode != NULL)
		(*LastListNode)->_right = cur;
	*LastListNode = cur;

	if (cur->_right!=NULL)
		ConvertNode(cur->_right, LastListNode);
}
BinaryTreeNode* Convert(BinaryTreeNode* root)
{
	if (root == NULL)
		return NULL;
	BinaryTreeNode* LastListNode = NULL;
	ConvertNode(root, &LastListNode);
	BinaryTreeNode* HeadListNode = LastListNode;
     while (HeadListNode != NULL && HeadListNode->_left != NULL)
		HeadListNode = HeadListNode->_left;
	return HeadListNode;
}
void Test()
{
	BinaryTreeNode* root = new BinaryTreeNode(10);
	BinaryTreeNode* left1 = root->_left = new BinaryTreeNode(6);
	BinaryTreeNode* right2 = root->_right = new BinaryTreeNode(14);
	BinaryTreeNode* left1l = left1->_left = new BinaryTreeNode(4);
	BinaryTreeNode* right1r = left1->_right = new BinaryTreeNode(8);
	BinaryTreeNode* left2l = right2->_left = new BinaryTreeNode(12);
	BinaryTreeNode* right2r = right2->_right = new BinaryTreeNode(16);
	BinaryTreeNode* head=Convert(root);
	BinaryTreeNode* cur = head;
	while (cur)
	{
		cout << cur->_value << " ";
		cur = cur->_right;
	}
}
int main()
{
	Test();
	getchar();
	return 0;
}