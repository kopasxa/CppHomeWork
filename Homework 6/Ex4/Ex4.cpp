
#include <iostream>
#include "time.h"

using namespace std;

void outputArr( int arr[], int size ) {
	int i;

	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

int fill( int arr[], int size ) {
	int i;

	for (i = 0; i < size; i++) {
		arr[i] = rand() % 15;
	}
	return 0;
}

int main() {
	setlocale( LC_ALL, "Rus" );
	srand( time( NULL ) );

	int arrsize1,
		arrsize2;

	cout << "Введите кол-во эл. 1 массива: ";
	cin >> arrsize1;
	cout << "Введите кол-во эл. 2 массива: ";
	cin >> arrsize2;

	int* arr1 = new int[arrsize1];
	int* arr2 = new int[arrsize2];

	fill( arr1, arrsize1 );
	fill( arr2, arrsize2 );

	outputArr( arr1, arrsize1 );
	outputArr( arr2, arrsize2 );

	int i,
		j,
		sum = 0,
		tmp = 0;


	for (i = 0; i < arrsize1; i++) {
		for (j = 0; j < arrsize2; j++) {
			if (arr1[i] == arr2[j]) {
				sum++;
				i++;
			}
		}
	}

	int* arr3 = new int[sum];

	int k = 0;

	for (i = 0; i < arrsize1; i++) {
		for (j = 0; j < arrsize2; j++) {
			if (arr1[i] == arr2[j]) {
				arr3[k] = arr1[i];
				k++;
				i++;
			}
		}
	}

	outputArr( arr3, sum );

	delete[] arr1, arr2, arr3;
}