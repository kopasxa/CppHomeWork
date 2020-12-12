#include <iostream>

using namespace std;

int main() {
    setlocale( LC_ALL, "Russian" );

    int num, allNum = 0, sum = 0, sAr = 0, zero = 0, x, menuNum;

    cout << "Введите число: ";
    cin >> num;

    while (num >= 10) {
        x = num % 10;
        num /= 10;

        // *** Summa ***
        sum += x;

        // *** All Numbers ***
        allNum += 1;

        // *** Zero ***
        if (x == 0) {
            zero += 1;
        }
    }
    
    sum += num;
    allNum += 1;

    // ВОПРОС: Почему программа не видет первый ноль?

    // *** Ser Arifm ***
    sAr = sum / allNum;

    cout << "Выберете одно действие: " << endl << endl;
    cout << "1. Сумма цифр числа" << endl;
    cout << "2. Кол-во цифр в числе" << endl;
    cout << "3. Кол-во нулей в числе" << endl;
    cout << "4. Среднее арифметическое" << endl;

    cin >> menuNum;

    switch (menuNum) {
        case 1:
            cout << sum;
            break;
        case 2:
            cout << allNum;
            break;
        case 3:
            cout << zero;
            break;
        case 4:
            cout << sAr;
            break;
        default:
            cout << "Данный пункт не найден, попробуйте еще раз.";
            break;
    }
}