#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	int k;
	cout << "Введите число: ";
	cin >> k;

	for (int i = 1; i <= 10; i++) {
		cout << k << " x " << i << " = " << k * i << "\n";
	}
}