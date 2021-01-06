// Створіть клас Дріб( або використовуйте вже раніше створений вами ).Використовуючи перевантаження
// операторів реалізуйте для нього арифметичні операції для роботи з дробом( операції + , -, *, / ).
// Додайте перевантаження инкремента і декремента.

#include <iostream>
#include <string>
#include "fraction.h"
#include <cstdarg>

using namespace std;

//fraction avr( int n, ... ) {
//    fraction result;
//
//    int temp = n;
//
//    va_list args;
//    va_start( args, n );
//
//    fraction sum( 0, 0 );
//
//    while (n--) {
//        sum = sum + va_arg( args, fraction );
//    }
//
//    va_end( args );
//
//    fraction tempF( temp, temp );
//
//    result = sum / tempF;
//
//    cout << result.getFrac();
//
//    return result;
//}

int main() {
    bool run = true;

    while (run) {
        cout << "Please input fraction1" << endl;
        
        fraction drob1;
        cin >> drob1;
        fraction result;

        string operation;
        cout << "Operation (+, -, /, *, a++, ++a, a--, --a, sum): ";
        cin >> operation;

        if (operation != "a++" && operation != "++a" && operation != "a--" && operation != "--a" && operation != "sum") {
            cout << "Please input fraction2" << endl;
            fraction drob2;
            cin >> drob2;

            if (operation == "+") {
                result = drob1 + drob2;
            }
            else if (operation == "-") {
                result = drob1 - drob2;
            }
            else if (operation == "/") {
                result = drob1 / drob2;
            }
            else if (operation == "*") {
                result = drob1 * drob2;
            }
        }
        /*else if ( operation == "sum") {
            fraction f1( 5, 6 ),
                     f2( 2, 9 ),
                     f3( 7, 3 );
            avr( 3, f1, f2, f3 );
        }*/
        else {
            if (operation == "a++") {
                result = drob1++;
            }
            else if (operation == "++a") {
                result = ++drob1;
            }
            if (operation == "a--") {
                result = drob1--;   
            }
            else if (operation == "--a") {
                result = --drob1;
            }
            else {
                cout << "Error 404: there is no such operation\n";
            }

            result.simple();
            cout << result;

            cout << endl;
        }

        cout << "\nInput 1 for continue / 0 for close: ";
        int g;
        cin >> g;

        if (g != 1)
            run = false;
    }
}

std::istream& operator>>( std::istream& in, fraction& d ) {
    cout << "Input chis: ";
    in >> d.chis;

    cout << "Input znam: ";
    in >> d.znam;

    return in;
}

std::ostream& operator<<( std::ostream& out, fraction& d ) {
    out << d.getFrac();

    return out;
}