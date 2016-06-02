#include<iostream>

using namespace std;

bool VerifySquenceOfBST(int *squence, size_t n)
{
	if (squence == NULL || n <= 0)
		return false;
	int root = squence[n - 1];
	int i = 0;
	for (; i < n - 1; i++)
	{
		if (squence[i]>root)
			break;
	}
	int j = i;
	for (; j < n - 1; j++)
	{
		if (squence[j] < root)
			return false;
	}
	bool left = true;
	if (i>0)
	{
		left = VerifySquenceOfBST(squence, i);
	}
	bool right = true;
	if (i < n - 1)
	{
		right = VerifySquenceOfBST(squence + i, n -1-i);
	}
	return (left && right);
}
int main()
{
	int a[] = {5,7,6,9,11,10,8};
	int b[] = {7,4,6,5};
	int size = sizeof(a) / a[0];
	cout << VerifySquenceOfBST(a, size) << endl;
	cout << VerifySquenceOfBST(b, size) << endl;

	getchar();
	return 0;
}