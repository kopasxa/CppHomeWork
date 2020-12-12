#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    int box, sum = 0;
    const int car = 25;
    
    cout << "Введите количество ящиков на складе: ";
    cin >> box;

    if (box >= 0) {
        for (int i = 0; i < box; i++) {
            if (box >= car) {
                box -= car;
                sum += 1;
            }
            else {
                cout << "Осталось " << box << " ящиков\n";
                break;
            }
            
        }
    }
    else {
        cout << "Неправильное кол-во ящиков на складе (\n";
    }
    cout << "Всего нужно " << sum << " машин";
}