#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int factorial, i = 1, result = 1;
    cout << "Введите факториал: ";
    cin >> factorial;

    if (factorial >= 0) {
        if (factorial == 0)
            result = 1;
        else {
            while (i <= factorial) {
                result = result * i;
                i++;
            }
        }
    }
    cout << "Факториал: " << result;
}
