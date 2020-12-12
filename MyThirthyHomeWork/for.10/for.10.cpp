#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int h, a, w, i, j, k, l;

    cout << "Введите высоту шахматной доски.\nh = ";
    cin >> h;
    cout << "Введите ширину шахматной доски.\nw = ";
    cin >> w;
    cout << "Введите величину ячейки шахматной доски.\na = ";
    cin >> a;

    for (i = 0; i < h; i++) {
        for (j = 0; j < a; j++) {
            for (k = 0; k < w; k++) {
                for (l = 0; l < a; l++) {
                    ((i + k) % 2) ? (cout << '_') : (cout << '*');
                }
            }
            cout << endl;
        }
    }
}

