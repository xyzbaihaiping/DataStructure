#include "DList.h"

void DList::PushBack(const DataType& d)
{
	Node *NewNode = new Node(d);
	if (_head == NULL)
	{
		_head = NewNode;
		_tail = NewNode;
	}
	else
	{
		_tail->_next = NewNode;
		NewNode->_prev = _tail;
		_tail = NewNode;
	}
}
void DList::PushFront(const DataType& d)
{
	Node *NewNode = new Node(d);
	if (_head == NULL)
	{
		_head = NewNode;
		_tail = NewNode;
	}
	else
	{
		NewNode->_next = _head;
		_head->_prev = NewNode;
		_head = NewNode;
	}
}
void DList::PopBack()
{
	if (_head == NULL)
		return;
	else if (_head == _tail)
	{
		delete _head;
		_head = NULL;
		_tail = NULL;
	}
	else
	{
		_tail = _tail->_prev;
		delete _tail->_next;
		_tail->_next = NULL;
	}

}
void DList::PopFront()
{
	if (_head == NULL)
		return;
	else if (_head == _tail)
	{
		delete _head;
		_head = NULL;
		_tail = NULL;
	}
	else
	{
		_head = _head->_next;
		delete _head->_prev;
		_head->_prev = NULL;
	}

}
Node* DList::Find(const DataType& d)
{
	Node* cur = _head;
	while (cur)
	{
		if (cur->_data == d)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}
void DList::Insert(Node* pos, const DataType& d)
{
	assert(pos);
	Node* NewNode = new Node(d);
	if (pos == _tail)
	{
		pos->_next = NewNode;
		NewNode->_prev = pos;
		_tail = NewNode;
	}
	else
	{
		NewNode->_next = pos->_next;
		pos->_next = NewNode;
		NewNode->_prev = pos;
		NewNode->_next->_prev = NewNode;
	}
}
void DList::Reverse()
{
	Node *cur = _head;
	while (cur)
	{
		swap(cur->_next, cur->_prev);
		cur = cur->_prev;
	}
	swap(_head, _tail);
}
void DList::Sort()
{
	Node* cur = _head;
	Node* end = NULL;
	while (cur != end)
	{
		while (cur && cur->_next != end)
		{
			if (cur->_data > cur->_next->_data)
			{
				DataType d = cur->_data;
				cur->_data = cur->_next->_data;
				cur->_next->_data = d;
			}
			cur = cur->_next;
		}
		end = cur;
		cur = _head;
	}

}
void DList::Remove(const DataType& d)
{
	Node* cur = _head;
	while (cur)
	{
		if (cur->_data == d)
		{
			Node *del = cur;
			if (cur == _head)
			{
				_head = _head->_next;
				_head->_prev = NULL;
			}
			else if (cur != _head && cur == _tail)
			{
				_tail = cur->_prev;
				_tail->_next = NULL;			
			}
			else
		    {
			    cur->_prev->_next = cur->_next;
			    cur->_next->_prev = cur->_prev;
		     }
			delete del;
			break;
		}
		cur = cur->_next;
	}
	

}
void DList::RemoveAll(const DataType& d)
{
	Node* cur = _head;
	while (cur)
	{
		if (cur->_data == d)
		{
			Node *del = cur;
			if (cur == _head)
			{
				_head = _head->_next;
				_head->_prev = NULL;
				cur = _head;
			}
			else if (cur != _head && cur == _tail)
			{
				_tail = cur->_prev;
				_tail->_next = NULL;
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
		{
			cur = cur->_next;
		}
	}

}
void DList::Erase(Node* pos)
{
	assert(pos);
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
ostream& operator<<(ostream& output, const DList& s)
{
	Node* cur = s._head;
	while (cur)
	{
		output << cur->_data << "<->";
		cur = cur->_next;
	}
	output << "over";
	return output;
}