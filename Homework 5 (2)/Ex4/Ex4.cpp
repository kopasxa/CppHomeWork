// Написать рекурсивную функцию, которая вычисляет сумму всех чисел в диапазоне от a до b.Пользователь вводит a и b.Проиллюстрируйте работу функции примером.

#include <iostream>

using namespace std;

int sum( int a, int b );

int main() {
    int a, 
        b;

    cout << "Please enter two numbers: " << endl;

    cin >> a >> b;

    cout << "Sum two number is: " << sum( a, b );
}

int sum( int a, int b ) {
    if (b == a - 1) {
        return 0;
    } 
    else {
        return b + sum( a, b - 1 );
    }
}
