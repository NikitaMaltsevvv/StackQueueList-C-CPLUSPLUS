#pragma once
#include<iostream>
#include<windows.h>
#include"Cell.h"
using namespace std;

class List
{

public:

	List(): size(0), head(NULL), tail(NULL)
	{}
	
	List(int n): size(n)
	{
		cout << "¬ведите числа в список:\n";
		int vsp;
		for (int i = 0; i < n; i++) {
			cin >> vsp;
			push(vsp);
		}
	}

	virtual void push (int value)
	{
		if (size == limit) throw "Ћимит исчерпан!";
		if (head == NULL)
		{
			cell* p = new cell;
			head = p;
			tail = p;
			p->prev = NULL;
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
			p1->next = p;
			tail = p;
			size++;
		}
		cout << "Ёлемент добавлен (" << value << ") size = " << size << endl;
	}

	void Print()
	{
		cell* p = head;
		do {
			cout << p->value << " ";
			p = p->next;
		} while (p != NULL);
		cout << endl;
	}

	int Get_Size()
	{
		return size;
	}

	virtual int Get_value_cell(int ind)
	{
		cell* p = head;

		for (int i = 0; i < ind - 1; i++) {
			p = p->next;
		}

		return p->value;
	}

	virtual cell* Get_link_prev_cell(int ind)
	{
		cell* p = head;

		for (int i = 0; i < ind - 1; i++) {
			p = p->next;
		}

		return p->prev;
	}

	virtual cell* Get_link_next_cell(int ind)
	{
		cell* p = head;

		for (int i = 0; i < ind - 1; i++) {
			p = p->next;
		}

		return p->next;
	}

	virtual cell* Get_link_cell(int ind)
	{
		cell* p = head;

		for (int i = 0; i < ind - 1; i++) {
			p = p->next;
		}

		return p;
	}

	virtual int pop(int ind)
	{
		if (head == NULL) throw "\n—писок пуст. ”даление невозможно.\n";
		if (ind > size || ind < 1) throw "\nЌеверный индекс!\n";

		cell* p = head;

		for (int i = 0; i < ind - 1; i++) {
			p = p->next;
		}

		cell* vsp_next = p->next;
		cell* vsp_prev = p->prev;
		if (vsp_next == NULL) { vsp_prev->next = NULL; tail = vsp_prev; }
		else if (vsp_prev == NULL) { vsp_next->prev = NULL; head = vsp_next; }
		else {
			vsp_next->prev = vsp_prev;
			vsp_prev->next = vsp_next;
		}

		int vsp = p->value;
		delete p;
		size--;
		return vsp;
	}

	int Del_odin_el()
	{
		if (size <= 1) throw "Ёлемент один. ќдинаковых не может быть!";
		for (int i = 1; i < size; i++) {
			for (int j = i + 1; j < size + 1; j++) {
				if (this->Get_value_cell(i) == this->Get_value_cell(j)) { this->pop(j); j--; }
			}
		}
	}

	bool empty()
	{
		if (head == NULL) return TRUE;
		else return FALSE;
	}

protected:
	const static int limit = 10;
	int size;
	cell* head;
private:
	cell* tail;
};