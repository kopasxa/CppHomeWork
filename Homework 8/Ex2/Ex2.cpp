//Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.

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

void delcol( int* arr[], int strS, int colS, int num) {
	int i,
		j,
		colSNew = colS - 1;

	int** pArrNew = new int* [strS];

	for (i = 0; i < strS; i++)
		pArrNew[i] = new int[colSNew];

	for (i = 0; i < strS; i++) {
		int currentCol = 0;
		for (j = 0; j < colSNew + 1; j++) {
			if (j != num - 1) {
				pArrNew[i][currentCol] = arr[i][j];
				currentCol++;
			}
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

	srand( time( NULL ) );

	cin >> strS >> colS;

	int** pArr = new int* [strS];

	for (i = 0; i < strS; i++)
		pArr[i] = new int[colS];

	fill( pArr, strS, colS );

	output( pArr, strS, colS );


	delcol( pArr, strS, colS, 3 );


	for (i = 0; i < strS; i++)
		delete[]pArr[i];
	delete[]pArr;
}
