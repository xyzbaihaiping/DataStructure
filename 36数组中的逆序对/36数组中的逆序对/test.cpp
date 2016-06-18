#include<iostream>
using namespace std;
int InversepairsCore(int *data, int *copy, int start, int end)
{

	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}
	int length = start + (end - start) / 2;
	int left = InversepairsCore(data,copy,start,length);
	int right = InversepairsCore(data,copy,length+1,end);
	int i = length;
	int j = end;
	int count = 0;
	int indexcopy = end;
	while (i >= start && j >= length + 1)
	{
		if (data[i] > data[j])
		{
			copy[indexcopy--] = data[i--];
			count += j - length;
		}
		else
		{
			copy[indexcopy--] = data[j--];
		}
	}
	while (i >= start)
	{
		copy[indexcopy--] = data[i--];
	}
	while (j >= length  + 1)
	{
		copy[indexcopy--] = data[j--];
	}
	return left + right + count;
}
int InversePairs(int *data, int length)
{
	if (data == NULL || length <= 0)
		return 0;
	int* copy = new int[length];
	for (int i = 0; i < length; i++)
		copy[i] = data[i];
	int count = InversepairsCore(data,copy,0,length-1);
	delete[] copy;
	return count;

}
int main()
{
	int a[] = {7,5,6,4};
	int size = sizeof(a) / sizeof(a[0]);
	cout << InversePairs(a, size) << endl;
	getchar();
	return 0;
}