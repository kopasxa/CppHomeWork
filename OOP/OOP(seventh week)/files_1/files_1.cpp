#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string line;

    fstream fIn( "temp\\qe.txt" );
    if (fIn.is_open()) {
        /*while (fIn >> line) {
            cout << line << "\n";
        }*/

        int sizeArr = 0;
        while (!fIn.eof()) {
            getline( fIn, line );
            sizeArr++;
        }
        fIn.close();

        string *arrFileText = new string[sizeArr];
        int i = 0;
        fIn.open( "temp\\qe.txt" );

        while (getline( fIn, line )) {
            arrFileText[i] = line;
            i++;
        }

        fstream res( "temp\\result.txt" );

        FILE* F;

        if (!res.is_open()) {
            fopen_s( &F, "temp\\result.txt", "r" );

            if (!F) {
                fopen_s( &F, "temp\\result.txt", "w" );
            };
            fclose( F );
        }

        if (res.is_open()) {
            arrFileText[sizeArr - 1] = '\0';

            for (int i = 0; i < sizeArr - 1; i++) {
                res << arrFileText[i] << "\n";
            }
        }
        delete [] arrFileText;
    }
    
    fIn.close();
}