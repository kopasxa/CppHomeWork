// Даны два массива, упорядоченных по возрастанию:
// А[n] и B[m]. Сформируйте массив C[n+m], состоящий из элементов массивов А и В, упорядоченный
// по возрастанию. Используйте синтаксис указателей.
   
#include <iostream>
#include "time.h"

using namespace std;

const int size1 = 10,
		  size2 = 15,
		  size3 = size1 + size2;

int fill( int arr[], const int size ),
	sort( int arr[], const int size ),
	output( int arr[], const int size );

int main() {
	srand(time(NULL));

	int arr1[::size1],
		arr2[::size2],
		arr3[::size1 + ::size2],
	   *ptr1 = arr1,
	   *ptr2 = arr2,
	   *ptr3 = arr3,
		i, j;

	fill( ptr1, ::size1 );
	fill( ptr2, ::size2 );
	output( ptr1, ::size1 );
	cout << endl;
	cout << endl;
	output( ptr2, ::size2 );
	sort( ptr1, ::size1 );
	sort( ptr2, ::size2 );
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	output( ptr1, ::size1 );
	cout << endl;
	cout << endl;
	output( ptr2, ::size2 );

	for (i = 0; i < ::size1; i++) {
		ptr3[i] = ptr1[i];
	}

	for (j = 0 ; j < ::size2; j++) {
		ptr3[i] = ptr2[j];
		i++;
	}

	cout << endl << endl << endl << endl;
	output( ptr3, ::size3 );
	cout << endl;
	sort( ptr3, ::size3 );
	cout << endl;
	output( ptr3, ::size3 );
}

int fill( int arr[], const int size ) {
	int i;

	for (i = 0; i < size; i++) {
		arr[i] = rand() % 1000;
	}

	return 0;
}

int sort( int arr[], const int size ) {
	int i, k, x, j;

	for (i = 0; i < size; i++) {
		k = i;
		x = arr[i];
		for (j = i + 1; j < size; j++)
			if (arr[j] < x) {
				k = j;
				x = arr[j];
			}
		if (k != i) {
			arr[k] = arr[i];
			arr[i] = x;
		}
	}
	
	return 0;
}

int output( int arr[], const int size ) {
	int i;

	cout << endl;

	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
