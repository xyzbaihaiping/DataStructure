#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int g_maxValue = 6;
//�ݹ鷨
void Probability(int num, int current, int sum, int* probability)
{
	if (current == 1)
		probability[sum - num]++;
	else
	{
		for (int i = 1; i <= g_maxValue; i++)
		{
			Probability(num,current-1,i+sum,probability);
		}
	}
}
void Probability(int num, int *probability)
{
	for (int i = 1; i <= g_maxValue; i++)
		Probability(num, num, i, probability);

}
void PrintProbability(int num)
{
	if (num <= 0)
		return;
	int maxSum = g_maxValue*num;
	int *probability = new int[maxSum - num - 1];
	for (int i = num; i <= maxSum; i++)
		probability[i - num] = 0;

	Probability(num,probability);

	int total = pow((double)g_maxValue,num);
	for (int i = num; i <= maxSum; i++)
	{
		double rate = ((double)probability[i-num]) / total;
		cout << "num :" << i << "rate : " << rate << endl;
	}

	delete[] probability;
}

void PrintProbability(int num)
{
	if (num <= 0)
		return;
	int *probability[2];

	probability[0] = new int[g_maxValue*num + 1];
	probability[1] = new int[g_maxValue*num + 1];

	for (int i = 0; i < g_maxValue*num + 1; i++)
	{
		probability[0][i] = 0;
		probability[1][i] = 0;
	}
	int flag = 0;
	for (int i = 1; i < g_maxValue; i++)
		probability[flag][i] = 1;

	for (int k = 2; k < num; k++)
	{
		for (int i = 0; i < k; i++)
			probability[1 - flag][i] = 0;
		for (int i = k; i <= g_maxValue*k; i++)
		{
			probability[1 - flag][i] = 0;
			for (int j = 1; j <= i && j <= g_maxValue; j++)
			{
				probability[1 - flag][j] += probability[flag][i - j];
			
			}
			flag = 1 - flag;
		}
	}
	int total = pow((double)g_maxValue, num);
	for (int i = num; i <= num*g_maxValue; i++)
	{
		double rate = ((double)probability[flag][i - num]) / total;
		cout << "num :" << i << "rate : " << rate << endl;
	}

	delete[] probability[0];
	delete[] probability[1];

}


int main()
{

	PrintProbability(2);
	getchar();
	return 0;
}