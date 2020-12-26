#include <iostream>

using namespace std;

int main() {
    setlocale( LC_ALL, "Russian" );

    int num1, num2, i = 0;

    cout << "Введи число: ";

    cin >> num1 >> num2;

    for (i = 1; i <= (num1 + num2) / 2; i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            cout << i << ", ";
        }
    }
}