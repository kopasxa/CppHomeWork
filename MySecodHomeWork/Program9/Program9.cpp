#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	int orelReshka, sum = 0;

	for (int i = 0; i < 9; i++) {
		cout << "Введите число 1 или 0 (орел / решка)\n";
		cin >> orelReshka;

		if (orelReshka == 1) {
			sum += 1;
		}
	}

	if (sum % 2 == 0) {
		cout << "решение в положительную сторону";
	}
	else {
		cout << "решение в отрицательную сторону";
	}
}
