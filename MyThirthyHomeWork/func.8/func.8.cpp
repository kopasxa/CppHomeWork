// Написать функцию, меняющую порядок следования
// элементов передаваемого ей массива на противоположный.

#include <iostream>
#include <time.h>

using namespace std;

void reverse(int arr[10], int arr2[10]) {
    int i,
        j;

    i = 9;
    j = 0;

    while (0 <= i && j < 10) {
        arr[j] = arr2[i];
        cout << arr[j] << ". ";
        i--;
        j++;

    }
}

int main() {
    srand(time(NULL));

    int arr[10],
        arr2[10],
        i,
        j;

    for (i = 0; i < 10; i++) {
        arr[i] = arr2[i] = rand() % 200;
        cout << arr[i] << ", ";
    }

    cout << endl;

    reverse(arr, arr2);
}
