#include <iostream>
#include <time.h>
#include "dlist.h"

using namespace std;

int main() {
    srand(time(NULL));

    dlist list(5);
    cout << "List: ";
    list.out();

    cout << "\n";

    list.push(5);
    cout << "Push item: ";
    list.out();

    cout << "\n";

    list.pop();
    cout << "Pop item: ";
    list.out();

    cout << "\n";

    list.shift();
    cout << "Shift item: ";
    list.out();
    
    cout << "\n";

    list.unshift(6);
    list.push(6);
    cout << "Unshift item: ";
    list.out();

    cout << "\n";

    list.del(6);
    cout << "Del item: ";
    list.out();

    cout << "\n";

    list.sortadd(12);
    cout << "Resul: ";
    list.out();
}
