#include<iostream>
using namespace std;

bool g_InvalidInput = false;
int FindGreatestSumOfSubArray(int *a, int size)//·½·¨Ò»
{
	if (a == NULL || size <= 0)
	{
		g_InvalidInput = true;
		return 0;
	}
	g_InvalidInput = false;
	int result = 0;
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (sum <= 0)
			sum = a[i];
		else
            sum += a[i];
		if (sum>result)
			result = sum;
	}
	return result;
}

int main()
{
	int a[] = {1,-2,3,10,-4,7,2,-5};
	int size = sizeof(a) / sizeof(a[0]);
	int result=FindGreatestSumOfSubArray(a,size);
	cout << result << endl;
	getchar();
	return 0;
}