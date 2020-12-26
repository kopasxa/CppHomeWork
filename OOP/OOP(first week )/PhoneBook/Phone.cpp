#include "Phone.h"

using namespace std;

bool Phone::setPhone(string newFio, string newPhones[], string newAddInfo) {
	this->fio = newFio;

	for (int i = 0; i < this->sizePhones; i++) {
		if (newPhones[i] == "") {
			this->phones[i] = "Телефон не был добавлен";
		}
		else {
			this->phones[i] = newPhones[i];
		}
	}

	if (this->addInfo != "") {
		this->addInfo = newAddInfo;
	}
	else {
		this->addInfo = "Информация не была добавлена (";
	}

	return true;
}

bool Phone::getPhone() {
	cout << endl;
	cout << "Имя контакта: " << this->fio << endl;
	cout << "Домашний: " << this->phones[0] << "   Рабочий: " << this->phones[1] << "   Мобильный: " << this->phones[2] << endl;
	cout << "Дополнительная информация о контакте: " << this->addInfo << endl;
	
	return true;
}

string Phone::getFio() {
	return this->fio;
}