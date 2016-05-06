#define _CRT_SECURE_NO_WARNINGS
#include "AutoPtr.h"
int main()
{
	/*AutoPtr<int> ap2(ap1);
	AutoPtr<int> ap3(ap2);
	*ap2 = 1;

	cout << *ap3 << endl;*/
	AutoPtr<int> ap1(new int(1));
	if (1)
	{
		AutoPtr<int> ap2(ap1);
	}
	*ap1 = 3;
	getchar();
	return 0;
}