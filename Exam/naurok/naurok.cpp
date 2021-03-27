#include <iostream>
#include <Windows.h>
#include <Wincrypt.h>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <ctime>

using namespace std;

#include "assets/userAdmin.cpp"
#include "assets/userTeacher.cpp"
//#include "assets/md.cpp"
#define keyForDB "itStep"

void SetPos( int x, int y ) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), c );
}

int main() {
    SetConsoleCP( 1251 );
    SetConsoleOutputCP( 1251 );

    /* ** Авторизация ** */

    bool auth = false;
    bool EXIT = false;
    string whatUser;
    fstream users;
    string login,
        password;
    DWORD res;

    while (!EXIT) {
        while (!auth) {
            system( "cls" );
            system( "title TEST" );
            system( "color 02" );
            SetPos( 38, 0 );

            /* ** Приветствие ** */

            cout << "Добро пожаловать в программу для тестирования!\n";
            cout << "Для входа в программу авторизуйтесь. \nЧтобы продoлжить нажмите любую клавишу (для выхода из программы нажмине ESC)\n";

            while (!_kbhit());
            if (_getch() == 27) {
                exit(0);
            }

            users.open( "db/users.txt" );

            cout << "Login: ";
            getline( cin, login );

            cout << "Password: ";

            HANDLE hStdin = GetStdHandle( STD_INPUT_HANDLE );
            DWORD mode = 0;
            GetConsoleMode( hStdin, &mode );
            SetConsoleMode( hStdin, mode & (~ENABLE_ECHO_INPUT) );

            getline( cin, password );

            SetConsoleMode( hStdin, mode );

            password = md( password, &res );

            if (users.is_open()) {
                string line;
                users >> line;
                if (line == keyForDB) {
                    string fLogin, fPassword, fUser, fNum;
                    while (!users.eof()) {
                        users >> fNum >> fLogin >> fPassword >> fUser ;
                        if (login == fLogin && password == fPassword) {
                            auth = true;
                            whatUser = fUser;
                            cout << "\nВы авторизованы!\n";
                            Sleep( 2000 );
                        }
                    }
                    if (!auth) {
                        cout << "\nПользователь не найден (\nпопробуйте ещё раз\n";
                        Sleep( 2000 );
                    }
                }
            }
            system( "cls" );
            users.close();
        }

        string titleConsole = "title ";
        transform( whatUser.begin(), whatUser.end(), whatUser.begin(), ::toupper );
        titleConsole.append( whatUser );
        system( titleConsole.c_str() );

        if (auth) {
            if (whatUser == "ADMIN") {
                auto_ptr<userAdmin> admin(new userAdmin);
                //clock_t t0 = clock();
                //Sleep(2000);
                //clock_t t1 = clock();
                //cout << "time: " << (double)(t1 - t0) / CLOCKS_PER_SEC << endl;
                //Sleep( 2000 );

                while (true) {
                    system( "cls" );
                    SetPos( 47, 0 );
                    system( "color 04" );

                    cout << "Панель администратора\n";
                    cout << "Добавить пользователя (нажмите A)\nУдалить пользователя (нажмите D)\nПросмотр всех пользователей (нажмите S)\nESC для выхода\n";

                    while (!_kbhit());

                    if (_getch() == 97) {
                        admin->add();
                    }
                    else if (_getch() == 100) {
                        cout << "\nУкажите какого пользователя хотите удалить (id)\n";
                        admin->writeListUsers();
                        int idUser;
                        cout << "\nВведите 0 / 1 для отмены...\n";
                        cin >> idUser;

                        if (idUser >= 0 && idUser <= 1) {
                            break;
                        }
                        else if (idUser > 1) {
                            admin->deleteUser( idUser );
                        }
                        else {
                            cout << "Пользователя не найдено (\n";
                            Sleep( 2000 );
                        }
                    }
                    else if (_getch() == 115) {
                        admin->writeListUsers();
                        cout << "\nЧтобы продолжить нажмите любую клавишу...\n";

                        while (!_kbhit());
                    }
                    else if (_getch() == 27) {
                        auth = false;
                        break;
                    }
                }
            }
            else if (whatUser == "TEACHER") {
                auto_ptr<userTeacher> teacher(new userTeacher);
                //userTeacher* teacher = new userTeacher;
                system( "cls" );
                SetPos( 47, 0 );
                system( "color 01" );

                cout << "Панель преподователя\n";
                cout << "Создать тест (нажмите С)\nДеактивировать тест (нажмите D)\n";

                while (!_kbhit());

                if (_getch() == 99) {
                    teacher->createTest();
                }
                else if (_getch() == 100) {

                }

                EXIT = true;
            }
            else if (whatUser == "STUDENT") {
                cout << "Hello student!)\n";
                EXIT = true;
            }
            else {
                cout << "У вас нет прав на использование программы, обратитесь к администратору \n";
            }
        }
    }
}