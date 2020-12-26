#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	int num1, num2, numM, numB;
	cout << "Введите числа от и до: \n";
	cin >> num1 >> num2;
	
	if (num2 < num1) {
		numM = num2;
		numB = num1;
	}
	else {
		numM = num1;
		numB = num2;
	}
	for (int i = numM; i <= numB; i++) {
		cout << i << " ";
	}
	cout << "\nЧетные числа: \n";
	for (int i = numM; i <= numB; i++) {
		if (!(i % 2)) {
			cout << i << " ";
		}
	}
	cout << "\nНечетные числа: \n";
	for (int i = numM; i <= numB; i++) {
		if (i % 2) {
			cout << i << " ";
		}
	}
	cout << "\nЧисла кратные 7: \n";
	for (int i = numM; i <= numB; i++) {
		if (!(i % 7)) {
			cout << i << " ";
		}
	}
}