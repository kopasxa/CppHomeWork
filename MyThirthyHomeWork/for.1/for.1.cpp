#include <iostream>

using namespace std;

void variant1(),
     variant2(),
     variant3(),
     variant4(),
     variant5(),
     variant6(),
     variant7(),
     variant8(),
     variant9(),
     variant10();

int main() {
    int numEx;

    setlocale(0, "");
   
    while (true) {
        cout << "\nВведите вариант узора (0 - 10): " << endl;
        cin >> numEx;
        switch (numEx) {
            case 1: 
                variant1();
                break;
            case 2: 
                variant2();
                break;
            case 3:  
                variant3();
                break;
            case 4: 
                variant4();
                break;
            case 5:
                variant5();
                break;
            case 6:
                variant6();
                break;
            case 7:
                variant7();
                break;
            case 8:
                variant8();
                break;
            case 9:
                variant9();
                break;
            case 10:
                variant10();
                break;
        }
    }
}

void variant1() {
    int i = 0, j = 0, k = 0, col = 10;

    while (0 < col) {
        i++;
        col -= 1;
        j = 0;
        while (j <= col) {
            j++;
            cout << " * ";
        }
        cout << endl;
        k = 0;
        while (k < i) {
            cout << "   ";
            k++;
        }
    }
}

void variant2() {
    int i = 0, j, col = 10;
    while (i < col) {
        i++;
        j = 0;
        while (j < i) {
            j++;
            cout << " * ";
        }
        cout << endl;
    }
}

void variant3() {
    int i = 0, j, k, b, col = 10;

    while (0 <= col ) {
        i++;
        col -= 2;
        j = 0;
        while (j <= col) {
            j++;
            cout << " * ";
        }
        cout << endl;
        k = 0;
        while (k < i) {
            cout << "   ";
            k++;
        }
    }
}

void variant4() {
    int n = 0, i = 0, col = 10;
    
    n = 1;
    while (n <= col) {
        i = 1;
        while (i <= col) {
            if ((!(i >= n) && !(i + n <= col))) {
                cout << " * ";
            }
            else {
                cout << "   ";
            }

            i++;
        }
        cout << endl;
        n++;
    }
}

void variant5() {
    int n = 0, i = 0, col = 10;

    n = 1;
    while (n <= col) {
        i = 1;
        while (i <= col) {
            if ((!(i >= n) && !(i + n <= col)) || ((i >= n) && (i + n <= col))) {
                cout << " * ";
            }
            else {
                cout << "   ";
            }

            i++;
        }
        cout << endl;
        n++;
    }
}

void variant7() {
    int n = 0, i = 0, col = 10;

    n = 1;
    while (n <= col) {
        i = 1;
        while (i <= col) {
            if (i <= n && (i + n ) <= col) {
                cout << " * ";
            }
            else {
                cout << "   ";
            }

            i++;
        }
        cout << endl;
        n++;
    }
}

void variant6() {
    int n = 0, i = 0, col = 9;

    n = 1;
    while (n <= col) {
        i = 1;
        while (i <= col) {
            if ((i <= n && (i + n - 1) <= col) || (i >= n && !(i + n <= col))) {
                cout << " * ";
            }
            else {
                cout << "   ";
            }

            i++;
        }
        cout << endl;
        n++;
    }
}

void variant8() {
    int n = 0, i = 0, col = 10;

    n = 1;
    while (n <= col) {
        i = 1;
        while (i <= col) {
            if ((i >= n && !(i + n - 1 <= col))) {
                cout << " * ";
            }
            else {
                cout << "   ";
            }

            i++;
        }
        cout << endl;
        n++;
    }
}

void variant10() {
    int i = 0, j = 0, k = 0, col = 10;

    while (0 < col) {
        i++;
        col -= 1;
        k = 0;
        while (k < i - 1) {
            k++;
            cout << " * ";
        }
        cout << endl;
        j = 0;
        while (j <= col) {
            cout << "   ";
            j++;
        }
    }
}

void variant9() {
    int i = 0, j, k, col = 10;
    while (i < col) {
        i++;
        
        k = i;
        while (k <= col) {
            k++;
            cout << " * ";
        }
        cout << endl;
    }
}

