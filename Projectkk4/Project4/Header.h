#pragma once
#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<typename t>
class CList
{
public:
	struct ListNode
	{
		t data;
		ListNode* next;

		ListNode(t d) : data(d), next(nullptr)
		{
		}

	};
private:
	ListNode* Head = nullptr, * Tail = nullptr;
public:
	void addHead(const t&);
	void addTail(const t&);
	void DeleteFromHead();
	void DeleteFromTail();
	void DeleteAll();
	int search(t elem);
	void show();
	void sum();
	void fRepetition();
	void clear();
	void push(int ind, t data);
	void back(int ind);
	int search_and_change(t elem, t newelem);
	void revers();
	int get_count()
	{
		int count = 0;
		ListNode* ptr = Head;
		while (ptr != nullptr)
		{
			ptr = ptr->next;
			count++;
		}
		return count;
	}
};

template<typename t>
inline void CList<t>::addHead(const t& elem)
{
	ListNode* tmp = new ListNode(elem);
	if (Head != nullptr)
	{
		tmp->next = Head;
		Head = tmp;
	}
	else
		Head = Tail = tmp;
}

template<typename t>
inline void CList<t>::addTail(const t& elem)
{
	ListNode* tmp = new ListNode(elem);
	if (Head)
	{
		Tail->next = tmp;
		Tail = tmp;
	}
	else
		Head = Tail = tmp;
}

template<typename t>
inline void CList<t>::DeleteFromHead()
{
	ListNode* ptr = Head;
	if (Head)
	{
		Head = Head->next;//   head =  null ; ptr tail 23 
		delete ptr;
		if (Head == nullptr)
			Tail = nullptr;
	}
}

template<typename t>
inline void CList<t>::DeleteFromTail()
{
	if (Head != nullptr)
	{
		ListNode* tmp = Head;
		while (tmp->next != Tail)
		{
			tmp = tmp->next;
		}
		delete Tail;
		Tail = tmp;
		tmp->next = nullptr;
	}
}

template<typename t>
inline void CList<t>::DeleteAll()
{
	ListNode* ptr = Head;
	while (Head != nullptr)
	{
		ListNode* fordelete = Head;
		Head = ptr->next;
		ptr = ptr->next;
		delete fordelete;
	}
}

template<typename t>
void CList<t>::clear()
{
	ListNode* ptr = Head;
	int num = get_count();
	for (int i = 0; i < num; i++)
	{
		ListNode* ptr2;
		ptr2 = ptr;
		ptr = ptr->next;
		cout << "dalete element#" << ptr2->data << endl;
		delete ptr2;

	}

}

template<typename t>
inline int CList<t>::search(t elem)
{
	ListNode* ptr = Head;
	int pos = 0;
	while (ptr != nullptr)
	{
		if (ptr->data == elem)
			return pos;
		ptr = ptr->next;
		pos++;
	}
	return -1;
}

template<typename t>
inline void CList<t>::show()
{
	if (Head == nullptr)
	{
		cout << "List is empty\n";
	}
	ListNode* tmp = Head;
	while (tmp != nullptr)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename t>
inline void CList<t>::sum()
{
	if (Head == nullptr)
	{
		cout << "List is empty\n";
	}
	ListNode* tmp = Head;
	int counter = 1;
	int sum = 0;
	while (tmp != nullptr)
	{
		if (counter % 2 == 0)
		{
			sum += tmp->data;
		}
		counter++;
		tmp = tmp->next;
	}
	cout <<"Sum = " << sum << endl;
	cout << endl;
}
template<typename t>
inline void CList<t>::fRepetition()
{
	if (Head == nullptr)
	{
		cout << "List is empty\n";
	}
	ListNode* tmp = Head;
	int counter = 0;
	vector<int> vec;
	bool flag = false;
	bool rep = false;
	while (tmp != nullptr)
	{
		ListNode* tmp2 = Head;
		int counter2 = 0;
		while (tmp2 != nullptr) {
			for (int i = 0; i < vec.size(); i++) {
				if (vec[i] == tmp->data) {
					goto ex;
				}
			}
	
			if (tmp->data == tmp2->data && counter != counter2) {
				cout << "Repetition is detected with the number " << tmp->data << endl;
				vec.push_back(tmp->data);
				rep = true;
				break;
			}
			ex:
			tmp2 = tmp2->next;
			counter2++;
		}
		counter++;
		tmp = tmp->next;
	}
	if(rep == false){
		cout << "Repetition is not detected" << endl;
	}
	cout << endl;
}
template<typename t>
inline void CList<t>::push(int ind, t data)
{
	ListNode* ptr = Head;
	ListNode* newel = new ListNode(data);
	if (ind == 0)
	{
		addHead(data);
	}
	else if (ind == get_count())
	{
		addTail(data);
	}
	else
	{
		for (int i = 0; i < ind - 1; i++)
		{
			ptr = ptr->next;
		}
		newel->next = ptr->next;
		ptr->next = newel;
	}
}

template<typename t>
inline void CList<t>::back(int ind)
{
	if (ind < get_count() && ind >= 0)
	{
		ListNode* ptr, * start = Head;
		if (ind == 0)
		{
			DeleteFromHead();
		}
		else if (ind == get_count() - 1)
		{
			cout << "-_-" << endl;
			DeleteFromTail();
		}
		else
		{
			for (int i = 0; i < ind - 1; i++)
			{
				start = start->next;
			}
			ptr = start->next;
			start->next = ptr->next;
			delete ptr;
		}
	}

}

template<typename t>
inline int CList<t>::search_and_change(t elem, t newelem)
{
	int changes = 0;
	ListNode* start = Head;
	while (start != nullptr)
	{
		if (start->data == elem)
		{
			start->data = newelem;
			changes++;
		}
		start = start->next;
	}
	return changes;
}

template<typename t>
inline void CList<t>::revers()
{
	CList<t>newList;
	ListNode* ptr = Head;
	while (ptr != nullptr)
	{
		newList.addHead(ptr->data);
		ptr = ptr->next;
	}
	clear();
	Head = newList.Head;
	Tail = newList.Tail;
	newList.Head = nullptr;
	newList.Tail = nullptr;

}