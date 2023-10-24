#pragma once
#include"List.h"

class Stek : public List {

public:

	Stek()
	{
		size = 0;
		head = NULL;
	}

	Stek(int n)
	{
		size = n;
		cout << "Введите числа в стек:\n";
		int vsp;
		for (int i = 0; i < n; i++) {
			cin >> vsp;
			push(vsp);
		}
	}

	void push(int value) override
	{

		if (size == limit) throw "Лимит исчерпан!";
		if (head == NULL)
		{
			cell* p = new cell;
			head = p;
			p->next = NULL;
			p->value = value;
			size++;
		}
		else
		{
			cell* p = new cell;
			p->value = value;
			p->next = head;
			head = p;
			size++;
		}
		cout << "Элемент добавлен (" << value << ") size = " << size << endl;
	}

	cell* Get_link_prev_cell(int ind) override {
		return NULL;
	}

	cell* Get_link_next_cell()
	{
		return head->next;
	}

	cell* Get_link_cell(int ind)
	{
		return head;
	}

	int Get_value_cell(int ind)
	{
		return head->value;
	}

	int pop() 
	{
		if (head == NULL) throw "Удаление элемента невозможно! Стек чист.";
		cell* p = head;
		int vsp = p->value;
		if (head->next == NULL) { delete p; cout << "Стек очищен."; size--; return vsp; }
		cell* p1 = head->next;
		delete p;
		head = p1;
		size--;
		return vsp;
	}
};