// Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.

#include <iostream>
#include "time.h"

using namespace std;

void output( int* arr[], int size1, int size2 ) {
	int i,
		j;

	for (i = 0; i < size1; i++) {
		for (j = 0; j < size2; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl << endl;
}

void fill( int* arr[], int size1, int size2 ) {
	int i,
		j;

	for (i = 0; i < size1; i++) {
		for (j = 0; j < size2; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}

void addCol( int* arr[], int strS, int colS ) {
	int i,
		j,
		colSNew = colS + 1;

	int** pArrNew = new int* [strS];

	for (i = 0; i < strS; i++)
		pArrNew[i] = new int[colSNew];

	fill( pArrNew, strS, colSNew );

	for (i = 0; i < strS; i++) {
		for ( j = 0; j < colS; j++) {
			pArrNew[i][j] = arr[i][j];
		}
	}

	output( pArrNew, strS, colSNew );

	for (i = 0; i < strS; i++)
		delete[]pArrNew[i];
	delete[]pArrNew;
}

int main() {
	int strS,
		colS,
		i,
		j;

	srand(time(NULL));

	cin >> strS >> colS;

	int** pArr = new int* [strS];

	for (i = 0; i < strS; i++)
		pArr[i] = new int[colS];

	fill( pArr, strS, colS );

	output( pArr, strS, colS );


	addCol( pArr, strS, colS );


	for (i = 0; i < strS; i++)
		delete[]pArr[i];
	delete[]pArr;
	
}
