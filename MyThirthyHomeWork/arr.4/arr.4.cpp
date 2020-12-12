//Написать программу, копирующую последовательно элементы одного массива размером 10 элементов в 2 массива размером 5 элементов каждый.

#include <iostream>
#include <time.h>

using namespace std;

int main() {
    srand(time(NULL));

    const int bigSize = 10, smallSize = bigSize / 2;
    int bigArr[bigSize],
        smallArr1[smallSize],
        smallArr2[smallSize],
        i,
        j = 0,
        k = 0;

    cout << "Big array: ";

    for (i = 0; i < bigSize; i++) {
        bigArr[i] = rand() % 300;
        cout << bigArr[i] << ", ";
    }

    cout << endl << "1 array: ";

    for (i = 0; i < bigSize; i++) {
        if (i >= smallSize) {
            smallArr2[j] = bigArr[i];
            j++;
        }
        else {
            smallArr1[k] = bigArr[i];
            k++;
        }
    }

    for (i = 0; i < smallSize; i++) {
        cout << smallArr1[i] << ", ";
    }

    cout << "." << endl << "2 array: ";

    for (i = 0; i < smallSize; i++) {
        cout << smallArr2[i] << ", ";
    }

    cout << ".";
}
