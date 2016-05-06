#include<iostream>
using namespace std;

template<class T>
struct DefaultDel
{
	void operator()(T *p)
	{
		delete p;
	}

};

struct Fclose
{
	void operator()(void *p)
	{
		fclose((FILE*)p);
	}
};
struct Free
{
	void operator()(void *p)
	{
		free(p);
	}
};


template<class T, class D = DefaultDel<T> >
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		,_pCount(new long(1))
	{}
	SharedPtr(T* ptr,D del)
		:_ptr(ptr)
		, _pCount(new long(1))
		, _del(del)
	{}
	~SharedPtr()
	{
		Release();
	}
	SharedPtr(const SharedPtr<T,D>& sp)
		:_ptr(sp._ptr)
		, _pCount(sp._pCount)

	{
		++(*_pCount);
	}
	/*SharedPtr& operator=(const SharedPtr<T>& sp)
	{
	
		if (sp._ptr != _ptr)
		{
			Release();
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			++(*_pCount);
		}
		return *this;
	}*/
	SharedPtr& operator=(SharedPtr<T,D> sp)
	{
		swap(sp._ptr, _ptr);
		swap(sp._pCount, _pCount);
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
	long UseCount()
	{
		return *_pCount;
	}
protected:
	void Release()
	{
		if (--(*_pCount) == 0)
		{
			/*delete _ptr;*/
			_del(_ptr);
			delete _pCount;
		}
	}
private:
	T* _ptr;
	long* _pCount;
	D _del;
};