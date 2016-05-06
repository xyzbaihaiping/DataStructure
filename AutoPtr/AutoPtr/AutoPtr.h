#include<iostream>
using namespace std;

template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr)
	:_ptr(ptr)
	, _owner(true)
	{}
	~AutoPtr()
	{
		if (_owner)
		{
			delete _ptr;
		}
	}
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
		, _owner(true)
	{
		ap._owner = false;
	}
	AutoPtr& operator=(AutoPtr<T>& ap)
	{
		if (this != &ap)
		{   
			if (_owner)
			{
				delete _ptr;

			}
			_ptr = ap._ptr;
			_owner = true;
			ap._owner = false;
		}
		return *this;
	}
	T* operator->()
	{
		return _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
private:
	T* _ptr;
	bool _owner;
};