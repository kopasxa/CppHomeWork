//Реалізувати клас для роботи з cтеком( у вигляді лінійного однозвязного списку )
//Необхідний функціонал :
//-Конструктори( по замовчуванню, без параметрів; зі створенням першого елементу; конструктор копіювання ).
//- Деструктор.
//- Реалізувати контроль к - ті елементів( в конструкторі передбачити можливість задання максимальної кількості при створенні ).
//- Додавання нового елементу в стек.
//- Видалення елементу зі стеку.
//- Визначення значення першого елементу стеку( гетер )
//- Визначенння к - ті елементів в стеці.
//- Виведення на єкран всього стеку.
//Реалізувати демонстрацію всих функцій в режимі діалогу з користувачем.

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

