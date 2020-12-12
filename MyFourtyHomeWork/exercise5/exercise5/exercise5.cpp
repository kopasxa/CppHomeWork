#include <iostream>
#include <time.h>

using namespace std;

int main() {
    srand(time(NULL));

    const int size = 10;
    int i, j, arr[size], el;

    for (i = 0; i < size; i++) {
        arr[i] = rand() % 20;
        cout << arr[i] << " ";
    }

    cout << endl;

    for (i = 0; i < size; i++) {
        el = arr[i];

        for (j = i - 1; j >= 0 && arr[j] > el; j--) {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = el;
    }

    cout << endl;

    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
