#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	Date(const Date& date)
	{
		_year = date._year;
		_month = date._month;
		_day = date._day;
	}
	Date& operator=(const Date& date)
	{
		_year = date._year;
		_month = date._month;
		_day = date._day;
		return *this;
	}
	bool IsLeapyear(int year)const;
	int DaysOfMonth(int year, int month)const;
	int PassDays(int year)const;
	friend Date operator+(const Date &data1, int days);
	friend Date operator-(const Date &data1, int days);
	friend int operator-(const Date &data1, const Date &data2);
	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream &input, Date& date);
	int Week();

private:
	int _year;
	int _month;
	int _day;
};
bool Date::IsLeapyear(int year)const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int Date::DaysOfMonth(int year, int month)const
{
	int days = 0;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		days = 31;
		break;
	case 2:
		days = 28 + IsLeapyear(year);
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		days = 30;
		break;
	}
	return days;
}

int Date::PassDays(int year)const
{
	int days = 0;
	int y = 0;
	int m = 0;
	for (y = year; y < _year; y++)
	{
		days += 365 + IsLeapyear(y);
	}
	for (m = 1; m < _month; m++)
	{
		days += DaysOfMonth(_year, m);
	}
	days += _day;
	return days;
}
Date operator+(const Date &date, int days)
{
	Date d(date);
	d._day += days;
	while (d._day > d.DaysOfMonth(d._year, d._month))
	{
		d._day -= d.DaysOfMonth(d._year, d._month);
		d._month++;
		if (d._month > 12)
		{
			d._month -= 12;
			d._year++;
		}
	}
	return d;
}

Date operator-(const Date &date, int days)
{
	Date d(date);
	d._day -= days;
	while (d._day <= 0)
	{
		d._month--;
		if (d._month == 0)
		{
			d._month = 12;
			d._year--;
		}
		d._day += d.DaysOfMonth(d._year, d._month);
	}
	return d;
}
int operator-(const Date &date1, const Date &date2)
{
	return date1.PassDays(date2._year) - date2.PassDays(date2._year);
}

ostream& operator<<(ostream &output, const Date &date)
{
	output << date._year << "." << date._month << "." << date._day;
	return output;
}
istream& operator>>(istream &input, Date& date)
{
	input >> date._year >> date._month >> date._day;
	return input;
}

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