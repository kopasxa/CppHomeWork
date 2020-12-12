#include <iostream>

using namespace std;

struct time {
    unsigned seconds: 6;
    unsigned minutes: 6;
    unsigned hours: 6;
    unsigned milliseconds: 6;
} bits;

void init() {
    cout << "Часы: ";
    int hours;
    cin >> hours;
    bits.hours = hours;

    cout << "Минуты: ";
    int minutes;
    cin >> minutes;
    bits.minutes = minutes;

    cout << "Секунды: ";
    int seconds;
    cin >> seconds;
    bits.seconds = seconds;

    cout << "Миллисекунды: ";
    int milliseconds;
    cin >> milliseconds;
    bits.milliseconds = milliseconds;
}

void print() {
    cout << "Время: " << bits.hours << ":" << bits.minutes << ":" << bits.seconds << ":" << bits.milliseconds << endl;
}
int main() {
    setlocale(LC_ALL, "ru");

    init();

    print();
}
