//В одномерном массиве, состоящем из N вещественных чисел вычислить :
//• Сумму отрицательных элементов.
//• Произведение элементов, находящихся между min и max элементами.
//• Произведение элементов с четными номерами.
//• Сумму элементов, находящихся между первым и последним отрицательными

#include <iostream>
#include <time.h>

using namespace std;

int main() {

    setlocale( LC_ALL, "ru");
    srand(time(NULL));

    const int size = 10;
    int i,
        arr[size],
        min,
        max,
        dobMiMa,
        dobChe = dobMiMa = 1,
        sumOtr,
        ot,
        doo,
        sumArr = min = max = sumOtr = ot = doo = 0;

    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100 - 50;
    }

    cout << "Элементы массива: ";

    for (i = 0; i < size - 1; i++) {
        cout << arr[i] << ", ";
    }

    cout << arr[size - 1] << "." << endl;

    min = max = arr[0];

    for (i = 1; i < size; i++) {
        if (min >= arr[i]) {
            min = arr[i];
        }

        if (max <= arr[i]) {
            max = arr[i];
        }
    }

    cout << endl << "Минимальное значение: " << min << endl << "Максимальное значение: " << max << endl;

    for (i = 0; i < size; i++) {
        if (min == arr[i]) {
            ot = i;
        }

        if (max == arr[i]) {
            doo = i;
        }
    }

    int xz = ot;
    if (ot > doo) {
        xz = doo;
        doo = ot;
    }

    for (i = xz; i <= doo; i++) {
        dobMiMa *= arr[i];
    }

    cout << endl << "Произведение элементов, находящихся между " << arr[xz] << " и " << arr[doo] << ": " << dobMiMa << endl;

    for (i = 0; i < size; i++) {
        if (arr[i] < 0) {
            ot = i;
            break;
        }
    }

    for (i = size - 1; i > 0; i--) {
        if (arr[i] < 0) {
            doo = i;
            break;
        }
    }

    for (i = ot + 1; i <= doo - 1; i++) {
        sumOtr += arr[i];
    }

    cout << endl << "Сумма элементов, находящихся между " << arr[ot] << " и " << arr[doo] << ": " << sumOtr << endl;

    for (i = 0; i < size; i++) {
        if (arr[i] < 0) {
            sumArr += arr[i];
        }
    }

    cout << endl << "Сумма отрицательных элементов: " << sumArr << endl;

    for (i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            dobChe *= arr[i];
        }
    }

    cout << endl << "Произведение элементов с четными номерами: " << dobChe << endl;
}