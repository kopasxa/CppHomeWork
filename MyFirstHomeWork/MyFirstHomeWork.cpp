#include <iostream>
using namespace std;

int main() {
    int exercise, prov;
    bool validate = true;
    setlocale(LC_ALL, "Russian");
    
    while (validate)
    {
        cout << "Введите номер задания: ";
        cin >> exercise;
        cout << "\n";

        if (exercise == 1) {
            cout << "\t\t\tЯ слышал, время лечит...\n\t\tЯ слышал «время лечит» много раз.\n\t\tИ что \"на ней свет клином не сошёлся\".\n\t\t\"Ты сам себе придумал тот мираж\".\n\t\tИ \"кто любил, тот хоть разок обжёгся\"…\n\t\tИ, как один, твердят друзья мои,\n\t\tСтремясь хоть как - то боль мою облегчить,\n\t\tЧто, может, вовсе не было любви.\n\t\tМол \"кончен бал и догорели свечи\".";
            
            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 2) {
            cout << "\tКаждый - Красный\n\t\tОхотник - Оранжевый\n\t\t\tЖелает - Жёлтый\n\t\t\t\tЗнать - Зелёный\n\t\t\t\t\tГде - Голубой\n\t\t\t\t\t\tСидит - Синий\n\t\t\t\t\t\t\tФазан - Фиолетовый\n";
            
            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 3) {
            cout << "\t  Сдам комнаты у моря\n\n";
            cout << "Город: Южное\n\n";
            cout << "+====================================+\n";
            cout << "| Тип предложения: / От собственника |\n| Общая площадь:  /      36 м2\t     |\n| Срок аренды:   / Посуточная оплата |\n";
            cout << "+====================================+\n\n";
            cout << "Двухэтажный домик с балконом. Две комнаты с двумя спальными местами в каждой. \nДо моря 15 мин пешком. Имеется беседка с барбекю. До центра Одессы 30 минут на маршрутке.\n";
            
            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 4) {
            float r1, r2, r3, r0;
            cout << "Введите сопротивление r1: ";
            cin >> r1;
            cout << "Введите сопротивление r2: ";
            cin >> r2;
            cout << "Введите сопротивление r3: ";
            cin >> r3;
            r0 = (1 / r1) + (1 / r2) + (1 / r3);
            cout << 1 / r0;

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 5) {
            const float numPi = 3.14;
            float square, length, radius;
            cout << "Введите длину окружности: ";
            cin >> length;
            radius = length / (2 * numPi);
            cout << "Радиус: " << radius << "\n";
            square = numPi * (radius * radius);
            cout << "Площа круга = " << square << "\n";

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 6) {
            int v, t, a;
            float s;
            cout << "Введите скорость: ";
            cin >> v;
            cout << "\n";
            cout << "Введите время: ";
            cin >> t;
            cout << "\n";
            cout << "Введите ускорение: ";
            cin >> a;
            cout << "\n";
            s = v * t + (a * (t * t)) / 2;
            cout << "Пройденное расстояние: " << s;

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 7) {
            float s, v, t;
            cout << "Введите расстояние до конечной точки (в км): ";
            cin >> v;
            cout << "\n";
            cout << "Введите время за которое вам нужно доехать (ч): ";
            cin >> t;
            cout << "\n";
            s = v * t;
            cout << "Ваша скорость будет: " << s << " км/ч";

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 8) {
            double h, m, s, h2, m2, s2, res_h, res_m, res_s, result, cost;
            cout << "Введите время начала разговора (часы, минуты, секунды): \n";
            cin >> h >> m >> s;
            cout << "Введите время конца разговора (часы, минуты, секунды): \n";
            cin >> h2 >> m2 >> s2;
            res_h = (h2 - h) * 60;
            res_m = m2 - m;
            res_s = (s2 - s) / 60;
            cost = 30;
            result = cost * (res_h + res_m + res_s);
            cout << "Вам надо будет заплатить: " << result / 100 << " грн";

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 9) {
            float on100, distance, varietyBenz1, varietyBenz2, varietyBenz3, res, globalres;
            cout << "Введите расход топлива на 100 км: \n";
            cin >> on100;
            cout << "Введите расстояние которое вам нужно проехать: \n";
            cin >> distance;
            cout << "Введите стоимость трёх видов топлива: \n";
            cin >> varietyBenz1 >> varietyBenz2 >> varietyBenz3;
            res = distance / 100;
            globalres = res * on100;
            cout << "+================================+\n";
            cout << "# 1 вид топлива ( " << varietyBenz1 << " ) : " << varietyBenz1 * globalres << " грн #\n";
            cout << "# 2 вид топлива ( " << varietyBenz2 << " ) : " << varietyBenz2 * globalres << " грн #\n";
            cout << "# 3 вид топлива ( " << varietyBenz3 << " ) : " << varietyBenz3 * globalres << " грн #\n";
            cout << "+=================================+\n\n";

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 10) {
            int i = 0;
            while (i <= 80)
            {
                cout << "=";
                i++;
            }
            i = 0;
            cout << "\n";
            cout << "|\tX\t|\tY\t|\tX AND Y |\tX OR Y  |\tNOT X   |\n";

            while (i <= 80)
            {
                cout << "=";
                i++;
            }
            i = 0;
            cout << "\n";
            cout << "|\t0\t|\t0\t|\t0\t|\t0\t|\t1\t|\n";
            cout << "|\t0\t|\t1\t|\t0\t|\t1\t|\t1\t|\n";
            cout << "|\t1\t|\t1\t|\t1\t|\t1\t|\t0\t|\n";

            while (i <= 80)
            {
                cout << "=";
                i++;
            }

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 11) {
            const float toSm = 2.54;
            float inch, result;
            cout << "Enter the diagonal of your screen:\n";
            cin >> inch;
            cout << int(inch * toSm) << "sm";

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 12) {
            const int quantity = 3;
            int mAh;
            cout << "Smartphone Battery Capacity (mAh):\n";
            cin >> mAh;
            cout << "Minimum capacity: " << mAh * quantity;

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 13) {
            float result, FeedForDay;
            cout << "Feed consumption for 1 day (g): \n";
            cin >> FeedForDay;
            result = FeedForDay * 30 / 1000;
            cout << "Feed for 30 days: " << result << " kg";

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 14) {
            int number, result;
            cout << "Enter the number:\n";
            cin >> number;
            result = number % 2;
            cout << "The number is ";
            if (result == 0)
            {
                cout << "even\n";
            }
            else
            {
                cout << "not even\n";
            }

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 15) {
            int colNum, num1, num2;
            cout << "Введите число: ";
            cin >> colNum;
            cout << "\n";
            if (colNum > 9)
            {
                cout << "Две цифры\n";
                num1 = colNum / 10;
                num2 = colNum % 10;
                cout << "Сумма: " << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
            }
            else
            {
                cout << "Одна цифра\n";
                cout << "Сумма: " << colNum << "\n";
            }

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 16) {
            float res, d = 2.54, num2;
            int num;
            cout << "Введите число которое хотите перевести: \n";
            cin >> num2;
            cout << "1. Перевести дюймы в сантиметры\n";
            cout << "2. Перевести сантиметры в дюймы\n";
            cin >> num;

            switch (num)
            {
            case 1: 
                res = num2 * d;
                break;
            case 2: 
                res = num2 / d;
                break;
            default:
                break;
            }

            cout << res;
            
            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else if (exercise == 17) {
            float num1, num2, result;
            char tools;

            cout << "Введите первое число: \n";
            cin >> num1;
            cout << "Введите операцию (+, -, /, *, < (min), > (max)): \n";
            cin >> tools;
            cout << "Введите второе число: \n";
            cin >> num2;
            
            switch (tools)
            {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    cout << "На ноль делить нельзя))) \n";
                    result = 0;
                }
                else {
                    result = num1 / num2;
                }
                break;
            case '>':
                if (num1 > num2) {
                    result = num1;
                }
                else {
                    result = num2;
                }
                break;
            case '<':
                if (num1 < num2) {
                    result = num1;
                }
                else {
                    result = num2;
                }
                break;
            default:
                cout << "Неизвестная мне операция \n";
                result = 0;
                break;
            }

            cout << "\nРезультат: " << result;

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
        else {
            cout << "Такого задания не существует, попробуйте еще раз.";

            cout << "\nПродолжить? 0 (no) / 1 (yes) ";
            cin >> prov;
            if (prov == 0) {
                validate = false;
            }
        }
    }
        
}
