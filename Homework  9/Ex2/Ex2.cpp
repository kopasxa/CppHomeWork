// Нахождение меньшего из двух чисел;
// Нахождение большего из двух чисел;
// Возведение числа в квадрат;
// Возведение числа в степень;
// Проверка числа на четность;
// Проверка числа на нечетность;

#include <iostream>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)
#define sqa(a) a*a
#define numSqa(a, num) (numInStep(a, num))
#define even(a) (a % 2 == 0 ? "even" : "odd")

using namespace std;

int numInStep( int a, int num ) {
	if (num) {
		return a * numInStep( a, num - 1 );
	}
	else {
		return 1;
	}
}

int main() {
	cout << "Min: " << min( 10, 20 ) << endl;
	cout << "Max: " << max( 10, 20 ) << endl;
	cout << "Num in sqared: " << sqa(5) << endl;
	cout << "Num in step: " << numSqa(2, 4) << endl;
	cout << "Even?: " << even(2) << endl;
	cout << "Even?: " << even(3) << endl;
}
