#include<iostream>
#include<queue>
using namespace std;

struct BinaryTreeNode
{
	BinaryTreeNode(const int& d)
	:_data(d)
	, _left(NULL)
	, _right(NULL)
	{}
	int _data;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};
void LevelOrderBinary(BinaryTreeNode* root)
{
	if (root == NULL)
		return;
	queue<BinaryTreeNode*> q;
	
	q.push(root);
	while (!q.empty())
	{
		BinaryTreeNode* node = q.front();
		q.pop();
		cout << node->_data<< " ";
		if (node->_left)
			q.push(node->_left);
		if (node->_right)
			q.push(node->_right);
	}

}
int main()
{
	BinaryTreeNode* root = new BinaryTreeNode(8);
	BinaryTreeNode* node1=root->_left = new BinaryTreeNode(6);
	BinaryTreeNode* node2=root->_right = new BinaryTreeNode(10);
	node1->_left = new BinaryTreeNode(5);
	node1->_right = new BinaryTreeNode(7);
	node2->_left = new BinaryTreeNode(9);
	node2->_right = new BinaryTreeNode(11);
	LevelOrderBinary(root);
	getchar();
	return 0;
}