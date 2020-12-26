#include <iostream>

using namespace std;

int main() {
    setlocale( LC_ALL, "Russian" );

    int numA, numB, i;
    
    cout << "Введите число: ";
    cin >> numA;

    for (i = 1; i <= numA / 2; i++) {
        if ((numA % (i * i) == 0) && (numA % (i * i * i) != 0) && (i != numA / 2)) {
            cout << i << ", ";
        }
    }
}
