//Создайте динамический массив, хранящий в первой строке имя, а во второй - телефон.
//Организуйте поиск по имени и по номеру телефона и возможность ввода и изменения данных.

#include <iostream>
#include <string>

using namespace std;

void output( string**& arr, int sizeRow, int sizeCol ) {
    int i;

    for (i = 0; i < sizeRow; i++) {
        cout << arr[i][0]; 
        cout << "Имя: " << arr[i][1] << endl;
        cout << "Телефон: " << arr[i][2] << endl << endl;
    }
}

int main() {
    setlocale( LC_ALL, "ru" );
    int sizeRow = 3,
        sizeCol = 3,
        i,
        j,
        menuNum;

    string** mainArr = new string * [sizeRow];
    for (int i = 0; i < sizeRow; i++) {
        mainArr[i] = new string[sizeCol];
    }

    for (i = 0; i < sizeRow; i++) {
        mainArr[i][0] = to_string( i + 1 ) + ". ";
        cout << "Введите имя: ";
        cin >> mainArr[i][1];
        cout << "Введите номер телефона: ";
        cin >> mainArr[i][2];
        cout << endl;
    }

    while (true) {
        cout << "1. Ввести данные" << endl;
        cout << "2. Найти по телефону" << endl;
        cout << "3. Найти по имени" << endl;
        cout << "4. Изменить данные" << endl;
        cout << "5. Вывести" << endl;

        cin >> menuNum;

        if (menuNum == 1) {
            for (i = 0; i < sizeRow; i++) {
                mainArr[i][0] = to_string( i + 1 ) + ". ";
                cout << "Введите имя: ";
                cin >> mainArr[i][1];
                cout << "Введите номер телефона: ";
                cin >> mainArr[i][2];
                cout << endl;
            }
        }
        if (menuNum == 2) {
            string number;

            cout << "Введите искомый телефон: ";
            cin >> number;
            cout << endl;

            for (i = 0; i < sizeRow; i++) {
                if (mainArr[i][2].find( number, 0 ) != string::npos) {
                    cout << mainArr[i][0];
                    cout << "Имя: " << mainArr[i][1];
                    cout << " Телефон: " << mainArr[i][2];
                    cout << endl << endl;
                }
            }
        }
        if (menuNum == 3) {
            string nameFind;

            cout << "Введите искаемое имя: ";
            cin >> nameFind;
            cout << endl;

            for (i = 0; i < sizeRow; i++) {
                if (mainArr[i][1].find( nameFind, 0 ) != string::npos) {
                    cout << mainArr[i][0];
                    cout << "Имя: " << mainArr[i][1];
                    cout << " Телефон: " << mainArr[i][2];
                    cout << endl << endl;
                }
            }
        }
        if (menuNum == 4) {
            output( mainArr, sizeRow, sizeCol );
            int numStr;

            cout << "Введите номер строки: "; 
            cin >> numStr; 
            mainArr[numStr - 1][0] = to_string( numStr ) + ". ";
            cout << "Введите имя: ";
            cin >> mainArr[numStr - 1][1];
            cout << "Введите номер телефона: ";
            cin >> mainArr[numStr - 1][2];
            cout << endl;
            
        }
        if (menuNum == 5) {
            output( mainArr, sizeRow, sizeCol );
        }
    }

    delete[] mainArr;
    for (int i = 0; i < sizeRow; i++) {
        delete[]mainArr[i];
    }
}