#ifndef __DATE_H__
#define __DATE_H__

#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	Date& operator=(const Date& d);

    int DaysOfMonth();//一个月的天数
	bool IsInvalid();//判断非法输入
	bool IsLeapYear();//判断闰年
	void ToCorrectDate();//调整为正确的日期
	Date& operator+=(int days);
	Date& operator-=(int days);

    friend ostream& operator<<(ostream& output, const Date& d);//输出运算符重载
	friend bool operator>(const Date& d1, const Date& d2);
	friend bool operator>=(const Date& d1, const Date& d2);
	friend bool operator<=(const Date& d1, const Date& d2);
	friend bool operator<(const Date& d1, const Date& d2);
	friend bool operator==(const Date& d1, const Date& d2);
	friend bool operator!=(const Date& d1, const Date& d2);
	
	friend Date operator+(const Date& d, int days);//日期+天数
	friend Date operator-(const Date& d, int days);//日期-天数
	friend int operator-(const Date& d1, const Date& d2);//日期-日期

private:
	int _year;
	int _month;
	int _day;

};

#endif