#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

template<class T>
class MinStack
{
public:
	void push(const T& d)
	{
		_sData.push(d);
		if ((_sMin.size()==0) || _sMin.top() >= d)
			_sMin.push(d);
	}
	void pop()
	{
		assert(!_sData.empty() && !_sMin.empty());
			if (_sData.top() == _sMin.top())
				_sMin.pop();
			_sData.pop();
		
	}
	T& Min()
	{
		assert(_sMin.size() != 0);
		return _sMin.top();
	}
private:
	stack<T> _sMin;
	stack<T> _sData;
};
void Test()
{
	MinStack<int> m;
	m.push(3);
	m.push(2);
	m.push(1);
	int min = m.Min();
	cout << min << endl;
	m.pop();
	m.pop();
    min = m.Min();
	cout << min << endl;
}
int main()
{
	Test();
	getchar();
	return 0;
}