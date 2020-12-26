//Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел
// Алгоритм Эвклида
#include <iostream>

using namespace std;

int findNum(int a, int b) {
    if (b == 0)
        return a;
    if (a > b)
        return findNum( b, a % b );
    else
        return findNum( a, b % a );
}

int main() {
    cout << findNum(169, 1690);
}
