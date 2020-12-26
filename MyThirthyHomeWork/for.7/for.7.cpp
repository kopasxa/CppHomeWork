#include <iostream>

using namespace std;

int main() {
    setlocale( LC_ALL, "Russian" );

    int num1, num2, i = 0;

    cin >> num1;

    for (i = 1; i <= num1 / 2; i++) {
        if (num1 % i == 0 && i != num1 / 2) {
            cout << i << ", ";
        }
    }
    cout << num1 / 2 << ". ";
}