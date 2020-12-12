//Используя указатели и оператор разыменования, обменять местами значения двух переменных.

#include <iostream>

using namespace std;

int main() {
    int a,
        b,
        *ptA = &a,
        *ptB = &b,
        temp;

    cout << "Input a two numbers: " << endl;
    cin >> a >> b;
    cout << endl;
    cout << *ptA << ", " << *ptB;
    cout << endl;

    temp = *ptA;
    *ptA = *ptB;
    *ptB = temp;

    cout << *ptA << ", " << *ptB;
}
