//Разработайте программу «Библиотека».Создайте структуру «Книга»( название, автор,
//                                                                издательство, жанр ).Создайте массив из 10 книг.Реализуйте для него следующие возможности :
//Редактировать книгу
//Печать всех книг
//Поиск книг по автору
//Поиск книги по названию
//Сортировка массива по названию книг
//Сортировка массива по автору
//Сортировка массива по издательству

#include <iostream>
#include <string>
#define size  10

using namespace std;

struct Book {
    string name,
           author,
           publishing,
           genre;
};

void init( Book library[] ) {
    int i;
    for (i = 0; i < size; i++) {
        library[i].name = "Язык программирования С++ " + to_string(i + 1);
        library[i].author = "Бьерн Страуструп. " + to_string( i + 1 );
        library[i].publishing = "Addison–Wesley " + to_string( i + 1 );
        library[i].genre = "Learninh " + to_string( i + 1 );
    }
}

void print( Book library[], int i ) {
    cout << "\tLibrary" << endl;
    
    cout << "Book №" << i + 1 << endl;
    cout << "  Book name: " << library[i].name << endl;
    cout << "  Author: " << library[i].author << endl;
    cout << "  Edition: " << library[i].publishing << endl;
    cout << "  Genre: " << library[i].genre << endl;
    cout << endl;
}

void find( Book library[], string phrase ) {
    string findPhrase, 
           finder; 
    bool err = false;
    if (phrase == "author") {
        cout << "Введите искаемого Автора: ";
    }
    else if (phrase == "name") {
        cout << "Введите искаемое название книги: ";
    }
    getline( cin, findPhrase );
    for (int i = 0; i < size; i++) {
        if (phrase == "author") {
            finder = library[i].author;
        }
        else if (phrase == "name") {
            finder = library[i].name;
        }
        if (finder.find( findPhrase ) != -1) {
            print( library, i );       
        }
    }
}

void edit( Book library[] ) {
    int num, 
        i;
    
    cout << "Номер редактируемой книги: " << endl;
    cin >> num;

    for (i = 0; i < size; i++) {
        if (num - 1 == i) {
            break;
        }
    }
    cout << "Name: ";
    cin >> library[i].name;
    cin.clear();
    cin.ignore();

    cout << "Author: ";
    cin >> library[i].author;
    cin.clear();
    cin.ignore();

    cout << "Edition: ";
    cin >> library[i].publishing;
    cin.clear();
    cin.ignore();

    cout << "Genre: ";
    cin >> library[i].genre;
    cin.clear();
    cin.ignore();
}

void sortName( Book library[], string type ) {
    Book temp;
    if (type == "name") {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (library[j].name > library[j + 1].name) {
                    temp = library[j];
                    library[j] = library[j + 1];
                    library[j + 1] = temp;
                }
            }
        }
    }
    else if (type == "author") {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (library[j].author > library[j + 1].author) {
                    temp = library[j];
                    library[j] = library[j + 1];
                    library[j + 1] = temp;
                }
            }
        }
    }
    else if (type == "publish") {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (library[j].publishing > library[j + 1].publishing) {
                    temp = library[j];
                    library[j] = library[j + 1];
                    library[j + 1] = temp;
                }
            }
        }
    }
    
}

int main() {
    setlocale(LC_ALL, "ru");
    int i, 
        j;

    Book library[size];

    init( library );

    for (i = 0; i < size; i++) {
        print( library, i );
    }
    cout << endl << endl;

    /*find( library, "name" );
    cout << endl << endl;
    find( library, "author" );
    cout << endl << endl;
    sortName( library, "author" );
    for (i = 0; i < size; i++) {
        print( library, i );
    }
    cout << endl << endl;*/

    edit( library );
    for (i = 0; i < size; i++) {
        print( library, i );
    }
    cout << endl << endl;
}
