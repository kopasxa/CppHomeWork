/* **** Реалізуйте клас «розумного покажчика», а також код для тестування даного класу. **** */

#include <iostream>
#include "SmartPtr.h"

using namespace std;

int main() {

	SmartPtr<int> smart = new int(1);

	cout << *smart;
}