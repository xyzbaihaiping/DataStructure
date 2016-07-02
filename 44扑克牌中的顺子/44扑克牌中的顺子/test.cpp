#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


int Compare(const void*left, const void* right)
{
	return *(int *)left - *(int *)right;
}
bool IsContinuous(int *num, int length)
{
	if (num == NULL || length <= 0)
		return false;
	qsort(num,length,sizeof(int),Compare);

	int numOfZero = 0;
	int numOfGap = 0;

	for (int i = 0; i < length; i++)
	{
		if (num[i] == 0)
			numOfZero++;
		int gap = 1;
		if (num[i] == num[i + 1])
			return false;
		while (i + 1 < length && num[i] + gap < num[i + 1])
		{
			numOfGap++;
			gap++;
		}
	}
	if (numOfGap <= numOfZero)
		return true;
	else
		return false;
}
int main()
{
	int a[] = {0,2,3,5,0};
	cout << IsContinuous(a,5) << endl;
	getchar();
	return 0;
}