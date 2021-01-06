#include <iostream>
#include "myString.h"

using namespace std;

int myString::count = 0;

int main() {
	char kek[] = "hello world";
	myString str( kek );
	cin >> str;
	cout << str;
	cout << str('t');
	cout << str[5];
	cout << endl;
	cout << str;
	str++;
	cout << endl;
	cout << str;
	cout << endl;
	str--;
	cout << str;
	myString str2,
			 str3;
	cout << endl << "All objects: " << str.getCountObj();
}
