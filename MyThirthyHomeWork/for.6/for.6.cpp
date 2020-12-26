#include <iostream>

using namespace std;

int main() {
    setlocale( LC_ALL, "Russian" );

    int numA, numB = 0, i = 0, g;

    cout << "Введите число: ";
    cin >> numA;
    g = numA;

    while (numA >= 10) {
        i = numA % 10;
        numA /= 10;
        numB += i;
    }

    numB += numA;

    int cub = numB * numB * numB;
    if (cub == g * g) {
        cout << "yes";
    }
}
