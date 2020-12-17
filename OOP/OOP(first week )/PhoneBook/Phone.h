#pragma once

#include <iostream>

//( ���, �������� �������,
//   ������� �������, ��������� �������, ��������������
//   ���������� � �������� )

using namespace std;

class Phone {
	string fio; // ��������� ����� ��� ������������ ������
	static const int sizePhones = 3;
	string phones[sizePhones];
	string addInfo;
public:
	Phone() {
		/*if (!getPhone()) {
			cout << "������ ��� ������ �������� (\n";
		}*/
	}

	Phone( string fio, string phones[], string addInfo ) {
		if (!setPhone( fio, phones, addInfo )) {
			cout << "������ � ������, ���������� ��� ���\n";
		}
	}

	bool getPhone();
	string getFio();
	bool setPhone( string fio, string phones[], string addInfo );
};

