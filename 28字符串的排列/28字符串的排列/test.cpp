#include<iostream>
using namespace std;
void PerMutation(char *pStr, char *pBegin)
{
	if (*pBegin == '\0')
		cout << pStr << endl;
	else
	{
		for (char *pch = pBegin; *pch != '\0'; ++pch)
		{
			swap(*pch, *pBegin);
			PerMutation(pStr, pBegin + 1);
			swap(*pch, *pBegin);
		}
	}
}
void PerMutation(char *pStr)
{
	if (pStr == NULL)
		return;
	PerMutation(pStr, pStr);
}
int main()
{
	char str[] = "abc";
	PerMutation(str);
	getchar();
	return 0;
}