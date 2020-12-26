

#include <iostream>

using namespace std;

void sys( int digit, int syst ) {
    int i, j, arr[50];
    for (i = 0; digit > 0; i++) {
        arr[i] = digit % syst;
        digit /= syst;
    }
    for (j = i - 1; j >= 0; j--) {
        if (arr[j] < 10) {
            cout << arr[j];
        }
        else {
            cout << char( arr[j] - 10 + 'A' );
        }
    }
}

int main() {
    sys(35, 18);
}
