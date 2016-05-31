#include<iostream>
#include<stack>
using namespace std;

bool IsPopOrder(const int *pPush, const int *pPop, int length)
{
	bool IsOrder = false;
	if (pPush == NULL || pPop == NULL || length <= 0)
		return IsOrder;
	const int *pNextPush = pPush;
	const int *pNextPop = pPop;
	stack<int> sData;
	while (pNextPop - pPop < length)
	{
		while (sData.empty() || sData.top() != *pNextPop)
		{
			if (pNextPush - pPush == length)
			{
				break;
			}
			sData.push(*pNextPush);
			pNextPush++;
		}
		if (sData.top() != *pNextPop)
			break;
		sData.pop();
		pNextPop++;
	}
	if (sData.empty() && pNextPop - pPop == length)
		IsOrder = true;
	return IsOrder;
}
int main()
{
	int a[5] = {1,2,3,4,5};
	int b[5] = { 4, 3, 5, 2,1 };
	bool ret = IsPopOrder(a,b,5);
	cout << ret << endl;
	getchar();
	return 0;
}