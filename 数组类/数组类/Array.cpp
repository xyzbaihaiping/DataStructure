#include<iostream>
using namespace std;
typedef int DateType;
class Array
{
public:
	Array(int size=10)
	:parr(new DateType[size])
	, _size(size)
	{
	}
	Array(const Array& arr)
	{
		_size = arr._size;
		parr = new DateType[_size];
		for (int i = 0; i < _size; i++)
		{
			parr[i] = arr.parr[i];
		}
		//memcpy(parr, arr.parr, _size);
	}
	DateType& operator[](int i)
	{
		return parr[i];	
	}
	Array& operator=(const Array& arr)
	{
		if (this != &arr)
		{
			delete[] parr;
			_size = arr._size;
			parr = new DateType[_size];
		}
		return *this;
	}
	~Array()
	{
		if (parr != NULL)
		{
			delete[] parr;
			parr = NULL;
		}
	}
private:
	DateType *parr;
	int _size;
};
int main()
{
	Array arr;
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i]<<" ";
	}
	Array arr1(arr);
	Array arr2 = arr;
	for (int i = 0; i < 10; i++)
	{
		cout << arr1[i]<<" ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arr2[i]<<" ";
	}
	cout << endl;

	getchar();
	return 0;
}