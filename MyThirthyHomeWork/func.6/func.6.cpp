// Написать функцию, которая проверяет, является ли переданное ей число простым? Число называется простым, 
// если оно делится без остатка только на себя и на единицу.

#include <iostream>

using namespace std;

void prosto(int number) {
    if (number % number == 0 && number / 1 == number) {
        cout << "chislo prostoe) ";
    }
}

int main() {
    prosto(-34);
}

