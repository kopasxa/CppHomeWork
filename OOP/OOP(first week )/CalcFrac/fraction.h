#pragma once

#include <iostream>

using namespace std;

class fraction {
	int chis;
	int znam;
public:
	fraction() {chis = 0; znam = 0;}
	fraction( int a, int b ) {
		if (!setFrac( a, b )) {
			cout << "Ошибка при задании значения (";
		}
	}

	bool getFrac();
	int getChis();
	int getZnam();
	bool setFrac(int a, int b);
};

