#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


const int g_MaxNumberLen = 10;

char* g_combine1 = new char[g_MaxNumberLen * 2 + 1];
char* g_combine2 = new char[g_MaxNumberLen * 2 + 1];

int compare(const void* strNumber1, const void* strNumber2)
{
	strcpy(g_combine1,*(const char**)strNumber1);
	strcat(g_combine1, *(const char**)strNumber2);
	strcpy(g_combine2, *(const char**)strNumber2);
	strcat(g_combine2, *(const char**)strNumber1);
	return strcmp(g_combine1, g_combine2);
}


void PrintMinNumber(int *a,int length)
{
	if (a == NULL || length <= 0)
		return;
	char** strNumber = (char**)new int[length];
	for (int i = 0; i < length; i++)
	{
		strNumber[i] = new char[g_MaxNumberLen];
		_itoa(a[i],strNumber[i], 10);
	}
	qsort(strNumber, length, sizeof(char*), compare);
	for (int i = 0; i < length; i++)
	{
		cout << strNumber[i];
	}
	cout << endl;
	for (int i = 0; i < length; i++)
		delete strNumber[i];
	delete[] strNumber;
}



int main()
{

	int a[] = {3,32,321};
	PrintMinNumber(a, 3);
	getchar();
	return 0;
}