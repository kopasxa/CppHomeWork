// Используя два указателя на массив целых чисел, скопировать один массив в другой.
// Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.

#include <iostream>
#include "time.h"

using namespace std;

const int size = 10;

int fill( int arr[] ),
    output( int arr[] ),
    copy( int* ptr1, int* ptr2 ),
    out( int n );

int main() {
    srand(time(NULL));

    int arr1[::size],
        arr2[::size],
        i;

    int *ptr1 = arr1,
        *ptr2 = arr2;
    
    fill( arr1 );
    output( arr1 );
    out(1);
    fill( arr2 );
    output( arr2 );
    out(3);

    copy( ptr1, ptr2 );
}

int fill( int arr[] ) {
    for (int i = 0; i < ::size; i++) {
        arr[i] = rand() % 100;
    }

    return 0;
}

int out( int n ) {
    cout << endl;

    if ( n > 0) {
        return out( n - 1 );
    }
}

int copy( int *ptr1, int *ptr2 ) {
    for (int i = 0; i < ::size; i++) {
        *(ptr2 + i) = *(ptr1 + i);
    }
    output( ptr1 );
    out(1);
    output( ptr2 );
    out(0);
    return 0;
}

int output( int arr[] ) {
    for (int i = 0; i < ::size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
