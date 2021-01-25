#include "doublylist.h"
#include <iostream>

using namespace std;

doublylist::doublylist() {
	list = new item;
	list->prev = nullptr;
	list->next = nullptr;
	firstitem = list;
	this->size += 1;

	for (int i = 1; i < 10; i++) {
		list = firstitem;
		temp = new item;
		temp->next = list->next;
		temp->prev = list;
		list->next = temp;
		this->size += 1;
	}
}

doublylist::doublylist( int number ) {
	list = new item;
	list->data = rand() % 20;
	list->next = nullptr;
	list->prev = nullptr;
	firstitem = list;
	this->size += 1;

	for (int i = 1; i < number; i++) {
		list = firstitem;
		temp = new item;
		temp->data = rand() % 20;
		temp->next = list->next;
		temp->prev = list;
		list->next = temp;
		this->size += 1;
	}
}

int doublylist::out() {
	if (firstitem != nullptr) {
		list = firstitem;
		do {
			cout << list->data << " ";
			list = list->next;
		} while (list != nullptr);
		return 1;
	}
	else {
		cout << "ERR: Item no found \n";
		return 0;
	}
}

int doublylist::push( int el ) {
	list = firstitem;

	while (list->next != nullptr) list = list->next;

	temp = new item;
	temp->data = el;
	temp->next = list->next;
	temp->prev = list;
	list->next = temp;

	this->size += 1;

	return temp->data;
}

int doublylist::pop() {
	list = firstitem;

	while (list->next->next != nullptr) list = list->next;

	temp = list->next;

	list->next = nullptr;

	this->size -= 1;

	return temp->data; delete temp;
}

int doublylist::unshift( int el ) {
	temp = new item;
	temp->data = el;
	temp->next = firstitem;
	firstitem = temp;
	list = firstitem;

	this->size += 1;

	return temp->data;
}

int doublylist::shift() {
	list = firstitem;
	temp = list->next;
	firstitem = temp;

	this->size -= 1;

	return list->data; delete list;
}

int doublylist::del( int el ) {
	list = firstitem;
	if (el == list->data) {
		temp = list;
		firstitem = list->next;
		delete temp;
		list = firstitem;

		this->size -= 1;
	}
	do {
		if (el == list->next->data) {
			temp = list->next;
			list->next = list->next->next;
			delete temp;

			this->size -= 1;
		}
		list = list->next;
	} while (list != nullptr);
	return 0;
}

int doublylist::sortadd( int el ) {
	this->push( el );

	list = firstitem;
	for (int i = 0; i < this->size - 1; i++) {
		for (int j = 0; j < this->size - i - 1; j++) {
			if (list->next->data < list->data) {
				int tmp = list->data;
				list->data = list->next->data;
				list->next->data = tmp;
			}
			list = list->next;
		}
		list = firstitem;
	}

	return 0;
}

doublylist::~doublylist() {
	while (firstitem != nullptr) {
		temp = firstitem;
		firstitem = firstitem->next;
		delete temp;
	}
}
