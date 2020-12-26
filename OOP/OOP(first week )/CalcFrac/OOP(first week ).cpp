#include <iostream>
#include "fraction.h"
#include "function.h"

using namespace std;

int main() {
    bool run = true;

    while (run) {
        cout << "Please input fraction1" << endl;
        cout << "Chiselnik: ";
        int a, b;
        cin >> a;
        cout << "Znamennik: ";
        cin >> b;

        cout << "Please input fraction2" << endl;
        cout << "Chiselnik: ";
        int a1, b1;
        cin >> a1;
        cout << "Znamennik: ";
        cin >> b1;

        fraction drob1( a, b );
        fraction drob2( a1, b1 );

        char operation;
        cout << "Operation (+, -, /, *): ";
        cin >> operation;

        if (operation == '+') {
            additionSubtraction( drob1, drob2, '+' );
        }
        else if (operation == '-') {
            additionSubtraction( drob1, drob2, '-' );
        }
        else if (operation == '/') {
            multiplyDivide( drob1, drob2, '/' );
        }
        else if (operation == '*') {
            multiplyDivide( drob1, drob2, '*' );
        }
        else {
            cout << "Error 404: there is no such operation\n";
        }

        cout << "\nInput 1 for continue / 0 for close: ";
        int g;
        cin >> g;

        if (g != 1)
            run = false;
    }
}
