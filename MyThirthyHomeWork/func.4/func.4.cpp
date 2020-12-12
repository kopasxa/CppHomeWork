// Написать функцию, выводящую на экран прямоугольник с высотой N и шириной K.

#include <iostream>

using namespace std;

void print(int height, int width) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    print(10, 10);
}

