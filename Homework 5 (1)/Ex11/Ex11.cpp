// Используя указатели и оператор разыменования, определить наибольшее из двух чисел.

#include <iostream>

using namespace std;

int main() {
	int a, 
		b,
		*ptA = &a,
		*ptB = &b;

	cin >> a >> b;

	if (ptA > ptB) {
		cout << "Number B is bigger than A;";
	}
	else {
		cout << "Number A is bigger than B;";
	}
}
