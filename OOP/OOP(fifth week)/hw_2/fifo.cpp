//Реалізувати клас для роботи з чергою з приорітетами( у вигляді лінійного однозвязного списку )
//Необхідний функціонал :
//-Конструктори( по замовчуванню, без параметрів; зі створенням першого елементу; конструктор копіювання ).
//- Деструктор.
//- Реалізувати контроль к - ті елементів( в конструкторі передбачити можливість задання максимальної кількості при створенні ).
//- Додавання нового елементу в чергу.
//- Видалення елементу з черги.
//- Визначення значення першого елементу черги( гетер )
//- Визначення значення останнього елементу черги( гетер )
//- Вигначення мінімального приорітету в черзі.
//- Визначення мінімального приорітету в черзі.
//- Визначенння к - ті елементів в черзі.
//- Виведення на єкран всієї черги.
//Реалізувати демонстрацію всих функцій в режимі діалогу з користувачем.

#include "fifo.h"
#include <iostream>

using namespace std;

fifo::fifo() {
	maxEl = 10;
}

fifo::fifo( int data ) {
	list = new item;
	list->ptr = nullptr;
	list->data = data;
	list->prioritet = 0;
	head = list;
	tail = list;

	this->size += 1;
	maxEl = 10;
}

fifo::fifo( const fifo& items ) {
	if (head != nullptr) {
		this->head = items.head;
		this->list = items.list;
		this->tail = items.tail;
		this->size = items.size;
		maxEl = items.maxEl;
	}
}

int fifo::getFirstItem() {
	if (head != nullptr) return head->data;
	else return 0;
}

int fifo::getLastItem() {
	return tail->data;
}

int fifo::minPr() {
	int min = head->prioritet;

	list = head;

	while (list->ptr != nullptr) {
		if (min > list->ptr->prioritet) {
			min = list->ptr->prioritet;
		}
		list = list->ptr;
	}

	return min;
}

int fifo::getSize() {
	return size;
}

int fifo::print() {
	if (head != nullptr) {
		list = head;
		do {
			cout << list->data << "|" << list->prioritet << "\n";
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

int fifo::push( int el, int prioritet ) {
	if (size < maxEl) {
		list = head;

		temp = new item;
		temp->data = el;
		temp->ptr = nullptr;
		temp->prioritet = prioritet;

		if (this->head == nullptr) {
			this->head = temp;
			this->tail = temp;
		}
		else {
			if (temp->prioritet > head->prioritet) {
				temp->ptr = head;
				head = temp;
			}
			else {
				if (temp->prioritet <= tail->prioritet) {
					tail->ptr = temp;
					tail = temp;
				}
				else {
					list = head;
					while (list->ptr->prioritet >= temp->prioritet && list->ptr != nullptr) {
						list = list->ptr;
					}
					temp->ptr = list->ptr;
					list->ptr = temp;
				}
			}
		}

		this->size += 1;

		return temp->data;
	}
	else {
		cout << "ERR: The maximum number of item \n";
	}
}

int fifo::pop() {
	list = head;

	while (list->ptr->ptr != nullptr) list = list->ptr;

	temp = list->ptr;

	tail = list;

	list->ptr = nullptr;

	this->size -= 1;

	return temp->data; delete temp;
}

fifo::~fifo() {
	while (head != nullptr) {
		temp = head;
		head = head->ptr;
		delete temp;
	}
}
