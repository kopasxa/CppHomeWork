#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	int num, sum = 0;

	while (true) {
		cout << "Введите число (напиши 0 когда закончишь): ";
		cin >> num;

		sum += num;
		if (num == 0) {
			break;
		}
	}

	cout << "\nСумма ваших чисел: " << sum;
}