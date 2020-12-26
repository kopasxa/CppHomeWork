#include <iostream>

using namespace std;

const int size = 10;

int view( int arr[] ),
    retake( int arr[] ),
    step( int arr[] );

int main() {
    setlocale(LC_ALL, "Russian");

    int i, 
        arr[::size],
        menu = 0,
        serAr = 0;
    
    cout << "Введите 10 оценок студента: " << endl;
    
    for (i = 0; i < ::size; i++) {
        cin >> arr[i];
    }

    while( true ) {
        cout << endl << "Что сделать?" << endl;
        cout << "1. Посмотреть оценки \n2. Пересдача \n3. Выходит ли стипендия\n";

        cin >> menu;

        switch (menu) {
            case 1:
                view( arr );
                break;

            case 2:
                retake( arr );
                break;

            case 3:
                step( arr );
                break;

            default:
                break;
        }
    }
}

int view( int arr[] ) {
    int i;

    for (i = 0; i < ::size - 1; i++) {
        cout << arr[i] << ", ";
    }

    cout << arr[::size - 1] << ".";

    return 0;
}

int step( int arr[] ) {
    int i, all = 0;
    float step;

    for (i = 0; i < ::size; i++) {
        all += arr[i];
    }

    step = float(all) / float(::size);

    if (step >= 10.7) {
        cout << "Стипендия выходит" << endl;
    }
    else {
        cout << "Стипендия не выходит (" << endl;
    }

    return 0;
}

int retake( int arr[] ) {

    int peres = 0, newO = 0;

    cout << "Оценки студента: " << endl;

    view( arr );

    cout << endl;

    cout << "Выберите номер оценки для пересдачи: " << endl;

    cin >> peres;

    cout << "Введите новую оценку: " << endl;

    cin >> newO;

    for (int i = 0; i < ::size; i++) {
        arr[peres] = newO;
    }

    cout << "Успешно изменено!" << endl;

    return 0;
}
