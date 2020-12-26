#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    int l, p, sum = 0;

    cout << "Введите длину ткани: ";
    cin >> l;
    cout << "Введите длину подушки: ";
    cin >> p;

    for (int i = 1; i < l; i++) {
        if (l < p) {
            cout << "Ткань закончилась\n";
            break;
        }
        else {
            l -= p;
            sum += 1;
            cout << "Сделал подушку\n";
        }
    }

    cout << "Можно сделать " << sum << " подушек";
}