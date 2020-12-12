//Реализовать структуру «Машина»( цвет, модель, номер ).Номер машины может представлять из
//себя или пятизначный номер или слово до 8 символов.
//Рекомендации: номер реализовать как объединение.
//Создать экземпляр структуры «Машина» и реализовать для него следующие функции :

#include <iostream>
#include <string>
#define size  10
#include <limits>
using namespace std;

struct car {
    string color,
        model,
        number;
};

void init( car cars[] ) {
    int i;
    for (i = 0; i < size; i++) {
        cars[i].color = "Black " + to_string( i + 1 );
        cars[i].model = "Tesla model 3 " + to_string( i + 1 );
        cars[i].number = "BA7917BA " + to_string( i + 1 );
    }
}

void print( car cars[], int i ) {
    cout << "Car №" << i + 1 << endl;
    cout << "  Color: " << cars[i].color << endl;
    cout << "  Model: " << cars[i].model << endl;
    cout << "  Number: " << cars[i].number << endl;
    cout << endl;
}

void find( car cars[] ) {
    string findPhrase;

    cout << "Введите искаемый номер автомобиля: ";

    getline( cin, findPhrase );
    for (int i = 0; i < size; i++) {
        if (cars[i].number.find( findPhrase ) != -1) {
            print( cars, i );
        }
    }
}

void edit( car cars[] ) {
    int num,
        i;

    cout << "Номер редактируемого автомобиля: " << endl;
    cin >> num;

    for (i = 0; i < size; i++) {
        if (num - 1 == i) {
            break;
        }
    }
    string color,
           model,
           number;

    cout << "Color: ";
    cin >> cars[i].color;
    cin.clear();
    cin.ignore();

    cout << "Model: ";
    getline( cin, cars[i].model );
    cin.clear();
    cin.ignore();

    cout << "Number: ";
    cin >> cars[i].number;
}

void sortName( car cars[] ) {
    car temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (cars[j].number > cars[j + 1].number) {
                temp = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = temp;
            }
        }
    }
}

int main() {
    setlocale( LC_ALL, "ru" );
    int i;

    car cars[size];

    init( cars );

    for (i = 0; i < size; i++) {
        print( cars, i );
    }
    cout << endl << endl;

    find( cars );
    cout << endl << endl;

    edit( cars );
    for (i = 0; i < size; i++) {
        print( cars, i );
    }
    cout << endl << endl;

    cout << "**** SORT ****" << endl;
    sortName( cars );

    for (i = 0; i < size; i++) {
        print( cars, i );
    }
    cout << endl << endl;
}
