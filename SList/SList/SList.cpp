#include "SList.h"

void SList::PushBack(const DataType& d)
{
	Node* NewNode = new Node(d);
	if (_head == NULL)
	{
		_head = NewNode;
		_tail = NewNode;
	}
	else
	{
		_tail->_next = NewNode;
		_tail = NewNode;
	}
}
void SList::PushFront(const DataType& d)
{
	Node* NewNode = new Node(d);
	if (_head == NULL)
	{
		_head = NewNode;
		_tail = NewNode;
	}
	else
	{
		NewNode->_next = _head;
		_head = NewNode;
	}
}
void SList::PopBack()
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
		Node* cur = _head;
		while (cur->_next != _tail)
		{
			cur = cur->_next;
		}
		delete _tail;
		_tail = cur;
		_tail->_next = NULL;
	}
}
void SList::PopFront()
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
		Node* del = _head;
		_head = del->_next;
		delete del;
	}
}
Node* SList::Find(const DataType& d)
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
void SList::Insert(Node* pos, const DataType& d)
{
	assert(pos);
	Node* NewNode = new Node(d);
	if (pos == _tail)
	{
		pos->_next = NewNode;
		_tail = NewNode;
	}
	else
	{
		NewNode->_next = pos->_next;
		pos->_next = NewNode;
	}
}
void SList::Reverse()
{
	Node* prev = NULL;
	Node* NewHead = NULL;
	Node* cur = _head;
	while (cur)
	{
		prev = cur;
		cur = cur->_next;
		prev->_next = NewHead;
		NewHead = prev;
	}
	_tail = _head;
	_head = NewHead;
}
void SList::Sort()
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
void SList::Remove(const DataType& d)
{
	Node* cur = _head;
	Node* prev = cur;
	while (cur)
	{
		if (cur->_data == d)
		{
			Node* del = cur;
			if (cur == _head)
			{
				_head = _head->_next;
			}
			else
			{
				prev->_next = cur->_next;
				if (cur == _tail)
				{
					_tail = prev;
					_tail->_next = NULL;
				}
			}
			delete del;
			break;
		}
		prev = cur;
		cur = cur->_next;
	}
}
void SList::RemoveAll(const DataType& d)
{
	Node* cur = _head;
	Node* prev = cur;
	while (cur)
	{
		if (cur->_data == d)
		{
			Node* del = cur;
			if (cur == _head)
			{
				_head = _head->_next;
				cur = _head;
			}
			else
			{
				prev->_next = cur->_next;
				if (cur == _tail)
				{
					_tail = prev;
					_tail->_next = NULL;

				}
				cur = prev->_next;
			}
			delete del;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
		
	}
}
void SList::Erase(Node* pos)
{
	Node *cur = _head;
	Node *prev = NULL;
	Node *del = NULL;
	while (cur)
	{
		if (cur == pos)
		{
			del = cur;
			if (cur == _head)
			{
				_head = _head->_next;
			}
			else
			{
				prev->_next = cur->_next;
				if (cur == _tail)
				{
					_tail = prev;
				}
			}
			delete del;
			break;
		}
		prev = cur;
		cur = cur->_next;
	}
}
ostream& operator<<(ostream& output, const SList& s)
{
	Node* cur = s._head;
	while (cur)
	{
		output << cur->_data << "->";
		cur = cur->_next;
	}
	output << "over";
	return output;
}
//ÃæÊÔÌâ

void SList::EraseNotTail(Node* pos)
{
	assert(pos);
	Node* del = pos->_next;
	pos->_data = pos->_next->_data;
	pos->_next =pos->_next->_next;
	delete del;

}
void SList::InsertFrontNode(Node* pos, DataType d)
{
	Node* NewNode = new Node(d);
	NewNode->_next = pos->_next;
	pos->_next = NewNode;
	DataType tmp = pos->_next->_data;
	pos->_next->_data = pos->_data;
	pos->_data = tmp;
}

void SList::Merge(SList l1 )
{
	Node *NewHead = NULL;
	if (_head == NULL || l1._head == NULL)
	{
		if (l1._head)
			NewHead = l1._head;
		else
			NewHead = _head;
	}
	if (_head->_data < l1._head->_data)
	{
		NewHead = _head;
		_head = _head->_next;
	}
	else
	{
		NewHead = l1._head;
		l1._head = l1._head->_next;
	}
	Node *cur = NewHead;
	while (l1._head && _head)
	{
		if (l1._head->_data < _head->_data)
		{
			cur->_next = l1._head;
			l1._head = l1._head->_next;
		}
		else
		{
			cur->_next = _head;
			_head = _head->_next;
		}
		cur = cur->_next;
	}
	if (l1._head)
		cur->_next = l1._head;
	else
		cur->_next = _head;
	_head = NewHead;
}

Node* SList::FindMidNode()
{
	Node* fast = _head;
	Node* slow = _head;
	while (fast && fast->_next)
	{
		fast = fast->_next->_next;
		slow = slow->_next;
	}
	return slow;
}

Node* SList::JoseCycle(int num)
{
	Node *cur = _head;
	while (1)
	{
		int count = num;
		if (cur->_next->_next == cur)
		{
			break;
		}
		while (--count)
		{
			cur = cur->_next;
		}
		Node* del = cur->_next;
		cur->_data = cur->_next->_data;
		cur->_next = cur->_next->_next;
		delete del;
	}
	return cur;
}
void SList::DelKNode(int k)
{
	Node *ps2 = _head;
	Node *ps1 = _head;
	Node *del = NULL;
	while (--k && ps1->_next)
	{
		ps1= ps1->_next;
	}
	if (ps2->_next == NULL)
		return;
	while (ps1->_next)
	{
		ps1 = ps1->_next;
		ps2 = ps2->_next;
	}
	del = ps2->_next;
	ps2->_data = ps2->_next->_data;
	ps2->_next = ps2->_next->_next;
	delete del;
}

Node* SList::CheckCycle()
{
	Node *fast = _head;
	Node *slow = _head;
	while (fast && fast->_next)
	{
		fast = fast->_next->_next;
		slow = slow->_next;
		if (fast == slow)
			return slow;
	}
	return NULL;
}
int SList::GetCircleLength(Node* meet)
{
	Node *cur = meet;
	int len = 0;
	do
	{
		len++;
		cur = cur->_next;
	} while (cur && cur != meet);
	return len;
}

Node* SList::FindEntryNMeetNodeode(Node* MeetNode)
{
	Node* meet = MeetNode;
	Node* Entry = _head;
	while (meet!=Entry)
	{
		meet = meet->_next;
		Entry = Entry->_next;
	}
	return Entry;
}

bool SList::CheckCross(SList list1, SList list2)
{
	if (list1._head == NULL || list2._head == NULL)
		return;
	Node* l1=list1._head;
	Node* l2 = list2._head;
	
	while (l1->_next)
	{
		l1 = l1->_next;
	}
	while (l2->_next)
	{
		l2 = l2->_next;
	}
	if (l1 == l2)
		return true;
	else
		return false;

}

Node* SList::LinkCrossNode(SList list1, SList list2)
{
	if (list1._head == NULL || list2._head == NULL)
		return;
	Node *l1 = list1._head;
	Node *l2 = list2._head;
	int lenl1 = 0;
	int lenl2 = 0;
	while (l1)
	{
		lenl1++;
		l1 = l1->_next;
	}
	while (l2)
	{
		lenl2++;
		l2 = l2->_next;
	}
	l1 = list1._head;
	l2 = list2._head;
	if (lenl1 > lenl2)
	{
		int len = lenl1 - lenl2;
		while (len--)
		{
			l1 = l1->_next;
		}
	}
	else
	{
		int len = lenl2 - lenl1;
		while (len--)
		{
			l2 = l2->_next;
		}
	}
	while (l1 != l2)
	{
		l1 = l1->_next;
		l2 = l2->_next;
	}
	return l1;


}