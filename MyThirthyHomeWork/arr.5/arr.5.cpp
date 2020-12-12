// Напишите программу, которая выполняет поэлементную сумму двух массивов и результат заносит в третий массив.

#include <iostream>
#include <time.h>

using namespace std;

int main() {
    srand( time( NULL ) );

    const int size = 10;
    int i,
        arr1[size],
        arr2[size],
        arrSum[size];

    for (i = 0; i < size; i++) {
        arr1[i] = rand() % 300;
        arr2[i] = rand() % 300;
        arrSum[i] = arr1[i] + arr2[i];
    }

    for (i = 0; i < size; i++) {
        cout << arr1[i] << ", ";
    }

    cout << endl;

    for (i = 0; i < size; i++) {
        cout << arr2[i] << ", ";
    }

    cout << endl;

    for (i = 0; i < size; i++) {
        cout << arrSum[i] << ", ";
    }
}