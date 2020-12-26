// Дан массив целых чисел.Воспользовавшись указателями, поменяйте местами элементы массива с четными
// и нечетными индексами( т.е.те элементы массива, которые стоят на четных местах, поменяйте с элементами,
// которые стоят на нечетных местах ).

#include <iostream>
#include "time.h"

using namespace std;

int main() {
	const int size = 10;
	int arr[size],
		i,
		temp,
		size2 = size,
		*ptrArr = arr;

	for (i = 0; i < size; i++) {
		ptrArr[i] = i + 1;
		cout << ptrArr[i] << " ";
	}

	cout << endl;

	if (size % 2 != 0) {
		size2--;
	}

	for (i = 0; i < size2; i++) {
		if (i % 2 == 0) {
			temp = ptrArr[i];
			ptrArr[i] = ptrArr[i + 1];
			ptrArr[i + 1] = temp;
		}
	}

	for (i = 0; i < size; i++) {
		cout << ptrArr[i] << " ";
	}
}
