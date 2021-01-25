#include "dlist.h"
#include <iostream>

using namespace std;

dlist::dlist() {
	list = new item;
	list->ptr = nullptr;
	firstitem = list;
	this->size += 1;

	for (int i = 1; i < 10; i++) {
		list = firstitem;
		temp = new item;
		temp->ptr = list->ptr;
		list->ptr = temp;
		this->size += 1;
	}
}

dlist::dlist( int number ) {
	list = new item;
	list->data = rand() % 20;
	list->ptr = nullptr;
	firstitem = list;
	this->size += 1;

	for (int i = 1; i < number; i++) {
		list = firstitem;
		temp = new item;
		temp->data = rand() % 20;
		temp->ptr = list->ptr;
		list->ptr = temp;
		this->size += 1;
	}
}

int dlist::out() {
	if (firstitem != nullptr) {
		list = firstitem;
		do {
			cout << list->data << " ";
			list = list->ptr;
		} while (list != nullptr);
		return 1;
	}
	else {
		cout << "ERR: Item no found \n";
		return 0;
	}
}

int dlist::push( int el ) {
	list = firstitem;

	while (list->ptr != nullptr) list = list->ptr;

	temp = new item;
	temp->data = el;
	temp->ptr = list->ptr;
	list->ptr = temp;

	this->size += 1;

	return temp->data;
}

int dlist::pop() {
	list = firstitem;

	while (list->ptr->ptr != nullptr) list = list->ptr;
	
	temp = list->ptr;

	list->ptr = nullptr;

	this->size -= 1;

	return temp->data; delete temp;
}

int dlist::unshift( int el) {
	temp = new item;
	temp->data = el;
	temp->ptr = firstitem;
	firstitem = temp;
	list = firstitem;

	this->size += 1;

	return temp->data;
}

int dlist::shift() {
	list = firstitem;
	temp = list->ptr;
	firstitem = temp;

	this->size -= 1;

	return list->data; delete list; 
}

int dlist::del( int el ) {
	list = firstitem;
	if (el == list->data) {
		temp = list;
		firstitem = list->ptr;
		delete temp;
		list = firstitem;

		this->size -= 1;
	}
	do {
		if (el == list->ptr->data) {
			temp = list->ptr;
			list->ptr = list->ptr->ptr;
			delete temp;

			this->size -= 1;
		}
		list = list->ptr;
	} while (list != nullptr);
	return 0;
}

int dlist::sortadd( int el ) {
	this->push( el );
	
	list = firstitem;
	for (int i = 0; i < this->size - 1; i++) {
		for (int j = 0; j < this->size - i - 1; j++) {
			if (list->ptr->data < list->data) {
				int tmp = list->data;
				list->data = list->ptr->data;
				list->ptr->data = tmp;
			}
			list = list->ptr;
		}
		list = firstitem;
	}
	
	return 0;
}

dlist::~dlist() {
	while (firstitem != nullptr) {
		temp = firstitem;
		firstitem = firstitem->ptr;
		delete temp;
	}
}
