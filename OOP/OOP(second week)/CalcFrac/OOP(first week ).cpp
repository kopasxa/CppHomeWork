// Створіть клас Дріб( або використовуйте вже раніше створений вами ).Використовуючи перевантаження
// операторів реалізуйте для нього арифметичні операції для роботи з дробом( операції + , -, *, / ).
// Додайте перевантаження инкремента і декремента.

#include <iostream>
#include <string>
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

        fraction drob1( a, b );
        fraction result;

        string operation;
        cout << "Operation (+, -, /, *, a++, ++a, a--, --a): ";
        cin >> operation;

        if (operation != "a++" && operation != "++a" && operation != "a--" && operation != "--a") {
            cout << "Please input fraction2" << endl;
            cout << "Chiselnik: ";
            int a1, b1;
            cin >> a1;
            cout << "Znamennik: ";
            cin >> b1;

            fraction drob2( a1, b1 );

            if (operation == "+") {
                result = drob1 + drob2;
                result.simple();
                result.getFrac();
            }
            else if (operation == "-") {
                result = drob1 - drob2;
                result.simple();
                result.getFrac();
            }
            else if (operation == "/") {
                result = drob1 / drob2;
                result.simple();
                result.getFrac();
            }
            else if (operation == "*") {
                result = drob1 * drob2;
                result.simple();
                result.getFrac();
            }
        }
        else {
            if (operation == "a++") {
                result = drob1++;
                result.simple();
                result.getFrac();
            }
            else if (operation == "++a") {
                result = ++drob1;
                result.simple();
                result.getFrac();
            }
            if (operation == "a--") {
                result = drob1--;
                result.simple();
                result.getFrac();
            }
            else if (operation == "--a") {
                result = --drob1;
                result.simple();
                result.getFrac();
            }
            else {
                cout << "Error 404: there is no such operation\n";
            }
            cout << endl;
        }

        cout << "\nInput 1 for continue / 0 for close: ";
        int g;
        cin >> g;

        if (g != 1)
            run = false;
    }
}
