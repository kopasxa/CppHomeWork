#include <iostream>

using namespace std;

int main() {
    int size1;
    cout << "size array: " << endl;
    cin >> size1;
    int* arr1 = new int[size1];

    cout << "values of the array: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    while (true) {
        int n;
        cout << "\nmenu:" << endl;
        cout << "1 - remove Chet" << endl;
        cout << "2 - remove Ne chet" << endl;
        cout << "3 - show arr" << endl; 
        cin >> n;
        switch (n) {
            case 1:
                for (int i = 0; i < size1; i++) {
                    if (arr1[i] % 2 == 0) {
                        for (int j = i; j < size1 - 1; j++) {
                            arr1[j] = arr1[j + 1];
                        }
                        size1--;
                        i--;
                    }
                }
                break;
            case 2:
                for (int i = 0; i < size1; i++) {
                    if (!(arr1[i] % 2 == 0)) {
                        for (int j = i; j < size1 - 1; j++) {
                            arr1[j] = arr1[j + 1];
                        }
                        size1--;
                        i--;
                    }
                }
                break;
            case 3:
                for (int i = 0; i < size1; i++) {
                    cout << arr1[i] << " ";
                }
                break;
        }
    }

    delete[] arr1;
}