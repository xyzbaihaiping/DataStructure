#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class T>
struct Triple//三元组结构
{
	Triple(const T& value=T(), size_t row=0, size_t col=0)//三元组默认构造函数
	:_value(value)
	, _row(row)
	, _col(col)
	{}
	T _value;
	size_t _row;
	size_t _col;
};
template<class T>
class SparseMatrix
{
public:
	SparseMatrix(size_t m, size_t n, const T& invaild)//重载稀疏矩阵构造函数
		:_RowSize(n)
		, _ColSize(m)
		, _invaild(invaild)
	{}
	SparseMatrix(const T* a, size_t m, size_t n, const T& invaild)//稀疏矩阵构造函数，压缩存储
	:_RowSize(m)
	, _ColSize(n)
	, _invaild(invaild)
	{
		int index = 0;
		for (size_t i = 0; i < m; i++)//行优先存储
		{
			for (size_t j = 0; j < n; j++)//遍历矩阵
			{
				if (a[i*n + j] != _invaild)//若该矩阵元素是有效值
				{
					_a.push_back(Triple<T>(a[i*n + j],i,j));//存储元素
				}
			}
		}
	}
	void display()//打印矩阵
	{
		int index = 0;//vetcor元素下标
		for (size_t i = 0; i < _RowSize; i++)
		{
			for (size_t j = 0; j < _ColSize; j++)
			{
				if (index != _a.size() && _a[index]._row == i && _a[index]._col == j)
					//若三元组中有该位置元素（元素行列都相等，该位置元素是有效值）
				{
					cout << _a[index++]._value << " ";//打印该元素
				}
				else
					cout << _invaild << " ";//若该位置元素不是有效值，则打印非有效值
			}
			cout << endl;
		}
	}
	SparseMatrix<T> Transport()//矩阵转置
	{
		int index = 0;
		SparseMatrix<T> tmp(_RowSize, _ColSize, _invaild);//定义一个转置后的矩阵的大小
		for (size_t j = 0; j < _RowSize; j++) //
		{
			for (size_t i = 0; i < _a.size(); i++)//遍历vector
			{
				if (_a[i]._col == j)//若
				{
					tmp._a.push_back(Triple<T>(_a[i]._value, _a[i]._col, _a[i]._row));
					index++;
				}
			}

		}
		return tmp;
	}
	SparseMatrix<T> FastTransport()
	{
		int index = 0;
		SparseMatrix<T> tmp(_RowSize, _ColSize, _invaild);
		int *RowCount=new int[tmp._RowSize];//每行有效元素的个数
		int *RowStart=new int[tmp._RowSize];//每行有效元素在tmp._a中的起始位置
		memset(RowCount, 0, sizeof(int)*tmp._RowSize);//初始化
		memset(RowStart, 0, sizeof(int)*tmp._RowSize);

		while (index != _a.size())//设置数组RowCount的数据
		{
			RowCount[_a[index]._col]++;
			index++;
		}

		index = 1;
		RowStart[0] = 0;//第一个有效数字起始位置为0
		while (index < tmp._RowSize)//设置数组RowSize的数据
		{
			RowStart[index] = RowStart[index - 1] + RowCount[index - 1];
			//每行有效元素的个数是上一行有效元素的起始位置+上一行有效元素的个数
			index++;
		}
		
		//压缩存储转置后的矩阵
		index = 0;
		tmp._a.resize(_a.size());//将tmp._a的大小置为矩阵中有效元素的个数
		while (index < _a.size())
		{
			Triple<T> t(_a[index]._value, _a[index]._col, _a[index]._row);
			//定义临时三元组，该三元组的行是原来矩阵的列，列是原来矩阵的行，值不变


			tmp._a[RowStart[_a[index]._col]++] = t;
			index++;
            
			//(1) _a[index]._col 取出_a中的元素的行
			//(2)RowStart[_a[index]._col] 该元素的行作为RowStart的下标（_a中元素的列是tmp._a中元素的行）
			//得到的值是该元素在tmp._a中的存储位置
			//RowStart[_a[index]._col]++  表示若一行有多个元素，那么依次存储在该行有效元素的位置的后面
			
		}
		return tmp;
	}
protected:
	vector<Triple<T> > _a;//用容器存储三元组元素
	size_t _RowSize;//矩阵行数
	size_t _ColSize;//矩阵列数
    T _invaild;//非有效值
};