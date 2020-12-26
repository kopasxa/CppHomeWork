//Предоставьте пользователю возможность добавлять
//новых абонентов, удалять абонентов, искать абонентов
//по ФИО, показывать всех абонентов.

#include <iostream>
#include <string>
#include "Phone.h"

int sizeBook = 0;

using namespace std;

void addPhone( Phone phoneBook[] );
void addPhone( string fio, string phones[], string addInfo, Phone phoneBook[] );
void print( Phone phoneBook[] );
void findFIo( Phone phoneBook[] );
void delItem( Phone phoneBook[] );

int main() {
    setlocale(LC_ALL, "ru");
    
    Phone *phoneBook = new Phone[100];

    int menu;
    bool isRun = true;

    while (isRun) {
        cout << "\n\tMENU" << endl;
        cout << "1. Показать список контактов" << endl;
        cout << "2. Добавить контакт" << endl;
        cout << "3. Удалить контакт" << endl;
        cout << "4. Искать по ФИО" << endl;
        cout << "5. Exit" << endl;

        cin >> menu;

        if (menu == 1) {
            print( phoneBook ); 
        }
        else if (menu == 2) {
            addPhone( phoneBook );
        }
        else if (menu == 3) {
            delItem( phoneBook );
        }
        else if (menu == 4) {
            findFIo( phoneBook );
        }
        else if (menu == 5) {
            isRun = false;
        }
    }
}

void addPhone( Phone phoneBook[] ) {
    string fio, phones[3], addInfo;

    cout << "Введите ФИО контакта: ";
    cin.ignore();
    getline( cin, fio );

    cout << "Введите домашний телефон контакта: ";
    getline( cin, phones[0] );
    cout << "Введите рабочий телефон контакта: ";
    getline( cin, phones[1] );
    cout << "Введите мобильный телефон контакта: ";
    getline( cin, phones[2] );

    cout << "Введите дополнительную информацию для контакта: ";
    getline( cin, addInfo );

    phoneBook[sizeBook].setPhone( fio, phones, addInfo );
    sizeBook++;
}

void addPhone( string fio, string phones[], string addInfo, Phone phoneBook[] ) {
    phoneBook[sizeBook].setPhone( fio, phones, addInfo );
    sizeBook++;
}

void print( Phone phonebook[] ) {
    if (sizeBook > 0) {
        for (int i = 0; i < sizeBook; i++) {
            phonebook[i].getPhone();
        }
    }
    else {
        cout << "Error 404: не найдены записи" << endl;
    }
}

void findFIo( Phone phoneBook[] ) {
    if (sizeBook > 0) {
        cout << "Введите искаемую строку" << endl;
        string str;
        cin.ignore();
        getline( cin, str );

        for (int i = 0; i < sizeBook; i++) {
            if (phoneBook[i].getFio().find( str ) != -1) {
                phoneBook[i].getPhone();
            }
        }
    }
    else {
        cout << "Error 404: не найдены записи" << endl;
    }
}

void delItem( Phone phoneBook[] ) {
    cout << "Все контакты: ";
    print( phoneBook );
    cout << endl << "Введите номер удаляемого контакта: ";
    int n;
    cin >> n;

    /*if (n < sizeBook && n > 0) {*/
        for (int i = n - 1; i < sizeBook - 1; i++) {
            phoneBook[i] = phoneBook[i + 1];
        }
    /*}*/
    sizeBook--;
}
