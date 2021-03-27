#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
#include <Wincrypt.h>

using namespace std;

#define keyForDB "itStep"

class admin {
	char* md5v2( std::string data, DWORD* result );
public:
	admin() {
		SetConsoleCP( 1251 );
		SetConsoleOutputCP( 1251 );
	}

	bool addUser();
	bool deleteUser();
};

