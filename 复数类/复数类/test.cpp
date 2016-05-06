#include"Complex.h"
void Test1()//默认函数测试
{
	Complex c1;
	cout << "c1:" << c1 << endl;
	Complex c2(1, 7);
	cout << "c2:" << c2 << endl;
	Complex c3(c2);
	cout << "c3(c2):" << c3 << endl;
	c1 = c2;
	cout << "c1 = c2:" << c1 << endl;
	Complex c4 = c3;
	cout << "c4 = c3:" << c4 << endl;

}
void Test2()//比较测试
{
	Complex c1(1, 3);
	Complex c2(1, 3);
	cout << "c1:" << c1 << endl;
	cout << "c2:" << c2 << endl;
	//cout << (c1 <= c2) << endl;
	cout << (c1 == c2) << endl;
	cout << (c1 != c2) << endl;
}
void Test3()//加法测试
{
	Complex c1(1, 3);
	Complex c2(1, 3);
	cout << "c1:" << c1 << endl;
	cout << "c2:" << c2 << endl;
	cout << "c1+c2:"<<(c1 + c2) << endl;
	/*cout << "++c1:" << ++c1 << endl;
	cout << "c1++:" << c1++ << endl;
	cout << "c1:" << c1 << endl;
	cout << "c1+=c2:" << (c1+=c2) << endl;
	cout << "c1:" << c1 << endl;*/

}
void Test4()//减法测试
{
	Complex c1(4, 3);
	Complex c2(1, 4);
	cout << "c1:" << c1 << endl;
	cout << "c2:" << c2 << endl;
	cout << "c1-c2:"<<(c1 - c2) << endl;
	cout << "--c1:" << --c1 << endl;
	cout << "c1--:" << c1-- << endl;
	cout << "c1:" << c1 << endl;
	cout << "c1-=c2:" << (c1 -= c2) << endl;
	cout << "c1:" << c1 << endl;
}
void Test5()//乘除法测试
{
	Complex c1(1, 2);
	Complex c2(2, 1);
	cout << "c1:" << c1 << endl;
	cout << "c2:" << c2 << endl;
   /* cout << "c1*c2:" << (c1*c2) << endl;
	cout << "c1:" << c1 << endl;*/
   /*cout << "c1*=c2:" << (c1*=c2) << endl;
	cout << "c1:" << c1 << endl;*/
    /*cout << "c1/c2:" << (c1/c2) << endl;
	cout << "c1:" << c1 << endl;*/
	cout << "c1/=c2:" << (c1/=c2) << endl;
	cout << "c1:" << c1 << endl;
}
int main()
{
	Test2();
	getchar();
	return 0;
}