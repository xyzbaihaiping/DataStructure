#include<iostream>
using namespace std;

bool IsUgly(int number)
{
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;
	return (number == 1) ? true : false;
}
int GetUglyNumber1(int index)
{
	if (index <= 0)
		return 0;
	int number = 0;
	int UglyFound = 0;
	while (UglyFound < index)
	{
		++number;
		if (IsUgly(number))
		{
			UglyFound++;
		}
	}

	return number;
}
int Min(int num1,int num2,int num3)
{
	
	return (num1 > num2 ? ((num2 > num3) ? num3 : num2) : (num1 > num3 ? num3 : num1));

}
int GetUglyNumber2(int index)
{
	if (index <= 0)
		return 0;
	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *Multiply2 = pUglyNumbers;
	int *Multiply3 = pUglyNumbers;
	int *Multiply5 = pUglyNumbers;
	while (nextUglyIndex < index)
	{
		int min = Min(*Multiply2 * 2, *Multiply3 * 3, *Multiply5 * 5);
		pUglyNumbers[nextUglyIndex] = min;

		while (*Multiply2 * 2 <= pUglyNumbers[nextUglyIndex])
			++Multiply2;
	    while (*Multiply3 * 3 <= pUglyNumbers[nextUglyIndex])
			 ++Multiply3;
	    while (*Multiply5 * 5 <= pUglyNumbers[nextUglyIndex])
			 ++Multiply5;
			 
		nextUglyIndex++;
	}
	int Ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return Ugly;
}


int main()
{
	int Ugly=GetUglyNumber2(1500);
	cout << Ugly << endl;
	getchar();
	return 0;
}