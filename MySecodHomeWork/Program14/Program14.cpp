#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	int i, num;
	long long sum = 1;
	cout << "Введите число: ";
	cin >> num;

	for (i = num; i <= 20; i++) {
		if (num <= 1) break;
		sum *= i;
	}

	cout << sum;
}