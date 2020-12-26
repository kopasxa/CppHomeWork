//Реализовать структуру «Автомобиль»( длина, клиренс( высота посадки ), объем двигателя,
//									мощность двигателя, диаметр колес, цвет, тип коробки передач ).Создайте функции для задания
//	значений, отображения значений, поиска значений.

#include <iostream>
#include <string>

using namespace std;

struct Car {
	string width;
	string dWhole;
	string color;
	string clearance;
	string V;
	string power;
	string typeKpp;
};

struct engine {
	string V;
	string power;
};

Car newValue() {
	Car vehine;
	vehine.width = "4,689";
	vehine.color = "Красный";
	vehine.dWhole = "22";
	vehine.clearance = "11,7";
	vehine.V = "1.5";
	vehine.power = "374";
	vehine.typeKpp = "АКПП";
	return vehine;
}

void output( Car vehine ) {
	cout << "\t\t BMW i8" << endl;
	cout << "\t Длина машины: " << vehine.width << endl;
	cout << "\t Клиренс: " << vehine.clearance << endl;
	cout << "\t Обьем двигателя: " << vehine.V << endl;
	cout << "\t Мощность двигателя: " << vehine.power << endl;
	cout << "\t Диаметр колёс: " << vehine.dWhole << endl;
	cout << "\t Цвет машины: " << vehine.color << endl;
	cout << "\t Тип КПП: " << vehine.typeKpp << endl << endl;
}

void find( Car vehine) {
	cout << "\t\tПоиск" << endl;
	cout << "Введите искаемое значение: ";
	string findPhrase;
	getline(cin, findPhrase );

	if (vehine.width.find( findPhrase ) != -1) {
		cout << "Искаемый обьект: " << vehine.width;
	}
	else if (vehine.color.find( findPhrase ) != -1) {
		cout << "Искаемый обьект: " << vehine.color;
	}
	else if (vehine.clearance.find( findPhrase ) != -1) {
		cout << "Искаемый обьект: " << vehine.clearance;
	}
	else if (vehine.V.find( findPhrase ) != -1) {
		cout << "Искаемый обьект: " << vehine.V;
	}
	else if (vehine.power.find( findPhrase ) != -1) {
		cout << "Искаемый обьект: " << vehine.power;
	}
	else if (vehine.typeKpp.find( findPhrase ) != -1) {
		cout << "Искаемый обьект: " << vehine.typeKpp;
	}
	else {
		cout << "ERROR 404";
	}
	cout << endl;
}

int main () {
	setlocale( LC_ALL, "ru");

	Car vehine; 
	vehine = newValue( );
	output( vehine );
	find( vehine );
}