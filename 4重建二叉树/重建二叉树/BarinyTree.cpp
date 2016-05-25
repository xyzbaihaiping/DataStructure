
#include<iostream>
using namespace std;

struct BarinyTreeNode
{
	BarinyTreeNode(const int& data)
	:_data(data)
	, _left(NULL)
	, _right(NULL)
	{}
	int _data;
	BarinyTreeNode* _left;
	BarinyTreeNode* _right;
};
BarinyTreeNode* ConStructCore(int *startPrevorder, int *endPrevorder, int *startInorder, int *endInorder)
{
	BarinyTreeNode* root = new BarinyTreeNode(startPrevorder[0]);

	int* rootInorder = startInorder;

	if (startPrevorder == endPrevorder && startInorder == endInorder && *startPrevorder == *startInorder)
		return root;

	while (rootInorder <= endInorder && *rootInorder != startPrevorder[0])
	{
		rootInorder++;
	}
	int leftlen = rootInorder - startInorder;
	int *leftPreorderEnd = startPrevorder + leftlen;

	if (leftlen > 0)
	{
		root->_left = ConStructCore(startPrevorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftlen < endPrevorder - startPrevorder)
	{
		root->_right = ConStructCore(leftPreorderEnd + 1, endPrevorder, rootInorder + 1, endInorder);
	}
	return root;
}
BarinyTreeNode* ConStruct(int *prevorder, int *inorder, int size)
{
	if (prevorder == NULL || inorder == NULL || size <= 0)
		return NULL;

	return  ConStructCore(prevorder, prevorder+size-1, inorder,inorder+size-1);
}
int main()
{
	int prevorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int size = sizeof(prevorder) / sizeof(prevorder[0]);
	BarinyTreeNode* root = NULL;
	root = ConStruct(prevorder, inorder, size);

	getchar();
	return 0;
}