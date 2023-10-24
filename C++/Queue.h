#pragma once
#include"List.h"

class Queue : public List {

public:

	Queue(): tail(NULL)
	{
		size = 0;
		head = NULL;
	}

	Queue(int n)
	{
		size = n;
		cout << "¬ведите числа в очередь:\n";
		int vsp;
		for (int i = 0; i < n; i++) {
			cin >> vsp;
			push(vsp);
		}
	}

	void push(int value)
	{
		if (size == limit) throw "Ћимит исчерпан!";
		if (head == NULL)
		{
			cell* p = new cell;
			head = p;
			tail = p;
			p->next = NULL;
			p->value = value;
			size++;
		}
		else
		{
			cell* p = new cell;
			p->value = value;
			p->next = NULL;
			p->prev = tail;
			cell* p1 = tail;
			tail = p;
			p1->next = p;
			size++;
		}
		cout << "Ёлемент добавлен (" << value << ") size = " << size << endl;
	}

	int Get_value_cell()
	{

		return head->value;
	}

	cell* Get_link_prev_cell()
	{
		return NULL;
	}

	virtual cell* Get_link_next_cell(int ind)
	{
		return head->next;
	}

	virtual cell* Get_link_cell(int ind)
	{
		return head;
	}

	int pop()
	{

		if (head == NULL) throw "\n”даление элемента невозможно! ќчередь пуста.\n";
		cell* p = head;
		int vsp = p->value;
		if (head->next == NULL) { delete p; cout << "\nќчередь очищена.\n"; size--; return vsp; }
		cell* p1 = head->next;
		delete p;
		head = p1;
		size--;
		return vsp;
	}


private:
	cell* tail = NULL;
};