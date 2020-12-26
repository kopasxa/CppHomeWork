#include "fraction.h"

bool fraction::getFrac() {
	if (this->chis != 0 && this->znam != 0) {
		cout << this->chis << "/" << this->znam << endl;

		return true;
	}
	else {
		return false;
	}
}

int fraction::getChis() {
	return this->chis;
}

int fraction::getZnam() {
	return this->znam;
}

bool fraction::setFrac( int a, int b ) {
	if (a != 0 && b != 0) {
		this->chis = a;
		this->znam = b;

		return true;
	}
	else {
		return false;
	}
}
