#include <iostream>

using namespace std;

int main() {
    setlocale( LC_ALL, "Russian" );
    int i = 0, a = 0, k;

    cout << "Введите число: ";
    cin >> k;
    cout << endl;

    while (k > 0) {
        if (k % 10 != 3 && k % 10 != 6) {
            a *= 10;
            a += k % 10;
        }
        k /= 10;
    }

    cout << "Полученное число: ";

    while (a > 0) {
        cout << a % 10;
        a /= 10;
    }
    cout << endl << endl;
}