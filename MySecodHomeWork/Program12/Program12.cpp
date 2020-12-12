#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	int x, y;
	cout << "Введите число Х: ";
	cin >> x;
	cout << "Введите число У: ";
	cin >> y;

	for (int i = 1; i < y; i++) {
		x *= x;
	}

	cout << "Х в степени У = " << x;
}