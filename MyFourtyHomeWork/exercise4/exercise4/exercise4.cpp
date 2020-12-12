#include <iostream>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    const int size = 10;
    int i, j, arr[size],
              temp = 0;

    for (j = 0; j < size; j++) {
        arr[j] = rand() % 50;
        cout << arr[j] << " ";
    }

    cout << endl;

    for (i = 1; i < size; i++) {
        for (j = 0; j < size - i; j++) {
            if (arr[j + 1] < arr[j]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (j = 0; j < size; j++) {
        cout << arr[j] << " ";
    }
}
