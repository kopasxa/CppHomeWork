#include <iostream>

using namespace std;

int main() {
    int sum     = 0,
        i       = 100,
        max     = 999,
        numOfI1 = 0,
        numOfI2 = 0,
        numOfI3 = 0,
        temp;


    while (i <= max) {
        temp = i;

        numOfI1 = temp % 10;
        numOfI2 = (temp / 10) % 10;
        numOfI3 = (temp / 10) / 10;

        if (numOfI1 == numOfI2 || numOfI2 == numOfI3 || numOfI1 == numOfI3 && numOfI1 != numOfI1 != numOfI3) {
            sum += 1;
        }

        cout << "( " << numOfI3 << ", " << numOfI2 <<  ", " << numOfI1 << " ); ";

        i++;
    }

    cout << endl << sum;
}