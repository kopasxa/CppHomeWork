//���������� ���� ��� ������ � c�����( � ������ ������� ������������ ������ )
//���������� ���������� :
//-������������( �� ������������, ��� ���������; � ���������� ������� ��������; ����������� ��������� ).
//- ����������.
//- ���������� �������� � - � ��������( � ����������� ����������� ��������� ������� ����������� ������� ��� �������� ).
//- ��������� ������ �������� � ����.
//- ��������� �������� � �����.
//- ���������� �������� ������� �������� �����( ����� )
//- ����������� � - � �������� � �����.
//- ��������� �� ����� ������ �����.
//���������� ������������ ���� ������� � ����� ������ � ������������.


#include "stack.h"
#include <iostream>

using namespace std;

stack::stack() {
	maxEl = 10;
}

stack::stack( int data ) {
	list = new item;
	list->ptr = nullptr;
	list->data = data;
	head = list;

	this->size += 1;
	maxEl = 10;
}

stack::stack( const stack& items ) {
	if (head != nullptr) {
		this->head = items.head;
		this->list = items.list;
		maxEl = items.maxEl;
	}
}

int stack::getFirstItem() {
	if (head != nullptr) return head->data;
	else return 0;
}

int stack::getSize() {
	return size;
}

int stack::print() {
	if (head != nullptr) {
		list = head;
		do {
			cout << list->data << " ";
			list = list->ptr;
		} while (list != nullptr);
		cout << endl;
		return 1;
	}
	else {
		cout << "ERR: Item not found \n";
		return 0;
	}

}

int stack::push( int el ) {
	if (size < maxEl) {
		list = head;

		while (list->ptr != nullptr) list = list->ptr;

		temp = new item;
		temp->data = el;
		temp->ptr = list->ptr;
		list->ptr = temp;

		this->size += 1;

		return temp->data;
	}
	else {
		cout << "ERR: The maximum number of item \n";
	}
}

int stack::pop() {
	list = head;

	while (list->ptr->ptr != nullptr) list = list->ptr;

	temp = list->ptr;

	list->ptr = nullptr;

	this->size -= 1;

	return temp->data; delete temp;
}

stack::~stack() {
	while (head != nullptr) {
		temp = head;
		head = head->ptr;
		delete temp;
	}
}
