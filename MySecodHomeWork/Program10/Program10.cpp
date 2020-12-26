#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int month, colStart, all = 0, numbers, holiday = 0, n = 0;
	cout << "Введите месяц (1 - 12): \n";
	cin >> month;
	cout << "Введите день недели с которого начинается " << month << " месяц (1 - 7): \n";
	cin >> colStart;
	cout << "\t\t\t";
	
	switch (month)
	{
	case 1:
		cout << "Январь";
		break;
	case 2:
		cout << "Февраль";
		break;
	case 3:
		cout << "Март";
		break;
	case 4:
		cout << "Апрель";
		break;
	case 5:
		cout << "Май";
		break;
	case 6:
		cout << "Июнь";
		break;
	case 7:
		cout << "Июль";
		break;
	case 8:
		cout << "Август";
		break;
	case 9:
		cout << "Сентябрь";
		break;
	case 10:
		cout << "Октябрь";
		break;
	case 11:
		cout << "Ноябрь";
		break;
	case 12:
		cout << "Декабрь";
		break;
	default:
		break;
	}
	cout << "\n\nПн\tВт\tСр\tЧт\tПт\tСб\tВс\n";

	for (int i = 1; i < colStart; i++) {
		cout << "\t";
		all++;
	}
	for (numbers = 1; numbers <= 30; numbers++) {
		cout << numbers << "\t";
		all++;
		if (all == 7) {
			cout << "\n";
			all = 0;
		}
	}
	
	//cout << "\n\nКоличество выходных в " << month << " месяце: " << holiday;
	
}
