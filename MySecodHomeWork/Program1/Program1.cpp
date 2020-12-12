#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int colvo, horOrVer;
    char symvol;
    cout << "Введите количество симоволов которые нужно вывести: \n";
    cin >> colvo;
    cout << "Введите симол которые хотите вывести: ";
    cin >> symvol;
    cout << "Введите положение линии: \n 1. Горизонтально  \n 2. Вертикально\n";
    cin >> horOrVer;

    for (int i = 1; i <= colvo; i++) {
        if (horOrVer == 1) {
            cout << symvol;
        }
        else if (horOrVer == 2) {
            cout << symvol << "\n";
        }
    }
}

