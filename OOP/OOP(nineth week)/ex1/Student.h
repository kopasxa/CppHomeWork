#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
#define FILENAMEST "students.txt"
#define FILETEMPST "tempStudent.txt"

using namespace std;

class Student: public User {
	struct item {
		int id;
		string fio,
			phone,
			login,
			password,
			group,
			direction;
	};

	item us;
	fstream out;
	fstream tempF;

public:

	int createUser();

	int printUsers();

	int deleteUser( int idUser );

};

