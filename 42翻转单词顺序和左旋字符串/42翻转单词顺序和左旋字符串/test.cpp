#include<iostream>
#include<string.h>
using namespace std;

void Reverse(char *left, char *right)
{
	if (left == NULL || right == NULL)
		return;
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}


void ReverseSentence(char *str)
{
	if (str == NULL)
		return;
	
	char *pstr = str;
	char *start = pstr;
	while (*pstr != '\0')
	{
		start = pstr;
		while (*pstr != ' '&& *pstr !='\0')
			pstr++;
		Reverse(start,pstr-1);
		if (*pstr != '\0')
		    pstr++;
	}
	Reverse(str, pstr-1);
}
void LeftRotateString(char *str, int n)
{
	if (str == NULL || n <= 0)
		return;
	int length = strlen(str);
	Reverse(str, str+n-1);
	Reverse(str+n,str+length-1);
	Reverse(str,str+length-1);

}

int main()
{
	char a[] = "I am a student.";

	char str[] = "abcdeg";
	ReverseSentence(a);
	cout << a << endl;

	LeftRotateString(str,2);
	cout << str << endl;
	getchar();
	return 0;
}