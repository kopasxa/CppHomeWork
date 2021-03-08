#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string line;
    fstream fIn( "temp\\qe.txt" );
    if (fIn.is_open()) {
        int sizeLine = 0;

        while (getline( fIn, line )) {
            if (sizeLine < line.length()) {
                sizeLine = line.length();
            }
        }
        cout << "max size line: " << sizeLine;
    }

    fIn.close();
}
