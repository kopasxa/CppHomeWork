//1)
//Создайте класс User, который будет содержать информацию о пользователе :
//-идентификатор( номер )
//- ФИО
//- номер телефона
//- email
//- логин
//- пароль
//и необходимые методы для просмотра, создания и удаления пользователей.
//Список пользователей храним в файле.
//
//С помощью механизма наследования, реализуйте класс Student производный от User.
//Дополнительные поля :
//-направление( например : прогммирование, дизайн, .... )
//- група( например : п1, п2, д3, ... )
//Информация о студентах группы сохраняется в отдельном файле.
//Избегаем дублирования информации в файлах.


#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>    
#include <stdio.h>
#define FILENAME "users.txt"
#define FILETEMP "temp.txt"

using namespace std;

class User {
	struct item {
		int id;
		string fio,
			phone,
			login,
			password;
	};

	item us;
	fstream out;
	fstream tempF;

public:
	User();
	bool is_empty( ifstream& pFile );
	int createUser();
	int printUsers();
	int deleteUser( int idUser );
};

