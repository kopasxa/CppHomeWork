//Инициализация квадратной матрицы;
//Вывод матрицы на экран;
//Определение максимального и минимального элемента на главной диагонали матрицы;
//Сортировка элементов по возрастанию отдельно для каждой строки матрицы.

#include <iostream>
#include <time.h>

using namespace std;

const int size = 10;

int init( int valueMatrix[::size][::size] ),
    output( int valueMatrix[::size][::size] ),
    maxmin( int valueMatrix[::size][::size] ),
    sort( int valueMatrix[::size][::size] );

double init( double valueMatrix[::size][::size] ),
       output( double valueMatrix[::size][::size] ),
       maxmin( double valueMatrix[::size][::size] ),
       sort( double valueMatrix[::size][::size] );

char init( char valuematrix[::size][::size] ),
     output( char valueMatrix[::size][::size] ),
     maxmin( char valueMatrix[::size][::size] ),
     sort( char valueMatrix[::size][::size] );

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int arr[::size][::size];
    double arrD[::size][::size];

    init(arr);
    output(arr);
    maxmin(arr);
    sort(arr);
    output(arr);
}

int init( int valueMatrix[::size][::size] ) {
    int i, j;
    
    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            valueMatrix[i][j] = rand() % 10;
        }
    }

    return 0;
}

double init( double valueMatrix[::size][::size] ) {
    int i, j;

    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            valueMatrix[i][j] = double( rand() % 10 ) + double( rand() % 100 ) / 100;
        }
    }

    return 0;
}

char init( char valueMatrix[::size][::size] ) {
    int i, j;

    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            valueMatrix[i][j] = rand() % 10;
        }
    }

    return 0;
}

int sort( int valueMatrix[::size][::size] ) {
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

double sort( double valueMatrix[::size][::size] ) {
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

char sort( char valueMatrix[::size][::size] ) {
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

int maxmin( int valueMatrix[::size][::size] ) {
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

double maxmin( double valueMatrix[::size][::size] ) {
    int i, j;
    double max = 0, min = 0;

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

char maxmin( char valueMatrix[::size][::size] ) {
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

int output( int valueMatrix[::size][::size] ) {
    int i, j;

    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            cout << valueMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

double output( double valueMatrix[::size][::size] ) {
    int i, j;

    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            cout << valueMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

char output( char valueMatrix[::size][::size] ) {
    int i, j;

    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            cout << valueMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
