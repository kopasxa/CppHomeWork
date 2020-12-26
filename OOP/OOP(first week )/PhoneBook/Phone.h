#pragma once

#include <iostream>

//( ФИО, домашний телефон,
//   рабочий телефон, мобильный телефон, дополнительная
//   информация о контакте )

using namespace std;

class Phone {
	string fio; // Непонятно зачем тут динамическая память
	static const int sizePhones = 3;
	string phones[sizePhones];
	string addInfo;
public:
	Phone() {
		/*if (!getPhone()) {
			cout << "Ошибка при выводе контакта (\n";
		}*/
	}

	Phone( string fio, string phones[], string addInfo ) {
		if (!setPhone( fio, phones, addInfo )) {
			cout << "Ошибка в номере, попробуйте ещё раз\n";
		}
	}

	bool getPhone();
	string getFio();
	bool setPhone( string fio, string phones[], string addInfo );
};

