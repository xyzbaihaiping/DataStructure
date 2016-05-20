#include<iostream>
using namespace std;
bool invalid = false;
//double Calculate(double base,int exp)
//{
//	double result = 1;
//	while (exp--)
//	{
//		result *= base;
//	}
//	return result;
//}
double Calculate(double base,int exp)
{
	if (exp == 0)
		return 1;
	if (exp == 1)
		return base;
	double result = Calculate(base, exp>>1);
	result *= result;
	if (exp & 1 == 1)
		result *= base;
	return result;
}
bool Equal(double left, double right)
{
	const double max = 0.00000001;
	if ((left - right) > -max && (left - right) < max)
		return true;
	else
		return false;
}
double MyPower(double base,int exp)
{
	double result = 1;
	if ( exp < 0.0 && Equal(base,0.0))
	{
		invalid = true;
		return 0.0;
	}
	if (exp < 0)
		result = 1 / Calculate(base, (-1)*exp);
	else
		result = Calculate(base, exp);
	return result;
}
int main()
{
	cout << MyPower(2,-2) << endl;
	getchar();
	return 0;
}