#include<iostream>

using namespace std;

char FirstNotRepeatingChar(char *str)
{
	if (str == NULL)
		return '\0';

	int *charStr = new int[256];
	memset(charStr, 0, sizeof(int)* 256);
	char *pstr = str;
	while (*pstr != '\0')
	{
		++charStr[*pstr];
		pstr++;
	}
	while (*str != '\0')
	{
		if (charStr[*str] == 1)
			return *str;
		str++;
	}
    return '\0';
}
int main()
{

	//char *str = "abacbcdedffg";
	char* str = "";
	char ch=FirstNotRepeatingChar(str);
	cout << ch << endl;
	getchar();
	return 0;
}