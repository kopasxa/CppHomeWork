#include <iostream>
#include <Windows.h>
#include <Wincrypt.h>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

#include "admin.h"
#include "md.cpp"
#define keyForDB "itStep"

int main() {
    SetConsoleCP( 1251 );
    SetConsoleOutputCP( 1251 );
    system("title TEST");
    system( "color 02" );
    COORD c;
    c.X = 38;
    c.Y = 0;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), c );

    /* ** Приветствие ** */

    cout << "Добро пожаловать в программу для тестирования!\n";
    cout << "Для продолжения пожалуйста авторизуйтесь\n";

    /* ** Авторизация ** */

    bool auth = false;
    string whatUser;
    fstream users( "db/users.txt" );
    string login,
           password;
    DWORD res;

    while ( !auth ) {
        cout << "Login: ";
        getline( cin, login );

        cout << "Password: ";
        getline( cin, password );
        password = md( password, &res );

        if (users.is_open()) {
            string line;
            users >> line;
            if (line == keyForDB) {
                string fLogin, fPassword, fUser;
                while (users >> fLogin >> fPassword >> fUser) {
                    if (login == fLogin && password == fPassword) {
                        auth = true;
                        whatUser = fUser;
                        cout << "\nВы авторизованы!\n";
                        Sleep( 2000 );
                    }
                    else {
                        cout << "\nПользователь не найден (\nпопробуйте ещё раз\n";
                        Sleep( 2000 );
                    }
                }
            }
        }
        system("cls");
    }
    users.close();

    string titleConsole = "title ";
    titleConsole.append( whatUser );
    system( titleConsole.c_str() );

    if ( auth ) {
        if ( whatUser == "admin" ) {
            admin userAdmin;
            userAdmin.addUser();
        }
    }


    //HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    //SetConsoleTextAttribute( hConsole, (WORD)((15 << 4) | 0) );

    /*while (!_kbhit());
    if (_getch() == VK_SPACE) cout << "Привет";*/
}