#include <iostream>
using namespace std;

int main() {
    setlocale( LC_ALL, "ru" );
    int r1, r2, imax, imin, i;
    const int n = 12;
    double a[n];

    cout << "Ваш доход каждый месяц:\n";
    for (i = 0; i < n; i++) {
        cout << "Месяц №" << i + 1 << ": ";
        cin >> a[i];
    }

    cout << "Введите диапазон:\n";
    cin >> r1 >> r2;

    imax = imin = r1 - 1;
    for (i = r1; i < r2; i++) {
        if (a[i] > a[imax]) {
            imax = i;
        }

        if (a[i] < a[imin]) {
            imin = i;
        }
    }

    cout << "Максимальный доход: за " << imax + 1 << " месяц\n";
    cout << "Минимальный доход: за " << imin + 1 << " месяц\n";
}