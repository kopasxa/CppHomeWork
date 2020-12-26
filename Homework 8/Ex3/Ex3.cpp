#include "time.h"
#include <iostream>

using namespace std;

void init( int* arr[], int row, int col ) {
    int i, j; 

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            arr[i][j] = rand () % 9;
        }
    }
}

void output( int* arr[], int row, int col ) {
    int i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
}

void shift( int* arr[], int row, int col, char where, int pos ) {
    int i, 
        j,
        k;

    int* arrTempCol = new int[col];
    int* arrTempRow = new int[row];

    int** newArr = new int*[row];

    int** oldArr = new int*[row];

    for (i = 0; i < row; i++) {
        oldArr[i] = new int[col];
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            oldArr[i][j] = arr[i][j];
        }
    }

    switch (where) {
        case 'w': 
            for (k = 0; k < pos; k++) {
                for (i = 0; i < col; i++) {
                    arrTempRow[i] = oldArr[0][i];
                    /*cout << arrTempRow[i] << " ";*/
                }

                cout << endl << endl;

                for (i = 0; i < row; i++) {
                    newArr[i] = new int[col];
                    for (j = 0; j < col; j++) {
                        if (i == row - 1) {
                            newArr[i][j] = arrTempRow[j];
                        }
                        else {
                            newArr[i][j] = oldArr[i + 1][j];
                        }
                    }
                }

                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        cout << newArr[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;

                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        oldArr[i][j] = newArr[i][j];
                    }
                }
            }
            break;
        case 'a':
            for (k = 0; k < pos; k++) {
                for (i = 0; i < row; i++) {
                    arrTempCol[i] = oldArr[i][0];
                    /*cout << arrTemp[i] << " ";*/
                }

                cout << endl << endl;

                for (i = 0; i < row; i++) {
                    newArr[i] = new int[col];
                    for (j = 0; j < col; j++) {
                        if (j == col - 1) {
                            newArr[i][j] = arrTempCol[i];
                        }
                        else {
                            newArr[i][j] = oldArr[i][j + 1];
                        }
                    }
                }

                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        cout << newArr[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;

                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        oldArr[i][j] = newArr[i][j];
                    }
                }
            }
            break;
        case 's':
            for (k = 0; k < pos; k++) {
                for (i = 0; i < col; i++) {
                    arrTempRow[i] = oldArr[row - 1][i];
                    /*cout << arrTempRow[i] << " ";*/
                }

                cout << endl << endl;

                for (i = 0; i < row; i++) {
                    newArr[i] = new int[col];
                    for (j = 0; j < col; j++) {
                        if (i == 0) {
                            newArr[i][j] = arrTempRow[j];
                        }
                        else {
                            newArr[i][j] = oldArr[i - 1][j];
                        }
                    }
                }

                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        cout << newArr[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;

                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        oldArr[i][j] = newArr[i][j];
                    }
                }
            }
            break;
        case 'd':
            for (k = 0; k < pos; k++) {
                for (i = 0; i < row; i++) {
                    arrTempCol[i] = oldArr[i][col - 1];
                    /*cout << arrTemp[i] << " ";*/
                }

                cout << endl << endl;

                for (i = 0; i < row; i++) {
                    newArr[i] = new int[col];
                    for (j = 0; j < col; j++) {
                        if (j == 0) {
                            newArr[i][j] = arrTempCol[i];
                        }
                        else {
                            newArr[i][j] = oldArr[i][j - 1];
                        }
                    }
                }

                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        cout << newArr[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;

                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        oldArr[i][j] = newArr[i][j];
                    }
                }
            }
            break;
        default:
            break;
    }

    delete[] arrTempCol;
    delete[] arrTempRow;

    for (int i = 0; i < row; i++) {
        delete[] newArr[i];
    }
    delete[] newArr;

    for (int i = 0; i < row; i++) {
        delete[] oldArr[i];
    }
    delete[] oldArr;
}

int main() {
    srand(time(NULL));

    int row = 5, 
        col = 6;

    int** pArr = new int*[row];
    for (int i = 0; i < row; i++) {
        pArr[i] = new int[col];
    }

    init( pArr, row, col );
    output( pArr, row, col );

    char shiftChar;
    int quantity;

    cout << "Enter shift: (w, a, s, d)\n";
    cin >> shiftChar;
    cout << "Enter quantity: \n";
    cin >> quantity;

    shift( pArr, row, col, shiftChar, quantity );

    for (int i = 0; i < row; i++) {
        delete[] pArr[i];
    }
    delete[] pArr;
}
