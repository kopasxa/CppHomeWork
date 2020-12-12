// Используя указатель на массив целых чисел, посчитать сумму элементов массива.

#include <iostream>
#include "time.h"

using namespace std;

int main() {
    srand(time(NULL));
    const int size = 10;
    int arr[size],
       *ptArr = arr,
        i,
        sum = 0;

    for (i = 0; i < size; i++) {
        ptArr[i] = rand() % 100;
    }

    for (i = 0; i < size; i++) {
        cout << ptArr[i] << " ";
    }

    for (i = 0; i < size; i++) {
        sum += *(ptArr + i);
    }

    cout << endl;

    cout << "Sum: " << sum;

}
