//1)
//�������� ����� User, ������� ����� ��������� ���������� � ������������ :
//-�������������( ����� )
//- ���
//- ����� ��������
//- email
//- �����
//- ������
//� ����������� ������ ��� ���������, �������� � �������� �������������.
//������ ������������� ������ � �����.
//
//� ������� ��������� ������������, ���������� ����� Student ����������� �� User.
//�������������� ���� :
//-�����������( �������� : ��������������, ������, .... )
//- �����( �������� : �1, �2, �3, ... )
//���������� � ��������� ������ ����������� � ��������� �����.
//�������� ������������ ���������� � ������.


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

