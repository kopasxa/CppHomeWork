#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	int result = 15, days, oneDay = 15;
	cout << "Сколько дней ползла улитка? \n";
	cin >> days;

	for (int i = 1; i < days; i++) {
		oneDay += 2;
		result += oneDay;
		
	}
	cout << result;
}