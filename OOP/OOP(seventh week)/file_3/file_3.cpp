#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string line;
    fstream fIn( "temp\\qe.txt" );
    string findStr;
    int sizeArr = 0;

    cin >> findStr;

    if (fIn.is_open()) {
        while (fIn >> line) {
            if (findStr == line) {
                sizeArr++;
            }
        }
        cout << "there are " << sizeArr << " words";
    }

    fIn.close();
}
