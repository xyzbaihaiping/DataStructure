#define _CRT_SECURE_NO_WARNINGS

#include "BinaryTree.hpp"
void TestBinaryTree()
{
	int array1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int array2[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	int size = sizeof(array1) / sizeof(array1[0]);
	BinaryTree<int> tree(array1, '#', size);
	tree.PreOrder();//先根遍历
	tree.InOrder();//中序遍历
	tree.PostOrder();//后根遍历
	tree.LevelOrder();//层序遍历
	cout << "size:"<<tree.size() << endl;//二叉树中元素个数
	cout << "depth："<<tree.Depth() << endl;//二叉树深度
	cout << "叶子节点个数："<<tree.LeafSize() << endl;//二叉树叶子节点个数

	BinaryTree<int> tree1(tree);//拷贝
	tree.PreOrder();
	BinaryTree<int> tree3;
	tree3 = tree;//赋值
	tree3.PreOrder();
}

int main()
{
	TestBinaryTree();
	getchar();
	return 0;
}