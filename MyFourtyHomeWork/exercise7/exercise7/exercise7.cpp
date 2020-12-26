#include <iostream>
#include <time.h>

using namespace std;

const int size = 18;

int sortArrayOne( int arr[], int halfPath ),
    sortArrayTwo( int arr[], int halfPath );

int main() {
    setlocale( LC_ALL, "russian" );
    int arr[::size];
    float averageNum = 0.0;
    float resAV = 0.0;
    int halfPath = 0;

    srand( time( NULL ) );
    halfPath = (::size / 3) * 2;

    for (int i = 0; i < ::size; i++) {
        arr[i] = rand() % 100 + 1;
    }

    for (int i = 0; i < ::size; i++) {
        cout << " " << arr[i];
    }

    for (int i = 0; i < 2 / 3; i++) {
        averageNum += arr[i];
    }

    cout << endl << endl;

    for (int i = 0; i < halfPath; i++) {
        resAV += arr[i];
        if (i == halfPath - 1) {
            resAV = resAV / i;
        }
    }

    if (resAV > averageNum) {
        sortArrayOne( arr, halfPath );
    }
    if (resAV < averageNum) {
        sortArrayTwo( arr, halfPath );
    }

    for (int i = 0; i < ::size; i++) {
        cout << " " << arr[i];
    }

    cout << "\n\n";
    return 0;
}

int sortArrayOne( int arr[], int halfPath ) {
    int temp = 0;

    for (int i = 0; i < halfPath; i++) {
        for (int j = i + 1; j < halfPath; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return 0;
}

int sortArrayTwo( int arr[], int halfPath ) {
    int temp = 0;

    for (int i = halfPath; i < ::size - 1; i++) {
        for (int j = i + 1; j < ::size; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return 0;
}

