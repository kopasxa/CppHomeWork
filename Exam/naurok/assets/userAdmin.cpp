#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
#include <cstdio>

#define keyForDB "itStep"
#define DBUsersName "db/users.txt"
#define tempDBUsers "db/usersTemp.txt"

#include "md.cpp"
using namespace std;

class userAdmin {
	fstream file;
	DWORD res;

	string name,
		surName,
		patronymic,
		number,
		role,
		login,
		password;

	int quantity = 0;
	bool isGo = false;

	bool secure() {
		file.open( DBUsersName );
		string key;

		if (file) {
			file >> key;

			if (key == keyForDB) {
				isGo = true;
			}
			else {
				return false;
			}
		}
		file.close();
		return true;
	}

	bool countUsers() {
		if (secure()) {
			file.open( DBUsersName );

			if (file) {
				this->quantity = 0;

				string line;
				while (!file.eof()) {
					getline( file, line );
					this->quantity++;
				}
				file.close();
			}
			else {
				return false;
			}
		}
		return true;
	}
public:

	bool add() {
		system( "cls" );
		COORD c;
		c.X = 47;
		c.Y = 0;
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), c );
		cout << "Меню добавления пользователя\n";

		cout << "Имя пользователя: ";
		getline( cin, this->name );
		cout << "Фамилия пользователя: ";
		getline( cin, this->surName );
		cout << "Отчество пользователя: ";
		getline( cin, this->patronymic );
		cout << "Номер телефона пользователя: ";
		getline( cin, this->number );
		cout << "Роль пользователя: ";
		getline( cin, this->role );
		cout << "Логин пользователя: ";
		getline( cin, this->login );
		cout << "Пароль пользователя: ";
		getline( cin, this->password );
		this->password = md( this->password, &res );

		if (countUsers()) {
			file.open( DBUsersName, ios::app );

			if (file.is_open()) {
				file << "\n" << this->quantity << " " << this->login << " " << this->password << " " << this->role << " " << this->name << " " << this->surName << " " << this->patronymic << " " << this->number;
			}

			file.close();
		}

		return true;
	};

	bool deleteUser(int id) {
		if (countUsers()) {
			if (id < quantity && id != 1) {
				fstream temp( tempDBUsers, ios::app );
				file.open( DBUsersName );

				if (file.is_open() && temp.is_open()) {
					string line;
					file >> line;
					temp << line;
					while (!file.eof()) {
						file >> this->quantity >> this->login >> this->password >> this->role >> this->name >> this->surName >> this->patronymic >> this->number;
						if (id != this->quantity) {
							temp << "\n" << this->quantity << " " << this->login << " " << this->password << " " << this->role << " " << this->name << " " << this->surName << " " << this->patronymic << " " << this->number;
						}
					}

					file.close();
					temp.close();

					HANDLE hwnd = GetStdHandle( STD_OUTPUT_HANDLE );
					SetConsoleTextAttribute( hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
					
					cout << "\nУспешно!\n";
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}

		remove( DBUsersName );
		rename( tempDBUsers, DBUsersName );
		
		Sleep( 2000 );

		return true;
	};

	bool writeListUsers() {
		if (countUsers()) {
			file.open( DBUsersName );

			if (file.is_open()) {
				string line;
				cout << "\nID | Login | Password | Role | Name | SurName | Patronymic | Phone\n";
				
				file >> line;

				while (!file.eof()) {
					getline(file, line);
					cout << line << endl;
				}
			
				file.close();

			}
			else {
				return false;
			}
		}

		return true;
	}
};

