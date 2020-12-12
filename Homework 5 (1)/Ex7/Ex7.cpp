// Напишите рекурсивную функцию, которая принимает одномерный массив из 100 целых чисел, заполненных случайным
// образом, и находит позицию, с которой начинается последовательность из 10 чисел, сумма которых минимальна.

#include <iostream>
#include "time.h"

using namespace std;

const int size = 100;

int topTen( int arr[], int j, int& k );

int main() {
    srand(time(NULL));

    int arr[::size],
        k;

    for (int i = 0; i < ::size; i++) {
        arr[i] = rand() % 1000;
    }

    for (int i = 0; i < ::size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    topTen( arr, 0, k);

    cout << endl << "Min pos: " << k << endl;
}

int topTen( int arr[], int j, int& k ) {
    int sum1 = 0;

    for (int i = j; i < j + 10; ++i) {
        sum1 += arr[i];
    }

    /* cout << "j: " << j << ", sum: " << sum1 << endl; */

    if (100 - j == 10) {
        k = j;
        return sum1;
    }
    else {
        int sum2 = topTen( arr, j + 1, k );
        if (sum1 <= sum2) {
            k = j;
            return sum1;
        }
        else {
            return sum2;
        }
    }
}