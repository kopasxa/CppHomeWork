#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	int num, sum = 0;
	cout << "Введите число: ";
	cin >> num;

	for ( ; num <= 500; num++) {
		sum += num;
	}

	cout << sum;
}