#include"date.h"
int main()
{
	Date d1(2016, 1, 7);
	Date d2(2016,1,3);
	Date d;
	int days = 100;

	d = d1 + days;
    cout << d1 <<" + "<< days <<": "<< d << endl;
	d = d1 - days;
	cout << d1 << " - " << days << ": " << d << endl;
	days = d1 - d2;
	cout <<d1 <<" - "<< d2<<": "<<days<< endl;
	getchar();
	return 0;
}