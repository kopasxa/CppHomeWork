#include <time.h>
#include <iostream>

using namespace std;

int main() {
    setlocale( LC_ALL, "ru");

    srand(time(NULL));

    const int size = 10;
    int arr[size],
        i,
        maxNum,
        minNum = maxNum = 0;

    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100 - 50;
    }

    for (i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }

    minNum = maxNum = arr[0];

    for (i = 1; i < size; i++) {
        if (minNum >= arr[i]) {
            minNum = arr[i];
        }

        if (maxNum <= arr[i]) {
            maxNum = arr[i];
        }
    }

    cout << endl << "Самое маленькое значение в массиве: " << minNum;
    cout << endl << "Самое большое значение в массиве: " << maxNum;
}
