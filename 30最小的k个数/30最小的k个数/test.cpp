#include<iostream>
#include<vector>
#include<set>
#include <functional>

using namespace std;

//int PartSort(int *a, int left, int right)
//{
//
//	int prev = left - 1;
//	int cur = left;
//	while (cur < right)
//	{
//		if (a[cur] < a[right] && ++prev != cur)
//			swap(a[cur], a[prev]);
//		++cur;
//	}
//	swap(a[++prev], a[right]);
//	return prev;
//}

//void GetLeastNumbers(int *a, int *output, int n,int k)
//{
//	if (a == NULL || output == NULL || k>n || n <= 0 || k<=0)
//		return;
//	int start = 0;
//	int end = n - 1;
//	int index = 0;
//	index = PartSort(a, start, end);
//	while (index != k - 1)
//	{
//		if (index > k - 1)
//		{
//			end = index - 1;
//			index = PartSort(a,start,end);
//		}
//		else
//		{
//			start = index + 1;
//			index = PartSort(a, start, end);
//		}
//	}
//	for (int i = 0; i < k; i++)
//	{
//		output[i] = a[i];
//	}
//}

typedef multiset<int, greater<int> > intset;
typedef multiset<int, greater<int> >::iterator  setiterator;

void GetLeastNumbers(const vector<int>& a, intset& leastNum, size_t k)
{
	leastNum.clear();
	if (k < 1 || a.size() < k)
		return;
	vector<int>::const_iterator iter = a.begin();
	for (; iter != a.end(); iter++)
	{
		if ((leastNum.size()) < k)
			leastNum.insert(*iter);
		else
		{
			setiterator itergreater = leastNum.begin();
			if (*iter < *(leastNum.begin()))
			{
				leastNum.erase(itergreater);
				leastNum.insert(*iter);
			}
		
		}
	}
}
int main()
{
	/*int a[] = { 9, 8, 7, 6,18,45,9,2,0,35};
	int size = sizeof(a) / sizeof(a[0]);
	int k = 4;
	int *output = new int[k];*/
	/*GetLeastNumbers(a, output, size, k);
	for (int i = 0; i < k; i++)
		cout << output[i] << endl;*/
	vector<int> a;
	int k = 4;
	a.push_back(4);
	a.push_back(6);
	a.push_back(8);
	a.push_back(9);
	a.push_back(2);
	a.push_back(6);
	a.push_back(3);
	a.push_back(0);
	intset leastNum;
	GetLeastNumbers(a, leastNum,k);
	setiterator itergreater = leastNum.begin();
	while (itergreater != leastNum.end())
	{
		cout << *itergreater << endl;
		itergreater++;
	}
	getchar();
	return 0;
}