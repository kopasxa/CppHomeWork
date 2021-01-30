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

#pragma once

class stack {
	struct item {
		int data;
		item* ptr; 
	};

	int size = 0; // stack size 
	int maxEl = 0;
	
	item* head = nullptr;
	item* temp = nullptr;
	item* list = nullptr;

public:
	stack(); // create empty stack
	stack( int data ); // create a list with 1 el
	stack( const stack &items ); // copy stack

	int getFirstItem(); // prints first element this stack
	int getSize(); // prints the size of the stack
	int print(); // prints items of the stack
	int push( int el ); // add item to the end of the list
	int pop(); // remove item to the end of the list

	~stack(); // remove memory 
};

