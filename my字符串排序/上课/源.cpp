#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
void Permutation(char *str, char *begin)
{
	if (*begin == '\0')
	{
		cout << str << endl;
		return;
	}
	char *start = begin;
	for (start = begin; *start!='\0'; start++)
	{
		/*char tmp = *start;
		*start = *begin;
		*begin = tmp;*/
		swap(*start, *begin);
		Permutation(str, begin+1);
		swap(*start, *begin);
		/*tmp = *start;
		*start = *begin;
		*begin = tmp;*/
	}
}
void Permutation(char *str)
{
	if (str == NULL)
	{
		return;
	}
	char *begin = str;
	Permutation(str, begin);
}
int main()
{
	char str[] = "abc";
	Permutation(str);
	getchar();
	return 0;
}