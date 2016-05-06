#include<iostream>
#include<string>
using namespace std;

template<typename T>
struct Node
{
	Node(const T& d)
	:_data(d)
	,_next(NULL)
	, _prev(NULL)
	{}
	T _data;
	Node<T>* _next;
	Node<T>* _prev;
};
template<typename T>
class DList
{
public:
	DList();
	~DList();
	DList(const DList<T>& list);
	DList<T>& operator=(const DList<T> list);
	void PushBack(const T& d);
	void PopBack();
	void PushFront(const T& d);
	void PopFront();
	Node<T>* Find(const	T& d);
	void Insert(Node<T>* pos, const T& d);
	void Reverse();
	void Sort();
	void Remove(const T& d);
	void RemoveAll(const T& d);
	void Erase(Node<T>* pos);
	friend ostream& operator<<<T>(ostream& output, const DList<T>& s);
private:
	Node<T>* _head;
	Node<T>* _tail;
};
template<typename T>
DList<T>::DList()
:_head(NULL)
,_tail(NULL)
{}
template<typename T>
DList<T>::~DList()
{
	Node<T>* cur = _head;
	while (cur)
	{
		Node<T>* del = cur;
		cur = cur->_next;
		delete del;
	}
}
template<typename T>
DList<T>::DList(const DList<T>& list)
:_head(NULL)
,_tail(NULL)
{
	Node<T>* cur = list._head;
	while (cur)
	{
		PushBack(cur->_data);
		cur = cur->_next;
	}
}
template<typename T>
DList<T>& DList<T>::operator=(const DList<T> list)
{
	swap((Node<T>*)_head, (Node<T>*)list._head);
	swap((Node<T>*)_tail, (Node<T>*)list._tail);
	return *this;
}
template<typename T>
void DList<T>::PushBack(const T& d)
{
	if (_head == NULL)
	{
		_head = new Node<T>(d);
		_tail = _head;
	}
	else
	{
		Node<T>* NewNode = new Node<T>(d);
		_tail->_next = NewNode;
		NewNode->_prev = _tail;
		_tail = NewNode;
	}
}
template<typename T>
void DList<T>::PopBack()
{
	if (_head == NULL)
	{
		return;
	}
	else if (_head== _tail)
	{
		delete _head;
		_tail = NULL;
		_head = NULL;
	}
	else
	{
		_tail = _tail->_prev;
		delete _tail->_next;
		_tail->_next = NULL;
	}
}
template<typename T>
void DList<T>::PushFront(const T& d)
{
	Node<T>* NewNode = new Node<T>(d);
	if (_head == NULL)
	{
		_head = NewNode;
		_tail = _head;
		return;
	}
	NewNode->_next = _head;
	_head->_prev = NewNode;
	_head = NewNode;
}
template<typename T>
void DList<T>::PopFront()
{
	if (_head == NULL)
		return;
	else if (_head==_tail)
	{
		delete _head;
		_head = NULL;
		_tail = NULL;
	
	}
	else
	{
		_head = _head->_next;
		delete _head->_prev;
	}
}
template<typename T>
ostream& operator<<(ostream& output, const DList<T>& s)
{
	Node<T>* cur = s._head;
	while (cur)
	{
		cout<< cur->_data << "<->";
		cur = cur->_next;
	}
	output << "over";
	return output;
}

template<typename T>
Node<T>* DList<T>::Find(const T& d)
{
	Node<T>* cur = _head;
	while (cur)
	{
		if (cur->_data == d)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}
template<typename T>
void DList<T>::Insert(Node<T>* pos, const T& d)
{
	if (pos == NULL)
		return;
	Node<T>* NewNode = new Node<T>(d);
	if (pos == _tail)
	{
		_tail->_next = NewNode;
		NewNode->_prev = _tail;
		_tail = NewNode;
	}
	else
	{
		NewNode->_next = pos->_next;
		NewNode->_prev = pos;
		pos->_next = NewNode;
		NewNode->_next->_prev = NewNode;
	}
}
template<typename T>

void DList<T>::Reverse()
{
	Node<T>* cur = _head;
	while (cur)
	{
		swap(cur->_next, cur->_prev);
		cur = cur->_prev;
	}
	swap(_head, _tail);
}
template<typename T>
void DList<T>::Sort()
{
	Node<T>* cur = _head;
	Node<T>* end = NULL;
	while (cur != end)
	{
		while (cur && cur->_next != end)
		{
			if (cur->_data > cur->_next->_data)
			{
				T tmp = cur->_data;
				cur->_data = cur->_next->_data;
				cur->_next->_data = tmp;
			}
			cur = cur->_next;
		}
		end = cur;
		cur = _head;
	}
}
template<typename T>

void DList<T>::Remove(const T& d)
{
	Node<T>* cur = _head;
	while (cur)
	{
		Node<T>* del = cur;
		if (cur->_data == d)
		{
			if (cur == _head)
			{
				_head = _head->_next;
				_head->_prev = NULL;
			}
			else if (cur!=_head && cur==_tail)
			{
				_tail = _tail->_prev;
				_tail->_next = NULL;
			}
			else
			{
				cur->_prev->_next = cur->_next;
			}
			delete del;
			break;
		}
		cur = cur->_next;
	}

}
template<typename T>

void DList<T>::RemoveAll(const	T& d)
{
	Node<T>* cur = _head;
	while (cur)
	{
		Node<T>* del = cur;
		if (cur->_data == d)
		{
			if (cur == _head)
			{
				_head = _head->_next;
				_head->_prev = NULL;
				cur = _head;
			}
			else if (cur != _head && cur == _tail)
			{
				_tail = _tail->_prev;
				_tail->_next = NULL;
				cur = NULL;
			}
			else
			{
				cur->_prev->_next = cur->_next;
				cur->_next->_prev = cur->_prev;
				cur = cur->_next;
			}
			delete del;
		}
		else
		cur = cur->_next;
	}

}
template<typename T>

void DList<T>::Erase(Node<T>* pos)
{
	if (pos == NULL)
		return;
	if (pos == _head && pos == _tail)
	{
		_head = NULL;
		_tail = NULL;
		return;
	}
	if (pos == _head)
	{
		_head = _head->_next;
		_head->_prev = NULL;
	}
	else if (pos == _tail)
	{
		_tail = _tail->_prev;
		_tail->_next = NULL;
	}
	else
	{
		pos->_prev->_next = pos->_next;
		pos->_next->_prev = pos->_prev;
	}
	delete pos;

}


void Test1()
{
	DList<string> dlist;
	dlist.PushBack("1111111");
	dlist.PushBack("222222");
	dlist.PushBack("3333333");
	dlist.PushBack("4444444");
	dlist.PopBack();
	
	cout << dlist << endl;
	dlist.PopBack();
	dlist.PopBack();
	dlist.PopBack();
	dlist.PopBack();
	cout << dlist << endl;
	DList<string> d(dlist);
	cout << d << endl;
	DList<string> list;
	list = dlist;
	cout << dlist << endl;

}
void Test2()
{/*
	DList<int> dlist;
	dlist.PushFront(1);
	dlist.PushFront(2);
	dlist.PushFront(3);
	dlist.PushFront(4);
	cout << dlist << endl;
	dlist.PopFront();
	dlist.PopFront();
	dlist.PopFront();
	dlist.PopFront();
	dlist.PopFront();

	cout << dlist << endl;*/

}
void Test3()
{
	DList<int> list;
	list.PushFront(1);
	list.PushFront(2);
	list.PushFront(3);
	cout << list << endl; 

	/*Node<int>* pos = list.Find(1);
	cout << pos->_data << endl;
	list.Insert(pos, 5);
	cout << list << endl;*/
	/*list.Reverse();
	cout << list << endl;*/
	/*list.Sort();
	cout << list << endl;*/
	/*list.RemoveAll(1);
	cout << list << endl;*/
	/*list.Erase(list.Find(3));
	list.Erase(list.Find(2));*/
	cout << list << endl;

	list.Erase(list.Find(3));
	

	cout << list << endl;
list.Erase(list.Find(2)); 
list.Erase(list.Find(1));

	cout << list << endl;
}
int main()
{
	Test3();
	getchar();
	return 0;
}
