#pragma once

#include<iostream>
using namespace std;

template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr)
		:_ptr(ptr)
	{}
	~AutoPtr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if (this != &ap)
		{
			delete _ptr;
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};
template<typename T>
class ScopedPtr
{
public:
	ScopedPtr(T* ptr)
	:_ptr(ptr)
	{}
	~ScopedPtr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}
	T* operator->()
	{
		return _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
protected:
	ScopedPtr(ScopedPtr<T>& sp);
	ScopedPtr<T>& operator=(ScopedPtr<T>& sp);
private:
	T* _ptr;
};
template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _pCount(new long(1))
	{}
	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _pCount(sp._pCount)
	{
		++(*_pCount);
	}
	/*SharedPtr& operator=(const SharedPtr<T>& sp)//传统的赋值方法
	{
	if (_ptr != sp._ptr)
	{
	Release();
	_ptr = sp._ptr;
	_pCount = sp._pCount;
	++(*_pCount);
	}
	return *this;
	}*/
	SharedPtr& operator=(SharedPtr<T> sp)//现代的赋值方法
	{
		swap(_ptr, sp._ptr);
		swap(_pCount, sp._pCount);
		return *this;
	}

	~SharedPtr()
	{
		Release();
	}
	long UseCount()
	{
		return *_pCount;
	}

	T* operator->()
	{
		return _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
protected:
	void Release()
	{
		if (--(*_pCount) == 0)
		{
			delete _ptr;
			delete _pCount;
		}
	}
private:
	T* _ptr;
	long* _pCount;
};
template<class T>
class ScopedArray
{
public:
	ScopedArray(T* ptr)
		:_ptr(ptr)
	{}
	~ScopedArray()
	{
		if (_ptr)
		{
			cout << "delete" << endl;
			delete[] _ptr;
		}
	}
	T& operator[](int index)
	{
		return _ptr[index];
	}
protected:
	ScopedArray(ScopedArray<T>& sparr);
	ScopedArray& operator=(ScopedArray<T>& sparr);
private:
	T* _ptr;
};
template<class T>
class SharedArray
{
public:
	SharedArray(T* ptr)
		:_ptr(ptr)
		, _pCount(new long(1))
	{}
	~SharedArray()
	{
		Release();
	}
	SharedArray(const SharedArray<T>& spArr)
		:_ptr(spArr._ptr)
		,_pCount(spArr._pCount)
	{
		++(*_pCount);
	}
	/*SharedArray& operator=(SharedArray<T> spArr)
	{
		swap(_ptr, spArr._ptr);
		swap(_pCount, spArr._pCount);
	}*/
	SharedArray& operator=(const SharedArray<T>& spArr)
	{
		if (_ptr != spArr._ptr)
		{
			Release();
			_ptr = spArr._ptr;
			_pCount = spArr._pCount;
			++(*_pCount);
		}
		return *this;

	}
	T& operator[](int index)
	{
		return _ptr[index];
	}
private:
	void Release()
	{
		if (--(*_pCount) == 0)
		{
			delete[] _ptr;
			delete _pCount;
		}
	}
private:
	T* _ptr;
	long* _pCount;
};