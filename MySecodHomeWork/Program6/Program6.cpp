#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    int number, sum = 0, i = 0;
	cout << "Введите число: ";
	cin >> number;
	
	while (number > 0) {
		sum = number % 10;
		number /= 10;
		cout << sum;
	}
}