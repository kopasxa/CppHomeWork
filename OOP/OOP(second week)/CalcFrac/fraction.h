#pragma once

#include <iostream>

using namespace std;

class fraction {
	int chis;
	int znam;
	int integer = 0;

	int nsk( fraction drob1 );
public:
	fraction() : chis{0}, znam{0} {}
	fraction( int a, int b ) {
		if (!setFrac( a, b )) {
			cout << "Ошибка при задании значения (";
		}
	}

	bool getFrac();
	int getChis();
	int getZnam();

	bool setFrac( int a, int b );

	fraction simple();
	fraction operator+( fraction secondF );
	fraction operator-( fraction secondF );
	fraction operator*( fraction secondF );
	fraction operator/( fraction secondF );
	fraction operator++();
	fraction operator++( int i );
	fraction operator--();
	fraction operator--( int i );
};

