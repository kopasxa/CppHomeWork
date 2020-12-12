#include <iostream>
#include <time.h>

using namespace std;

const int size = 10;

template <typename T1> 
T1 maxEl( T1 arr[::size]) {
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

template <typename T2>
T2 maxEl( T2 arr[::size][::size] ) {
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

template <typename T3>
T3 maxEl( T3 arr[::size][::size][::size] ) {
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

template <typename T> T init( T valueMatrix[::size][::size] ) {
    int i, j;

    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            valueMatrix[i][j] = rand() % 10;
        }
    }

    return 0;
}

template <typename T> T output( T valueMatrix[::size][::size] ) {
    int i, j;

    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            cout << valueMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

template <typename T> T maxmin( T valueMatrix[::size][::size] ) {
    int i, j, max = 0, min = 0;

    cout << endl;
    min = max = valueMatrix[0][0];

    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            if (i == j) {
                if (min > valueMatrix[i][j])
                    min = valueMatrix[i][j];

                if (max < valueMatrix[i][j])
                    max = valueMatrix[i][j];
            }
        }
    }

    cout << "Максимальное значение: " << max << endl << "Минимальное значение: " << min << endl << endl;

    return 0;
}

template <typename T> T sort( T valueMatrix[::size][::size] ) {
    int i, j, k, temp, val;

    val = valueMatrix[0][0];

    for (i = 0; i < ::size; i++) {
        for (j = 1; j < ::size; j++) {
            for (k = 0; k < ::size - j; k++) {
                if (valueMatrix[i][k + 1] < valueMatrix[i][k]) {
                    temp = valueMatrix[i][k];
                    valueMatrix[i][k] = valueMatrix[i][k + 1];
                    valueMatrix[i][k + 1] = temp;
                }
            }
        }
    }

    return 0;
}

int main() {
    setlocale( LC_ALL, "Russian" );
    srand( time( NULL ) );

    int arr[::size][::size];

    init( arr );
    output( arr );
    maxmin( arr );
    sort( arr );
    output( arr );

    int arr1[::size],
        arr2[::size][::size],
        arr3[::size][::size][::size];

    maxEl( arr1 );
    maxEl( arr2 );
    maxEl( arr3 );
}
