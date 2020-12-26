// Написать примитивный калькулятор, пользуясь только указателями.

#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    float num1,
        num2,
        res,
       *ptNum1 = &num1,
       *ptNum2 = &num2,
       *ptRes  = &res;

    char sign,
        *ptS = &sign;

    cout << "\tКалькулятор" << endl;
    
    while (1) {
        cout << endl;
        cout << "Введите уравнение: " << endl;
        cin >> *ptNum1;
        //cout << "Знак: " << endl;
        cin >> *ptS;
        //cout << "Второе число: " << endl;
        cin >> *ptNum2;
        cout << endl;

        switch (*ptS) {
            case '+':
                *ptRes = *ptNum1 + *ptNum2;
                cout << *ptNum1 << " + " << *ptNum2 << " = " << *ptRes;
                break;
            case '-':
                *ptRes = *ptNum1 - *ptNum2;
                cout << *ptNum1 << " - " << *ptNum2 << " = " << *ptRes;
                break;
            case '/':
                *ptRes = *ptNum1 / *ptNum2;
                cout << *ptNum1 << " / " << *ptNum2 << " = " << *ptRes;
                break;
            case '*':
                *ptRes = *ptNum1 * *ptNum2;
                cout << *ptNum1 << " * " << *ptNum2 << " = " << *ptRes;
                break;
            default:
                cout << "Не знаю такой операции ( ";
                break;
        }
    }
}
