// Розробити клас String, який в подальшому буде використовуватися для роботи з рядками.Клас повинен містити :
// • Конструктор за замовчуванням, що дозволяє створити рядок довжиною 80 символів;
// • Конструктор, що дозволяє створювати рядок довільного розміру;
// • Конструктор, який створює рядок і ініціалізує її рядком, отриманої від користувача.
// • Необхідно створити деструктор.
// • Клас повинен містити методи для введення рядків з клавіатури і виведення рядків на екран.
// 
// В клас String додайте перевантаження[], ()
// [] - повертає елемент за вказаною індексу;
// () - шукає символ в рядку, якщо символ є повертає індекс, якщо немає - 1.
// 
// 
// Реалізуйте операцію інкеремента.Вона повинна збільшувати довжину рядка на одиницю.Новий символ заповнюється прогалиною.
// Реалізуйте операцію декремента.Вона повинна зменшувати довжину рядка на одиницю.

#include "myString.h"
#include <iostream>
#include <string>

using namespace std;

myString::myString() {
	this->str = new char[80];
	count++;
}

myString::myString( int sizeStr ) {
	this->str = new char[sizeStr];
	count++;
}

myString::myString( char str2[] ) {
	this->str = new char[strlen( str2 )];
	this->str = str2;
	count++;
}

myString::~myString() {
	count--;
	delete[] str; // ???? ERROR | I don't have idea to fix this bug (
}

void myString::cinS() {
	cin >> this->str;
}

void myString::coutS() {
	cout << this->str;
}

int myString::getCountObj() {
	return count;
}

char myString::operator[]( int index ) {
	cout << endl;
	for (int i = 0; i < strlen( str ); i++ ) {
		if (i == index-1) {
			return this->str[i];
		}
	}

	return 0;
}

int myString::operator()( char symbol ) {
	cout << endl;
	for (int i = 0; i < strlen( str ); i++) {
		if (this->str[i] == symbol) {
			return i;
		}
	}

	return -1;
}

void myString::operator++( int i ) {
	int temp = strlen( this->str );
	this->str[strlen( this->str )] = '|';
	this->str[temp + 1] = 0;
}

void myString::operator--( int i ) {
	this->str[strlen( this->str ) - 1] = 0;
}

std::istream& operator>>( std::istream& is, myString& o ) {
	is >> o.str;
	return is;
}

std::ostream& operator<<( std::ostream& is, myString& o ) {
	is << o.str;
	return is;
}
