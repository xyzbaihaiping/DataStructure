#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include<iostream>

using namespace std;

class Complex
{
public:
	
	Complex(float real = 1, float imag = 1):_real(real), _imag(imag){}//构造函数
	Complex(const Complex& complex);//拷贝构造函数
	~Complex(){};//析构函数
	Complex& operator=(const Complex& complex);//赋值操作符重载
	
	bool operator==(const Complex& complex);
	bool operator!=(const Complex& complex);

	Complex operator+(const Complex& complex);
    Complex& operator++();//前置++
	Complex operator++(int);//后置++
	Complex& operator+=(const Complex& complex);

    Complex operator-(const Complex& complex);
	Complex& operator-=(const Complex& complex);
	Complex& operator--();//前置--
	Complex operator--(int);//后置--

	Complex operator*(const Complex& complex);
	Complex& operator*=(const Complex& complex);

	Complex operator/(const Complex& complex);
	Complex& operator/=(const Complex& complex);

	friend ostream& operator<<(ostream& output, const Complex& complex);//输出操作符重载
    bool operator>(const Complex& complex);
	bool operator>=(const Complex& complex);
	bool operator<(const Complex& complex);
	bool operator<=(const Complex& complex);

private:
	float _real;
	float _imag;
};



#endif//__COMPLEX_H__