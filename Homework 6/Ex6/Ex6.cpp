#include <iostream>
#include "time.h"
using namespace std;

bool prostoe( int n ) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) 
            return false;
    return true;
}

int* del( int* arr, int& size ) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (!prostoe( arr[i] ))
            arr[j++] = arr[i];
    }
    int* arr2 = new int[size = j];
    for (int i = 0; i < size; i++) {
        arr2[i] = arr[i];
    }
    return arr2;

    delete[] arr2;
}

int main() {
    srand(time(NULL));
    int size,
        i;
    cin >> size;

    int* arr = new int[size];

    for (i = 0; i < size; i++) {
        arr[i] = rand() % 30;
        cout << arr[i] << " ";
    }

    cout << endl;

    int* arr2 = del( arr, size );
    for (i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }

    cout << endl;

    delete[] arr;
    delete[] arr2;
}
