// Написать функцию, которая получает указатель на статический массив и его размер.
// Функция распределяет положительные, отрицательные и нулевые элементы в отдельные динамические массивы.
#include <iostream>
#include "time.h"

using namespace std;

int distributor( int* arr[], int size ),
    fill( int arr[], int size );

void output( int arr[], int size );

int main() {
    const int size = 10;
    int arr[size];
    int* ptr = arr;

    fill( ptr, size );
    output( ptr, size );
    distributor( &ptr, size );
}

int distributor( int* arr[], int size ) {
    int i,
        plus = 0,
        minus = 0,
        zero = 0,
        p = 0,
        m = 0,
        z = 0;

    int* ptr = *arr;

    for (i = 0; i < size; i++) {
        if (*(ptr + i) > 0) {
            plus++;
        }
        else if (*(ptr + i) < 0) {
            minus++;
        }
        else {
            zero++;
        }
    }

    int* arrplus = new int[plus];
    int* arrminus = new int[minus];
    int* arrzero = new int[zero];

    for (i = 0; i < size; i++) {
        if (*(ptr + i) > 0) {
            arrplus[p] = *(ptr + i);
            p++;
        }
        else if (*(ptr + i) < 0) {
            arrminus[m] = *(ptr + i);
            m++;
        }
        else {
            arrzero[z] = *(ptr + i);
            z++;
        }
    }

    cout << "Plus: ";
    output( arrplus, plus );
    cout << "Minus: ";
    output( arrminus, minus );
    cout << "Zero: ";
    output( arrzero, zero );

    return 0;

    delete[] arrplus, arrminus, arrzero;
}

void output( int arr[], int size ) {
    int i;

    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int fill( int arr[], int size ) {
    int i;
    srand(time(NULL));

    for (i = 0; i < size; i++) {
        arr[i] = (rand() % 20) - 10;
    }

    return 0;
}
