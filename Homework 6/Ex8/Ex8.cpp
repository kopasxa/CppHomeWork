#include <iostream>
#include "string.h"
#include <stdio.h>
#include "ctype.h"

using namespace std;

void del( char str[], int n ),
     delin ( char str[], char n ),
     pastein( char str[], char n, int num );

bool polindrom( char* word );

int main() {
    setlocale(LC_ALL, "Rus");

    const int maxlen = 128;
    char str[maxlen];
    int num,
        sum = 0;
    char n;

    char listletter[] = "zxcvbnmasdfghjklpoiuytrewqёйцукенгшщзхъэждлорпавыфячсмитьбюіїє";
    char listnum[]    = "1234567890";
    char str2[]       = "ltk1 ltk2 ltk3";
    char polin[256];

    int letter = 0,
        colnum = 0,
        words  = 1;

    cout << "Введите строку: ";
    gets_s(str);

    int leng = strlen(str);

    int number;

    while (1) {
        cout << endl << endl << "1. Удалить символ с  заданным номером \n" << "2. Удалить из строки все вхождения в нее заданного символа\n" << "3. Вставить в указанную позицию заданный символ\n" << "4. Заменить все символы точки \".\" в строке\n" << "5. Сколько искомого символа\n" << "6. Количество букв, количество цифр и количество остальных символов\n" << "7. Заменить в ней все пробелы на табуляции\n" << "8. Количество букв, цифр и остальных символов, присутствующих в строке\n" << "9. Количество слов во введенном предложении\n" << "10. Проверить является ли эта строка палиндромом\n";

        cout << endl << "Введите номер задачки: " << endl;
        cin >> number;

        switch (number) {
            case 1:
                cout << "Теперь номер символа который удалить:" << endl;
                cin >> num;

                del( str, num );
                break;
            case 2:
                cout << "Теперь символы которые удалить: ";
                
                cin >> n;

                delin( str, n );
                break;
            case 3:
                cout << "Теперь позицию и символ: ";

                cin >> num >> n;

                pastein( str, n, num );
                break;
            case 4:
                int i;

                for (i = 0; i < leng; i++) {
                    if (str[i] == '.') {
                        str[i] = '!';
                    }
                    cout << str[i];
                }

                break;
            case 5:
                cout << "Введите символ который ищите: ";
                cin >> n;

                for (i = 0; i < leng; i++) {
                    if (str[i] == n) {
                        sum++;
                    }
                }
                cout << "Символ \"" << n << "\" в строке \"" << str << "\" встречается " << sum << " раз" << endl;

                break;
            case 6:

                for (i = 0; i < leng; i++) {
                    for (int j = 0; j < strlen( listletter ); j++) {
                        if (tolower( str[i] ) == listletter[j]) {
                            letter++;
                        }
                    }
                    for (int j = 0; j < strlen( listnum ); j++) {
                        if (str[i] == listnum[j]) {
                            colnum++;
                        }
                    }
                }
                cout << "Кол-во букв: " << letter << endl << "Кол-во цифр: " << colnum << endl << "Остальные символы: " << leng - letter - colnum << endl;

                break;
            case 7:
                for (i = 0; i < strlen( str2 ); i++) {
                    if (str2[i] == ' ') {
                        str2[i] = '\t';
                    }
                    
                }
                cout << str2;
                break;
            case 8:
                for (i = 0; i < strlen( str2 ); i++) {
                    for (int j = 0; j < strlen( listletter ); j++) {
                        if (tolower( str2[i] ) == listletter[j]) {
                            letter++;
                        }
                    }
                    for (int j = 0; j < strlen( listnum ); j++) {
                        if (str2[i] == listnum[j]) {
                            colnum++;
                        }
                    }
                }
                cout << "Кол-во букв: " << letter << endl << "Кол-во цифр: " << colnum << endl << "Остальные символы: " << strlen( str2 ) - letter - colnum << endl;
                break;
            case 9:
                for (i = 0; i < leng; i++) {
                    if (str[i] == ' ') {
                        if (i < leng - 1) {
                            if (str[i + 1] != ' ') {
                            //    i++;
                            //}
                            //else {
                                words++;
                            }
                        }
                    }
                }

                cout << "Кол-во слов в строке \"" << str << "\": " << words;
                break;
            case 10:
                if (polindrom( str )) {
                    cout << "Палиндром";
                }
                else {
                    cout << "Не палиндром";
                }
                break;
            default:
                break;
        }
    }
}

bool polindrom( char* word ) {
    int leng = strlen( word );
    for (int i = 0; i < leng / 2; ++i) {
        if (word[i] != word[leng - i - 1]) {
            return false;
        }
    }
    return true;
}

void del( char str[], int n ) {
    int i,
        j;

    char* newstr = new char[strlen( str ) - 1];

    for (i = 0, j = 0; i < strlen( str ); i++, j++) {
        if (i != n - 1) {
            newstr[j] = str[i];
            cout << newstr[j];
        }
        else {
            j--;
        }
    }
}

void delin( char str[], char n ) {
    int i,
        col = 0;

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == n) {
            col++;
        }
    }

    char* newstr = new char[strlen(str) - col];

    int j;

    for (i = 0, j = 0; i < strlen(str); i++, j++) {
        if (str[i] != n) {
            newstr[j] = str[i];
            cout << newstr[j];
        }
        else {
            if (j > 1) {
                j--;
            }
        }
    }
}

void pastein( char str[], char n, int num ) {
    int i;

    for (i = strlen(str); i > num - 2; i--) {
        str[i + 1] = str[i];
    }
    str[num - 1] = n;

    for (i = 0; i < strlen(str); i++) {
        cout << str[i];
    }
}