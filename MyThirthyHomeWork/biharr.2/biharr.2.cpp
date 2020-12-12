#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void variant1(),
     variant2(),
     variant3(),
     variant4(),
     variant5(),
     variant6(),
     variant7(),
     variant8(),
     variant9(),
     variant10();

const int sizeCol = 7,
          sizeRow = 7;

int arr[sizeRow][sizeCol],
    col,
    row;

int main() {
    setlocale( 0, "" );
    srand( time( NULL ) );
    int numEx,
        max = arr[0][0];
    
    while (true) {
        cout << "\nВведите вариант узора (0 - 10): " << endl;
        cin >> numEx;
        cout << endl;
        for (row = 1; row <= sizeRow; row++) {
            for (col = 1; col <= sizeCol; col++) {
                switch (numEx) {
                    case 1:
                        variant1();
                        break;
                    case 2:
                        variant2();
                        break;
                    case 3:
                        variant3();
                        break;
                    case 4:
                        variant4();
                        break;
                    case 5:
                        variant5();
                        break;
                    case 6:
                        variant6();
                        break;
                    case 7:
                        variant7();
                        break;
                    case 8:
                        variant8();
                        break;
                    case 9:
                        variant9();
                        break;
                    case 10:
                        variant10();
                        break;
                }
            }
            cout << endl;
        }

        for (row = 1; row < sizeRow; row++) {
            for (col = 1; col < sizeCol; col++) {
                if (max <= arr[row][col]) {
                    max = arr[row][col];
                }
            }
        }

        cout << "Максимальное значение: " << max;
    }

    
}

void variant1() {
    if ((col >= row)) {
        arr[row - 1][col - 1] = rand() % 9 + 1;
        cout << arr[row - 1][col - 1] << " ";
    }
    else {
        cout << "  ";
    }
}

void variant2() {
    if ((col <= row)) {
        arr[row - 1][col - 1] = rand() % 9 + 1;
        cout << arr[row - 1][col - 1] << " ";
    }
    else {
        cout << "  ";
    }
}

void variant3() {
    if (((col >= row) && (col - 1 + row <= sizeRow))) {
        arr[row - 1][col - 1] = rand() % 9 + 1;
        cout << arr[row - 1][col - 1] << " ";
    }
    else {
        cout << "  ";
    }
}

void variant4() {
    if ((!(col - 1 >= row) && !(col + row <= sizeRow))) {
        arr[row - 1][col - 1] = rand() % 9 + 1;
        cout << arr[row - 1][col - 1] << " ";
    }
    else {
        cout << "  ";
    }
}

void variant5() {
    if ((!(col - 1 >= row) && !(col + row <= sizeRow)) || ((col >= row) && (col - 1 + row <= sizeRow))) {
        arr[row - 1][col - 1] = rand() % 9 + 1;
        cout << arr[row - 1][col - 1] << " ";
    }
    else {
        cout << "  ";
    }
}

void variant7() {
    if (!(!(col <= row) || !(col - 1 + row <= sizeRow))) {
        arr[row - 1][col - 1] = rand() % 9 + 1;
        cout << arr[row - 1][col - 1] << " ";
    }
    else {
        cout << "  ";
    }
}

void variant6() {
    if (!(!(col <= row) || !(col - 1 + row <= sizeRow)) || ((col >= row) && !(col + row <= sizeRow))) {
        arr[row - 1][col - 1] = rand() % 9 + 1;
        cout << arr[row - 1][col - 1] << " ";
    }
    else {
        cout << "  ";
    }
}

void variant8() {
    if (((col >= row) && !(col + row <= sizeRow))) {
        arr[row - 1][col - 1] = rand() % 9 + 1;
        cout << arr[row - 1][col - 1] << " ";
    }
    else {
        cout << "  ";
    }
}

void variant10() {
    if (col - 1 + row >= sizeRow) {
        arr[row - 1][col - 1] = rand() % 9 + 1;
        cout << arr[row - 1][col - 1] << " ";
    }
    else {
        cout << "  ";
    }
}

void variant9() {
    if (col + row - 1 <= sizeRow) {
        arr[row - 1][col - 1] = rand() % 9 + 1;
        cout << arr[row - 1][col - 1] << " ";
    }
    else {
        cout << "  ";
    }
}
