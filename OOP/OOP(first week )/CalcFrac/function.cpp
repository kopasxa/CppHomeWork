#include "function.h"

bool additionSubtraction( fraction drob1, fraction drob2, char oper ) {
    int max, min;

    if (drob1.getZnam() < drob2.getZnam()) {
        max = drob2.getZnam();
        min = drob1.getZnam();
    }
    else {
        max = drob1.getZnam();
        min = drob2.getZnam();
    }

    int nok = max;

    while (nok % min != 0) {
        nok += max;
    }

    int newZnam = nok;
    int newChis;

    if (oper == '+') {
        newChis = drob1.getChis() * (nok / drob2.getZnam()) + drob2.getChis() * (nok / drob1.getZnam());
    }
    else if (oper == '-') {
        newChis = drob2.getChis() * (nok / drob1.getZnam()) - drob1.getChis() * (nok / drob2.getZnam());
    }
    else {
        cout << "Error 400: the operation was not successful\n";
        return false;
    }

    simple( newChis, newZnam, max );

    fraction res( newChis, newZnam );

    return res.getFrac();
}

bool simple( int& newChis, int& newZnam, int max ) {
    for (int i = max; i > 0; i--) {
        if (newChis % i == 0 && newZnam % i == 0) {
            newZnam /= i;
            newChis /= i;
        }
    }
    return true;
}

bool simple( int& newChis, int& newZnam ) {
    int max;

    if (newChis > newZnam) {
        max = newChis;
    }
    else {
        max = newZnam;
    }

    for (int i = max; i > 0; i--) {
        if (newChis % i == 0 && newZnam % i == 0) {
            newZnam /= i;
            newChis /= i;
        }
    }
    return true;
}


bool multiplyDivide( fraction drob1, fraction drob2, char oper ) {
    int newChis;
    int newZnam;

    if (oper == '/') {
        newChis = drob1.getChis() * drob2.getZnam();
        newZnam = drob1.getZnam() * drob2.getChis();
    }
    else if (oper == '*') {
        newChis = drob1.getChis() * drob2.getChis();
        newZnam = drob1.getZnam() * drob2.getZnam();
    }
    else {
        cout << "Error 400: the operation was not successful\n";
        return false;
    }

    simple(newChis, newZnam);

    fraction res(newChis, newZnam);

    return res.getFrac();
}
