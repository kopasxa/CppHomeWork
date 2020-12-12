#include <iostream>
#include <time.h>

using namespace std;

int** init( int n, int m ) {
	int** Matrix = new int* [n];
	for (int i = 0; i < n; i++)
		Matrix[i] = new int[m];
	return Matrix;
}

void del( int** arr, int n, int m ) {
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
}

int** transport( int** arr, int& n, int& m ) {
	int** tMatrix = init( m, n );

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tMatrix[i][j] = arr[j][i];
	int temp = n;
	n = m;
	m = temp;

	return tMatrix;
}

void output( int** arr, int n, int m ) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

void main( void ) {
	srand( time( NULL ) );
	int row, col;
	int** pArr; 
	row = 5;
	col = 5;
	pArr = init( row, col );

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			pArr[i][j] = rand() % 90 + 10;
		}
	}	

	output( pArr, row, col );

	pArr = transport( pArr, row, col );

	output( pArr, row, col );
	del( pArr, row, col );
}