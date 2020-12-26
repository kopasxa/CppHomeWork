#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	int sum = 0, i;

	for (i = 1; i <= 1000; i++) {
		sum += i;
	}

	cout << sum / i;
}