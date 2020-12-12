#include <iostream>
#include <string>

using namespace std;

string searchBrace(string str);
string count(string str);
string calc(string num1, string operation, string num2);

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Введите выражение: ";
    string str;

    getline( cin, str );
 
    searchBrace(str);
}

string searchBrace( string str ) {
    bool open = false,
        close = false;

    int posOpen  = -1,
        posClose = -1;

    int i, j,
        sizeStr = str.length();

    for (i = 0; i < sizeStr; i++) {
        if (str[i] == '(') {
            open = true;
            posOpen = i;
        } 
        if (open && str[i] == ')') {
            close = true;
            posClose = i;

            string result = count(str.substr(posOpen + 1, posClose - posOpen - 1));
            str.erase(posOpen, posClose + 1);
            str.insert(posOpen, result);

        }
    }

  
    /*for (i = 0; i < sizeStr; i++) {
        if (str[i] == '(') {
            searchBrace(str);
        }
    }*/

    return count(str);
}

string count( string str ) {
    string temp = "";
    string *lox = new string[str.length()];

    int i;
    
    /*for (i = 0; i < str.length(); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            lox[i] += temp;
            lox[i] += str[i];
            temp = "";
        }
        else {
            string num;
            int k = i;
            while (k < str.length() && str[k+1] == '+' || str[k+1] == '-' || str[k+1] == '*' || str[k+1] == '/') {
                num += str[k];
                k++;
            }
            lox[i] += num;
        } 
    }*/
    /*lox[i] += temp;*/

    for (i = 0; i < str.length(); i++) {
        if (str[i] == '*' || str[i] == '/') {
            if (i == 0 || i == str.length() - 1) {
                return "Ошибка в расположении знака";
            }
            string result = calc(str[i-1], str[i], str[i+1]);
            str.erase( i - 1, i + 1 );
            str.insert(i - 1, result);
            i--;
        }
    }
}

string calc( char num1, char operation, char num2 ) {

    double number1 = atof( num1 );
    double number2 = atof( num2 );

    if (operation == '/') {
        if (number2 != 0) {
            return to_string(number1 / number2);
        }
    }
    if (operation == '*') {
        return to_string(number1 * number2);
    }
    if (operation == '+') {
        return to_string(number1 + number2);
    }
    if (operation == '-') {
        return to_string(number1 - number2);
    }
}
