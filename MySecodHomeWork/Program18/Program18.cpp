#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	int num1, num2, numM, numB, sum = 0;
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
		sum += i;
	}

	cout << endl << sum;
}