#include<iostream>
#include<assert.h>
using namespace std;

void ReOrderOddEven(int *data,size_t len,bool (*Func)(int))
{
	assert(data && len>0);
	int *left = data;
	int *right = data + len - 1;
	while (left < right)
	{
		while (left < right &&  !Func(*left))
			left++;
		while (left < right && Func(*right))
			right--;
		if (left < right)
		{
			int tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
}
bool IsEven(int val)
{
	return (val & 0x1) == 0;
}
void ReOrderOdd(int *data, size_t len)
{
	ReOrderOddEven(data,len,IsEven);
}
int main()
{
	int a[] = {1,2,4,6,3,7,5,9,6,0,11,8};
	size_t size = sizeof(a) / sizeof(a[0]);
	ReOrderOdd(a, size);
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	getchar();
	return 0;
}