#include <iostream>
#include "myString.h"

using namespace std;

int main() {
	char kek[] = "hello world";
	myString str( kek );
	str.cinS();
	str.coutS();
	cout << str('t');
	cout << str[5];
	cout << endl;
	str.coutS();
	str++;
	cout << endl;
	str.coutS();
	cout << endl;
	str--;
	str.coutS();
}
