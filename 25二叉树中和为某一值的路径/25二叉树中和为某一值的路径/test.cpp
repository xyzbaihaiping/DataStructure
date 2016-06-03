#include<iostream>
#include<vector>
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
void FindPath(BinaryTreeNode* root, int expectSum, vector<int>& path, int& curSum)
{
	curSum += root->_value;
	path.push_back(root->_value);
	//如果是叶子节点，并且路径之和等于expectSum,则打印这条路径
	if (root->_left == NULL && root->_right == NULL && curSum == expectSum)
	{
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
		cout << endl;
	}
	//若不是叶子节点，遍历它的子节点
	if (root->_left != NULL)
		FindPath(root->_left,expectSum,path,curSum);
	if (root->_right != NULL)
		FindPath(root->_right, expectSum, path, curSum);
	//返回父节点之前，路径中删除该节点，当前和curSum减去当前节点值
	curSum -= root->_value;
	path.pop_back();
}

void FindPath(BinaryTreeNode* root,int expectSum)
{
	if (root == NULL)
		return;
	vector<int> path;
	int curSum = 0;
	FindPath(root, expectSum, path, curSum);
}
void Test()
{
	BinaryTreeNode* root=new BinaryTreeNode(10);
	BinaryTreeNode* left1 =root->_left= new BinaryTreeNode(5);
	BinaryTreeNode* right2 = root->_right=new BinaryTreeNode(12);
	BinaryTreeNode* left1l =left1->_left= new BinaryTreeNode(4);
	BinaryTreeNode* right1r = left1->_right=new BinaryTreeNode(7);
	FindPath(root,22);
}
int main()
{
	Test();
	getchar();
	return 0;
}