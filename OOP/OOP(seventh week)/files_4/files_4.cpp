#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string line;
    fstream fIn( "temp\\qe.txt" );
    string findStr, newStr;

    cout << "What find? \n";
    cin >> findStr;


    if (fIn.is_open()) {
        while (fIn >> line) {
            if (findStr == line) {

                string replace;
                cout << "Replace on ";
                cin >> replace;

                ofstream out( "temp\\qe.txt" );
                out << newStr << replace;
                newStr += replace;
            }
            else {
                newStr += " " + line;
            }
        }
    }

    fIn.close();
}
