//- Визначення мінімального приорітету в черзі.

#pragma once

class fifo {
	struct item {
		int data;
		int prioritet;
		item* ptr; 
	};

	int size = 0;
	int maxEl = 0;

	item* head = nullptr;
	item* tail = nullptr;
	item* temp = nullptr;
	item* list = nullptr;

public:
	fifo(); // create empty stack
	fifo( int data ); // create a list with 1 el
	fifo( const fifo& items ); // copy stack

	int getFirstItem(); // prints first element this fifo
	int getLastItem(); // prints last element this fifo
	int minPr(); // print min prioritet
	int getSize(); // prints the size of the fifo
	int print(); // prints items of the fifo
	int push( int el, int prioritet ); // add item to the end of the list
	int pop(); // remove item to the end of the list

	~fifo(); // remove memory 
};

