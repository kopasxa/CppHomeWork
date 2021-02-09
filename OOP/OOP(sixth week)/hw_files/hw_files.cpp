#include <iostream>
#include <string>
#include "function.h"

using namespace std;

int main() {
    setlocale( LC_ALL, "ru" );

    todo list[sizeList];

    cout << "\t\tTO-DO LIST" << endl;

    bool working = true;

    while (working) {
        cout << "\n\tMENU" << endl;
        cout << "1. Список заданий" << endl;
        cout << "2. Удалить задание" << endl;
        cout << "3. Редактировать задание" << endl;
        cout << "4. Найти задание" << endl;
        cout << "5. Добавить задание" << endl;
        cout << "6. Записать все данные в файл" << endl;
        cout << "7. Вывести все данные из файла" << endl;
        cout << "8. Остановить работу программы" << endl;

        int menu;

        cin >> menu;

        if (menu == 1) {
            printList( list );
        }
        else if (menu == 2) {
            bool isDel = deleteQ( list );

            if (!isDel)
                cout << "Не удалось удалить задачу (" << endl;
        }
        else if (menu == 3) {
            bool isEdit = edit( list );

            if (!isEdit)
                cout << "Не удалось редактировать задачу (" << endl;
        }
        else if (menu == 4) {
            bool isFind = search( list );

            if (!isFind)
                cout << "Подходящих заданий не найдено (" << endl;
        }
        else if (menu == 5) {
            bool isAdd = addTo( list );

            if (!isAdd)
                cout << "Переполнено кол-во добавляемых задач (" << endl;
        }
        else if (menu == 6) {
            inFile( list );
        }
        else if (menu == 7) {
            outFile( list );
        }
        else if (menu == 8) {
            working = false;
        }
    }
}
