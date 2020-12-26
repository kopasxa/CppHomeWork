// Написать рекурсивную функцию, которая выводит N звезд в ряд, число N задает пользователь.Проиллюстрируйте работу функции примером.

#include <iostream>

using namespace std;

int star( int n );

int main() {
    int n;

    cout << "Please enter number:" << endl;
    cin >> n;

    star(n);
}

int star( int n ) {
    cout << " * ";

    if (n > 1) {
        return star( n - 1 );
    }
}
