#include<iostream>
using namespace std;

void FindNumsAppearOnce(int *data, int length, int *num1, int *num2)
{
	if (data == NULL || length <= 0)
		return;

	unsigned int result = 0;
	for (int i = 0; i < length; i++)
	{
		result^=data[i];
	}
	int index = 0;
	while (result)
	{
		if (1 & result == 1)
		{
			break;
		}
		else
		{
			result >>= 1;
			index++;
		}
	}
	*num1 = 0;
	*num2 = 0;
	for (int i = 0; i < length; i++)
	{
		int num = data[i] >> index;
		if (num & 1 == 1)
			*num1 ^= data[i];
		else
			*num2 ^= data[i];
	}
}

int main()
{
	int a[] = {4,6,7,6,3,4,9,7,0,2,3,2};
	int num1 = 0;
	int num2 = 0;
	FindNumsAppearOnce(a,sizeof(a)/sizeof(a[0]),&num1,&num2);
	cout << "num1:" << num1 << endl;
	cout << "num2:" << num2 << endl;
	getchar();
	return 0;
};