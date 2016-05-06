#include"date.h"

void Test()
{
	Date date(2014, 3, 15);
	Date da;
	Date da1;
	int days = 17;
	da = date + days;
	cout << date << "+" << days << "=" << da << endl;
	da1 = da - days;
	cout << da << "-" << days << "=" << da1 << endl;
	Date date1(2015, 12, 30);
	Date date2(2016, 1, 6);
	days = date2 - date1;
	cout << date2 << "-" << date1 << "=" << days << endl;
}
int main()
{
	Test();
	getchar();
	return 0;
}