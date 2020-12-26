// Написать рекурсивную функцию нахождения степени
// числа.

#include <iostream>

using namespace std;

int step( int num, int s );

int main() {
	cout << step( 2, 3);
}

int step( int num, int s ) {
	if (s == 0) {
		return 1;
	}
	if (s == 1) {
		return num;
	}
	if (s > 0) {
		return num * step( num, s - 1 );
	}
}