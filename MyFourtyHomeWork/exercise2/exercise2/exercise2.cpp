//Нахождения максимального значения в одномерном массиве;
//Нахождения максимального значения в двумерном массиве;
//Нахождения максимального значения в трёхмерном массиве;
//Нахождения максимального значения двух целых; ??????
//Нахождения максимального значения трёх целых; ??????

#include <iostream>
#include <time.h>

using namespace std;

const int size = 10;

int maxEl(int arr[::size] ),
    maxEl(int arr[::size][::size]),
    maxEl(int arr[::size][::size][::size]);

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int arr[::size],
        arr2[::size][::size],
        arr3[::size][::size][::size];

    maxEl( arr );
    maxEl( arr2 );
    maxEl( arr3 );
}

int maxEl( int arr[::size] ) {
    int i, max = 0;

    for (i = 0; i < ::size; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << " ";
    }

    max = arr[0];

    for (i = 0; i < ::size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    cout << endl << "Max el: " << max << endl;

    return 0;
}

int maxEl( int arr[::size][::size][::size] ) {
    int i, j, k, max = 0;

    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            for (k = 0; k < ::size; k++) {
                arr[i][j][k] = rand() % 10;

                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    max = arr[0][0][0];

    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            for (k = 0; k < ::size; k++) {
                if (max < arr[i][j][k]) {
                    max = arr[i][j][k];
                }
            }
        }
    }
        
    cout << endl << "Max el: " << max << endl;

    return 0;
}

int maxEl( int arr[::size][::size] ) {
    int i, j, max = 0;

    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            arr[i][j] = rand() % 10;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    max = arr[0][0];

    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
            }
        }
    }

    cout << endl << "Max el: " << max << endl;

    return 0;
}



