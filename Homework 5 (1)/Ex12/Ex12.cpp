// Используя указатели и оператор разыменования, определить знак числа, введённого с клавиатуры.

#include <iostream>

using namespace std;

int main() {
    long num,
        *pt = &num;

    cout << "Please input a number: ";
    cin >> num;

    if (*pt >= 0) {
        cout << "Number " << *pt << " plus sign";
    }
    else {
        cout << "Number " << *pt << " minus sign";
    }
}

