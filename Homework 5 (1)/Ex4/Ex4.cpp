// Написать рекурсивную функцию нахождения степени числа.

#include <iostream>

using namespace std;

int step(int num, int step);

int main() {
   cout << step(5, 2);
}

int step(int num, int steps) {
	if (steps <= 0) 
		return 1;

	return num * step( num, steps - 1 );
}
