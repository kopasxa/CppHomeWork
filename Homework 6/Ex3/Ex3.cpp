#include <iostream>
#include "time.h"

using namespace std;

void fill( int arr[], int size ) {
    int i;

    for (i = 0; i < size; i++) {
        arr[i] = rand() % 20;
    }
}

void outputArr( int arr[], int size ) {
    int i;

    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    srand(time(NULL));

    int arr1size,
        arr2size;

    cout << "1 & 2 size arr: ";
    cin >> arr1size >> arr2size;

    int* arr1 = new int[arr1size];
    int* arr2 = new int[arr2size];
    int* arr3 = new int[arr1size + arr2size];

    fill(arr1, arr1size);
    fill( arr2, arr2size );

    int i;
    for (i = 0; i < arr1size; i++)
        arr3[i] = arr1[i];
    
    for (int k = 0; k < arr2size; k++, i++)
        arr3[i] = arr2[k];

    outputArr(arr1, arr1size);
    outputArr( arr2, arr2size );
    outputArr( arr3, arr1size + arr2size );

    delete[] arr1, arr2, arr3;
}

