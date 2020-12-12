// Даны два массива : А[n] и B[m].Необходимо создать
// третий массив, в котором нужно собрать :
// ■ Элементы обоих массивов;
// ■ Общие элементы двух массивов;
// ■ Элементы массива A, которые не включаются в B;
// ■ Элементы массива B, которые не включаются в A;
// ■ Элементы массивов A и B, которые не являются общими для них( то есть объединение результатов двух
// 															   предыдущих вариантов ).
// 	Обязательно используйте синтаксис указателей для
// 	решения этой задачи.

#include <iostream>
#include "time.h"

using namespace std;

const int size1 = 10,
		  size2 = 15;

int fill( int arr[], const int size ),
	output( int arr[], const int size ),
	all( int arr1[], int arr2[], int arr3[], const int size, int num );

int main() {
	setlocale(LC_ALL, "Rus");
	srand( time( NULL ) );

	int arr1[::size1],
		arr2[::size2],
		arr3[::size1 + ::size2],
		* ptr1 = arr1,
		* ptr2 = arr2,
		* ptr3 = arr3,
		col;

	fill( ptr1, ::size1 );
	fill( ptr2, ::size2 );
	output( ptr1, ::size1 );
	cout << endl;
	cout << endl;
	output( ptr2, ::size2 );
	cout << endl;
	cout << endl;

	cout << endl << endl << endl << endl;

	cout << "Что сделать с третим массивом: \n1. Элементы обоих массивов; \n2. Общие элементы двух массивов; \n3. Элементы массива A, которые не включаются в B; \n4. Элементы массива B, которые не включаются в A; \n5. Элементы массивов A и B, которые не являются общими для них";
	cout << endl;
	cin >> col;
	const int size3 = all( ptr1, ptr2, ptr3, ::size1 + ::size2, col );

	cout << endl;
	output( ptr3, size3 );
}

int fill( int arr[], const int size ) {
	int i;

	for (i = 0; i < size; i++) {
		arr[i] = rand() % 30;
	}

	return 0;
}

int all( int arr1[], int arr2[], int arr3[], const int size, int num ) {
	int i = 0, j, k, pred, tmp = 0;
	
	switch (num) {
		case 1:
			for (i = 0; i < ::size1; i++) {
				arr3[i] = arr1[i];
			}

			for (j = 0; j < ::size2; j++) {
				arr3[i] = arr2[j];
				i++;
			}
			break;
		case 2:
			for (k = 0; k < ::size1; k++) {
				for (j = 0; j < ::size2; j++) {
					if (arr1[k] == arr2[j]) {
						tmp++;
						break;
					}
				}
				if (tmp != 0) {
					arr3[i] = arr1[k];
					i++;
				}
				tmp = 0;
			}
			if (i == 0) {
				cout << "Совпадений не найдено" << endl;
			}
			break;
		case 3: 
			for (k = 0; k < ::size1; k++) {
				for (j = 0; j < ::size2; j++) {
					if (arr1[k] == arr2[j] ) {
						tmp++;
						break;
					}
				}
				if (tmp == 0) {
					arr3[i] = arr1[k];
					i++;
				}
				tmp = 0;
			}
			if (i == 0) {
				cout << "Совпадений не найдено" << endl;
			}
			break;
		case 4:
			for (k = 0; k < ::size1; k++) {
				for (j = 0; j < ::size2; j++) {
					if (arr2[k] == arr1[j]) {
						tmp++;
						break;
					}
				}
				if (tmp == 0) {
					arr3[i] = arr2[k];
					i++;
				}
				tmp = 0;
			}
			if (i == 0) {
				cout << "Совпадений не найдено" << endl;
			}
			break;
		case 5:
			for (k = 0; k < ::size1; k++) {
				for (j = 0; j < ::size2; j++) {
					if (arr1[k] == arr2[j] || arr2[k] == arr1[j]) {
						tmp++;
						break;
					}
				}
				if (tmp == 0) {
					arr3[i] = arr1[k];
					i++;
				}
				tmp = 0;
			}
			if (i == 0) {
				cout << "Совпадений не найдено" << endl;
			}
			break;
		default:
			cout << "Не знаю такой операции" << endl;
			break;
	}

	return i;
}

int output( int arr[], const int size ) {
	int i;

	cout << endl;

	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
