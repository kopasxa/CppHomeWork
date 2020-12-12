//Игра «кубики».Условие: имеется два игральных кубика
//со значениями от 1 до 6. Игра происходит с компьютером,
//кубики бросаются поочередно.Побеждает тот, у кого
//сумма выпавших очков по итогам пяти бросков больше.
//Предусмотрите возможность получения первого хода
//человеком или  компьютером.Кубики отображаются
//с помощью символов.В конце игры необходимо выводить среднюю сумму по броскам для обоих участников.

#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int symScoreBot = 0, symScorePlayer = 0;

void image( int roll ), RollTheDice( int firstPlayer ), imageCube( int numRoll );
int roll();

int main() {
    srand( time( NULL ) );
    setlocale( LC_ALL, "ru" );

    int firstPlayer;

    cout << "Кто первый ходит? (Я - 0, Компьютер - 1)" << endl;
    cin >> firstPlayer;

    for (int i = 1; i <= 5; i++) {
        RollTheDice( firstPlayer );
        Sleep( 1000 );
    }

    cout << endl << "Сумма очков компьютера: " << symScoreBot << endl << "Сумма твоих очков: " << symScorePlayer << endl;
    if (symScoreBot > symScorePlayer) {
        cout << "Победил компьютер. Поздравляем!" << endl;
    }
    else {
        cout << "Ты победил. Поздравляем!" << endl;
    }

}

int roll() {
    return rand() % 6 + 1;
}

void RollTheDice( int firstPlayer ) {
    char enter;
    int scoreBot = 0, scorePlayer = 0;
    if (firstPlayer == 0) {
        Sleep( 500 );
        cout << "Для броска кубика введите любой символ" << endl;
        cin >> enter;
        Sleep( 1000 );
        scoreBot = roll();
        image( scoreBot );
        symScorePlayer += scoreBot;

        cout << endl << "Бросок от компьютера: " << endl;
        Sleep( 1000 );
        scorePlayer = roll();
        image( scorePlayer );
        symScoreBot += scorePlayer;
    }
    else {
        cout << endl << "Бросок от компьютера: " << endl;
        Sleep( 1000 );
        scorePlayer = roll();
        image( scorePlayer );
        symScoreBot += scorePlayer;

        Sleep( 500 );
        cout << "Для броска кубика введите любой символ" << endl;
        cin >> enter;
        Sleep( 1000 );
        scoreBot = roll();
        image( scoreBot );
        symScorePlayer += scoreBot;
    }
}

void image( int roll ) {
    switch (roll) {
        case 1:
            imageCube( roll );
            break;
        case 2:
            imageCube( roll );
            break;
        case 3:
            imageCube( roll );
            break;
        case 4:
            imageCube( roll );
            break;
        case 5:
            imageCube( roll );
            break;
        case 6:
            imageCube( roll );
            break;
        default:
            cout << "lol" << roll;
            break;
    }
}

void imageCube( int numRoll ) {
    for (int i = 0; i < 20; i++) {
        cout << "—";
    }
    cout << endl;
    for (int i = 0; i < 4; i++) {
        cout << "—                  —" << endl;
    }
    cout << "—         " << numRoll << "        —" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "—                  —" << endl;
    }
    for (int i = 0; i < 20; i++) {
        cout << "—";
    }
    cout << endl;
}