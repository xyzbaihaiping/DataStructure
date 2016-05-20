#include "BinaryTreeThread.h"

int main()
{
	int array1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int array2[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	int size = sizeof(array1) / sizeof(array1[0]);

	BinaryTreeThd<int> th1(array1, size, '#');
	th1.InOrderTheading();
	th1.InOrderThd();
	BinaryTreeThd<int> th2(array1, size, '#');
	th2.PrevOrderTheading();
	th2.PrevOrderThd();
	BinaryTreeThd<int> th3(array1, size, '#');
	th3.PostOrderTheading();
	getchar();
	return 0;
}