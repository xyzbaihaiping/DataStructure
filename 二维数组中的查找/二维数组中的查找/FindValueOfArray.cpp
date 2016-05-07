#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int FindValueOfArray(int *array,int rows,int cols,int value)
{
	int row = 0;
	int col = 0;

	if (array != NULL && rows > 0 && cols > 0)
	{
        row = 0;
	    col = cols-1;
		while (row <rows && col >= 0)
		{
			if (value < array[row * cols + col])
			{
				col -= 1;
			}
			else if (value > array[row *cols + col])
			{
				row += 1;
			}
			else
				return 1;
		}
	}
	return 0;
}
int main()
{
	int ret = 0;
	int arr[]= { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
		 
	ret=FindValueOfArray(arr,4,4, 7);
	if (ret==1)
		printf("exist");
	else
		printf("not exist");
	system("pause");
	return 0;
}