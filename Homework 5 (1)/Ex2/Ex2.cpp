// Написать игру «Быки и коровы».Программа "загадывает" четырёхзначное число и играющий
// должен угадать его.После ввода пользователем числа программа сообщает, сколько цифр числа
// угадано( быки ) и сколько цифр угадано и стоит на нужном месте( коровы ).После отгадывания
// числа на экран необходимо вывести количество сделанных пользователем попыток.В
// программе необходимо использовать рекурсию.

#include <iostream>
#include <time.h>

using namespace std;

const int size = 4;
int prohod = 0;

int outputArr(int arr[]),
    carveNum(int number, int arr[]),
    coup(int arr[]),
    recurs(int arrPlayer[], int arrBot[]);

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int randNum   = rand() % 9000 + 999,
        myNum     = 0,
        temp      = 0,
        localTemp = 0,
        i         = 0,
        arrBot[::size],
        arrPlayer[::size],
        j         = 0,
        guessed   = 0,
        inPlace   = 0;

    cout << "Загадываю число..." << endl << "Загадал!" << endl;
    cout << randNum;
    cout << endl;
    
    // **** Разделываю число бота ****

    carveNum(randNum, arrBot);

    coup(arrBot);

    recurs(arrPlayer, arrBot);

}

int outputArr( int arr[] ) {
    int i = 0;

    for (i = 0; i < ::size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

int recurs(int arrPlayer[], int arrBot[]) {
    int guessed = 0,
        inPlace = 0,
        i       = 0,
        j       = 0,
        myNum   = 0;

    cout << "Введите число: " << endl;
    cin >> myNum;

    // **** Разделываю число игрока ****

    carveNum(myNum, arrPlayer);

    // *** Переворачиваю массив ***

    coup(arrPlayer);

    for (i = 0; i < ::size; i++) {
        for (j = 0; j < ::size; j++) {
            if (arrBot[i] == arrPlayer[j]) {
                guessed++;
            }
        }
        if (arrBot[i] == arrPlayer[i]) {
            inPlace++;
        }
    }

    ::prohod++;

    cout << endl << guessed << " " << inPlace << endl;

    if (guessed >= 4 && inPlace == 4) {
        cout << "Игра окончена!" << endl << "Вы прошли за " << prohod << " проходов" << endl;
    }
    else {
        return recurs(arrPlayer, arrBot);
    }
}

int coup( int arr[] ) {
    int i    = 0,
        temp = 0;

    for (i = 0; i < ::size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[::size - 1 - i];
        arr[::size - 1 - i] = temp;
    }

    return 0;
}

int carveNum( int number, int arr[] ) {
    int temp      = 0,
        i         = 0,
        localTemp = 0;

    temp = number;
    i = 0;

    while (temp >= 10) {
        localTemp = temp % 10;
        temp /= 10;
        arr[i] = localTemp;
        i++;
    }

    arr[::size - 1] = temp;

    return 0;
}
