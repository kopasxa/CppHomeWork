#include "fraction.h"
#include <cstdarg>

int fraction::nsk( fraction drob1 ) {
	int max, min;

	if (drob1.getZnam() < this->znam) {
		max = this->znam;
		min = drob1.getZnam();
	}
	else {
		max = drob1.getZnam();
		min = this->znam;
	}

	int nsk = max;

	while (nsk % min != 0) {
		nsk += max;
	}

	return nsk;
}

fraction fraction::simple() {
	int max;
	this->getChis() < this->getZnam() ? max = this->getZnam() : max = this->getChis();

	if (this->getChis() % this->getZnam() == 0) {
		this->integer = this->getChis() / this->getZnam();
		this->chis = 0;
		this->znam = 0;
	}
	else if (this->getChis() % this->getZnam() != 0) {
		int nZnam = this->getZnam();
		while (this->getChis() % nZnam != 0) {
			nZnam--;
		}
		this->integer = this->getChis() / nZnam;
		this->chis = this->getChis() % this->getZnam();
	}

	return *this;
}

bool fraction::getFrac() {
	if (this->chis != 0 && this->znam != 0) {
		if (this->integer != 0) cout << integer << "  ";
		cout << this->chis << "/" << this->znam << endl;

		return true;
	}
	else if (this->integer > 0) {
		cout << integer;
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

fraction fraction::operator+( fraction secondF ) {
	int newZnam = this->nsk( secondF );
	int newChis = this->chis * (newZnam / secondF.getZnam()) + secondF.getChis() * (newZnam / this->znam);

	fraction newF( newChis, newZnam );
	return newF;
}

fraction fraction::operator-( fraction secondF ) {
	int newZnam = this->nsk( secondF );
	int newChis = this->chis * (newZnam / secondF.getZnam()) - secondF.getChis() * (newZnam / this->znam);

	fraction newF( newChis, newZnam );
	return newF;
}

fraction fraction::operator*( fraction secondF ) {
	int newZnam = this->getZnam() * secondF.getZnam();
	int newChis = this->getChis() * secondF.getChis();

	fraction newF( newChis, newZnam );
	return newF;
}

fraction fraction::operator/( fraction secondF ) {
	int newZnam = this->getZnam() * secondF.getChis();
	int newChis = this->getChis() * secondF.getZnam();

	fraction newF( newChis, newZnam );
	return newF;
}

fraction fraction::operator++ () {
	fraction temp;
	temp = *this;
	fraction int1( 1, 1 );
	fraction result = this->operator+( int1 );
	*this = result;
	return temp;
}

fraction fraction::operator++ ( int i ) {
	fraction int1( this->znam, this->znam );
	int newZnam = this->nsk( int1 );
	int newChis = this->chis * (newZnam / int1.getZnam()) + int1.getChis() * (newZnam / this->znam);

	fraction result(newChis, newZnam);
	this->setFrac( result.getChis(), result.getZnam() );
	return *this;
}

fraction fraction::operator-- () {
	fraction temp;
	temp = *this;
	fraction int1( 1, 1 );
	fraction result = this->operator-( int1 );
	*this = result;
	return temp;
}

fraction fraction::operator-- ( int i ) {
	fraction int1( this->znam, this->znam );
	int newZnam = this->nsk( int1 );
	int newChis = this->chis * (newZnam / int1.getZnam()) - int1.getChis() * (newZnam / this->znam);

	fraction result( newChis, newZnam );
	this->setFrac( result.getChis(), result.getZnam() );
	return *this;
}

