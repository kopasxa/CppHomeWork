#include "Phone.h"

using namespace std;

bool Phone::setPhone(string newFio, string newPhones[], string newAddInfo) {
	this->fio = newFio;

	for (int i = 0; i < this->sizePhones; i++) {
		if (newPhones[i] == "") {
			this->phones[i] = "������� �� ��� ��������";
		}
		else {
			this->phones[i] = newPhones[i];
		}
	}

	if (this->addInfo != "") {
		this->addInfo = newAddInfo;
	}
	else {
		this->addInfo = "���������� �� ���� ��������� (";
	}

	return true;
}

bool Phone::getPhone() {
	cout << endl;
	cout << "��� ��������: " << this->fio << endl;
	cout << "��������: " << this->phones[0] << "   �������: " << this->phones[1] << "   ���������: " << this->phones[2] << endl;
	cout << "�������������� ���������� � ��������: " << this->addInfo << endl;
	
	return true;
}

string Phone::getFio() {
	return this->fio;
}