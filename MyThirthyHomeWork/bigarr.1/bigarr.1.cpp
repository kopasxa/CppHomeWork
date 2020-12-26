#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
    srand(time(NULL));

    const int sizeCol = 4,
              sizeRow = 3;
    int arr[sizeRow][sizeCol],
        col,
        row,
        allZ = 0;

    for (row = 0; row < sizeRow; row++) {
        for (col = 0; col < sizeCol; col++) {
            arr[row][col] = rand() % 9;
            if (arr[row][col] == 0) {
                allZ += 1;
            }
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    cout << "Quantity 0: " << allZ;
}

