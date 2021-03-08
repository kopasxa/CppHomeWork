#include "Student.h"
#include <cstdio>    
#include <stdio.h>

int Student::createUser() {
	cout << "ID: "; cin >> us.id;
	cout << "Inp FIO of student: "; cin >> us.fio;
	cout << "Phone: "; cin >> us.phone;
	cout << "Login: "; cin >> us.login;
	cout << "Password: "; cin >> us.password;

	out.open( FILENAMEST, ios::app );
	if (out.is_open()) {
		out << "\n" << us.id << "\n" << us.fio << "\n" << us.login << "\n" << us.password << "\n" << us.phone << "\n" << us.direction << "\n" << us.group;
	}
	else {
		cout << "can not open this file (\n";
		return 0;
	}


	out.close();
	return 1;
}

int Student::printUsers() {
	item temp;
	out.open( FILENAMEST );

	if (out.is_open()) {
		/*out >> temp.id >> temp.fio >> temp.login >> temp.password >> temp.phone;*/
		while (!out.eof()) {
			out >> temp.id >> temp.fio >> temp.login >> temp.password >> temp.phone >> temp.direction >> temp.group;
			cout << "ID: " << temp.id << endl;
			cout << "Inp FIO of student: " << temp.fio << endl;
			cout << "Phone: " << temp.phone << endl;
			cout << "Login: " << temp.login << endl;
			cout << "Password: " << temp.password << endl;
			cout << "Derection: " << temp.direction<< endl;
			cout << "Group: " << temp.group << endl;
			cout << endl;
		}
	}
	else {
		return 0;
	}

	out.close();
	return 1;
}

int Student::deleteUser( int idUser ) {

	item temp;
	out.open( FILENAMEST );
	tempF.open( FILETEMPST, ios::app );

	if (out.is_open()) {
		while (!out.eof()) {
			out >> temp.id >> temp.fio >> temp.login >> temp.password >> temp.phone >> temp.direction >> temp.group;
			if (temp.id != idUser) {
				tempF << "\n" << temp.id << "\n" << temp.fio << "\n" << temp.login << "\n" << temp.password << "\n" << temp.phone << "\n" << temp.direction << "\n" << temp.group;
			}
		}
	}
	else {
		return 0;
	}

	out.close();
	tempF.close();

	remove( FILENAMEST );
	rename( FILETEMPST, FILENAMEST );

	return 1;
}