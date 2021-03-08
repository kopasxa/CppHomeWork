#include "User.h"

User::User() {

}

bool User::is_empty( ifstream& pFile ) {
	return pFile.peek() == ifstream::traits_type::eof();
}

int User::createUser() {
	cout << "ID: "; cin >> us.id;
	cout << "Inp FIO of user: "; cin >> us.fio;
	cout << "Phone: "; cin >> us.phone;
	cout << "Login: "; cin >> us.login;
	cout << "Password: "; cin >> us.password;

	bool isContinue = true;

	/*obj.open( FILENAME );
	item temp;
	if (is_empty(obj)) {
		if (temp.id != us.id) {
			isContinue = true;
		}
	}
	else {
		while (!obj.eof()) {
			obj >> temp.id >> temp.fio >> temp.login >> temp.password >> temp.phone;
			if (temp.id != us.id && isContinue) {
				isContinue = true;
			}
			else {
				cout << "this user already exists (\n";
				isContinue = false;
			}
		}
	}*/
		 
	if (isContinue) {
		out.open( FILENAME, ios::app );
		if (out.is_open()) {
			out << "\n" << us.id << "\n" << us.fio << "\n" << us.login << "\n" << us.password << "\n" << us.phone;
		}
		else {
			cout << "can not open this file (\n";
			return 0;
		}

	}

	out.close();
	return 1;
}

int User::printUsers() {
	item temp;
	out.open( FILENAME );

	if (out.is_open()) {
		/*out >> temp.id >> temp.fio >> temp.login >> temp.password >> temp.phone;*/
		while (!out.eof()) {
			out >> temp.id >> temp.fio >> temp.login >> temp.password >> temp.phone;
			cout << "ID: " << temp.id << endl;
			cout << "Inp FIO of user: " << temp.fio << endl;
			cout << "Phone: " << temp.phone << endl;
			cout << "Login: " << temp.login << endl;
			cout << "Password: " << temp.password << endl;
			cout << endl;
		}
	}
	else {
		return 0;
	}
	
	out.close();
	return 1;
}

int User::deleteUser( int idUser ) {

	item temp;
	out.open( FILENAME );
	tempF.open( FILETEMP, ios::app );

	if (out.is_open() ) {
		while (!out.eof()) {
			out >> temp.id >> temp.fio >> temp.login >> temp.password >> temp.phone;
			if (temp.id != idUser) {
				tempF << "\n" << temp.id << "\n" << temp.fio << "\n" << temp.login << "\n" << temp.password << "\n" << temp.phone;
			}
		}
	}
	else {
		return 0;
	}

	out.close();
	tempF.close();
	
	remove( FILENAME );
	rename( FILETEMP, FILENAME );

	return 1;
}
