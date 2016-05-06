#include"date.h"

Date::Date(int year, int month, int day)//构造函数
:_year(year)
, _month(month)
, _day(day)
{
	if (IsInvalid())//若输入的日期不合法，则调整为合法日期
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
}

Date::Date(const Date& d)//拷贝构造函数
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
Date& Date::operator=(const Date& d)//赋值运算符重载
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

int Date::DaysOfMonth()
{
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//用数组的形式表示每个月的天数
	if (IsLeapYear())//若为闰年则二月份天数为29天
	{
		days[2] += 1;
	}
	return days[_month];
}

bool Date::IsInvalid()
{
	if (_year < 1900 || _month < 0 || _month > 12 || _day < 0 || _day > DaysOfMonth())
		return true;
	else
		return false;
}

bool Date::IsLeapYear()
{
	return (_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0;
}

ostream& operator<<(ostream& output, const Date& d)//输出运算符重载
{
	output << d._year << "." << d._month << "." << d._day;
	return output;
}

bool operator==(const Date& d1, const Date& d2)
{
	return (d1._year == d2._year) && (d1._month == d2._month) && (d1._day == d2._day);
}
bool operator!=(const Date& d1, const Date& d2)
{
	return !(d1 == d2);
}

bool operator>(const Date& d1, const Date& d2)
{
	if (d1._year > d2._year)
		return true;
	if (d1._year == d2._year)
	{
		if (d1._month > d2._month)
			return true;
		if (d1._month == d2._month)
		{
			if (d1._day > d2._day)
			{
				return true;
			}
		}
	}
	return false;
}

bool operator>=(const Date& d1, const Date& d2)
{
	return (d1 > d2) || (d1 == d2);
}

bool operator<=(const Date& d1, const Date& d2)
{
	return !(d1 > d2);
}

bool operator<(const Date& d1, const Date& d2)
{
	return !(d1 >= d2);
}

void Date::ToCorrectDate()
{
	while (_day <= 0)
	{
		if (_month == 1)
		{
			_month = 12;
			_year -= 1;
		}
		else
			_month--;
		_day += DaysOfMonth();
	}
	while (_day > DaysOfMonth())
	{
		_day -= DaysOfMonth();
		if (_month == 12)
		{
			_month = 1;
			_year += 1;

		}
		else
			_month++;
	}
}

Date operator+(const Date& d, int days)
{
	Date d1(d);
	d1._day += days;
	d1.ToCorrectDate();
	return d1;
}

Date& Date::operator+=(int days)
{
	_day += days;
	ToCorrectDate();
	return *this;
}

Date operator-(const Date& d, int days)
{
	Date d1(d);
	d1._day -= days;
	d1.ToCorrectDate();
	return d1;
}

Date& Date::operator-=(int days)
{
	_day -= days;
	ToCorrectDate();
	return *this;
}

int operator-(const Date& d1, const Date& d2)
{
	Date MinDate(d1);
	Date MaxDate(d2);
	int days = 0;
	if (d1 > d2)
	{
		MinDate = d2;
		MaxDate = d1;
	}
	if (d1 < d2)
	{
		MinDate = d1;
		MaxDate = d2;
	}
	while (MinDate != MaxDate)//较小的日期每次增加一天，直到与较大日期相等
	{
		MinDate += 1;
		days++;//记录天数
	}
	return days;
}

