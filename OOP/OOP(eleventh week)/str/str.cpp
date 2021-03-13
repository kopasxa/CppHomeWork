#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;

    cout << "enter string: ";
    getline(cin, str);

    cout << "1. delete symbol\n2. replace symbol\n3. insert symbol\n";
    int num;
    cin >> num;

    if (num == 1) {
        char sym;
        cout << "enter symb: ";
        cin >> sym;
        int h = str.find( sym );
        if (h != -1) {
            str.erase(h, 1);
        }
        else {
            cout << "Symbol not found (\n";
        }
    }
    else if (num == 2) {
        char sym;
        cout << "enter symb: ";
        cin >> sym;
        cin.ignore();
        int k = str.find( sym );
        if (k != -1) {
            cout << "enter replace symbols: ";
            string s;
            getline( cin, s );
            str.replace( k, k + 1, s );
        }
    }
    else if (num == 3) {
        cout << "which character to insert? ";
        string sym;
        cin.ignore();
        getline(cin, sym);
        cout << "in what position? ";
        int pos;
        cin >> pos;
        str.insert(pos - 1, sym);
    }

    cout << "Result: " << str;
}

