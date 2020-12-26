// Написать функцию, вычисляющую факториал переданного ей числа

#include <iostream>

using namespace std;

int faktorial(int number) {
    int i, sum = 1;

    for (i = 1; i <= number; i++) {
        sum *= i;
    }

    return sum;
}

int main() {
    cout << "Faktorial: " << faktorial(5);
}

