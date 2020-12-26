#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	int num;
	cout << "Введите число: ";
	cin >> num;

	for (int i = 0; i < num; i++) {
		cout << i << ", ";
	}

	cout << num << ".";
}