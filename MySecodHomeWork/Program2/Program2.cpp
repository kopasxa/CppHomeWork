#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int sum = 0, num1, num2, i = 1;
    cout << "Введите числа в определённом диапазоне: \n";
    cin >> num1 >> num2;
    i = num1;
    while (i <= num2) {
        if (i % 2 != 0) {
            sum += i;
        }
        i++;
    }
    cout << "Сумма нечетных чисел: " << sum;
}
