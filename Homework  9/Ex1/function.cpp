// 2. в файле function.cpp необходимо написать следующие функции для работы с массивом
// данных :
// а) функцию для заполнения массива случайными значениями;
// б) функцию для вывода значений массива на консоль;
// в) функцию для поиска минимального элемента;
// г) функцию для поиска максимального элемента;
// д) функцию для сортировки;
// е) функцию для редактирования значения массива.
// Данные функции необходимо написать для работы с массивом целых, действительных и
// символьных значений. (Для каждого типа написать отдельную функцию) .

#include <iostream>
#include <time.h>
#include "function.h"

using namespace std;

// **** INTEGER ****

inline void initInt( int arr[], int size ) {
	srand( time( NULL ) );

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 90 + 9;
	}
}

inline void editInt( int arr[], int size ) {
	cout << endl << "Выберите элемент который хотите отредактировать: " << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << arr[i] << endl;
	}
	int num;
	cin >> num;
	cout << "Введите новое значение: ";
	int newValue;
	cin >> newValue;
	for (int i = 0; i < size; i++) {
		if (num - 1 == i) {
			arr[i] = newValue;
		}
	}
	cout << "Значение успешно изменено! " << endl;
}

inline void sortInt( int arr[], int size ) {
	for (int i = 0; i < size; i++) {
		int temp = arr[0];
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

inline int maxElInt( int arr[], int size ) {
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max; 
}

inline int minElInt( int arr[], int size ) {
	int min = arr[0];
	for (int i = 0; i < size; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	return min;
}

inline void outputInt( int arr[], int size ) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// **** DOUBLE ****

inline void initDouble( double arr[], int size ) {
	srand( time( NULL ) );

	for (int i = 0; i < size; i++) {
		arr[i] = (double)(rand() % (i / 100));
	}
}

inline void editDouble( double arr[], int size ) {
	cout << endl << "Выберите элемент который хотите отредактировать: " << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << arr[i] << endl;
	}
	int num;
	cin >> num;
	cout << "Введите новое значение: ";
	double newValue;
	cin >> newValue;
	for (int i = 0; i < size; i++) {
		if (num - 1 == i) {
			arr[i] = newValue;
		}
	}
	cout << "Значение успешно изменено! " << endl;
}

inline void sortDouble( double arr[], int size ) {
	for (int i = 0; i < size; i++) {
		double temp = arr[0];
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

inline double maxElDouble( double arr[], int size ) {
	double max = arr[0];
	for (int i = 0; i < size; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

inline double minElDouble( double arr[], int size ) {
	double min = arr[0];
	for (int i = 0; i < size; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	return min;
}

inline void outputDouble( double arr[], int size ) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// **** CHAR ****

inline void initChar( char arr[], int size ) {
	srand( time( NULL ) );

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 90 + 9;
	}
}

inline void editChar( char arr[], int size ) {
	cout << endl << "Выберите элемент который хотите отредактировать: " << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << arr[i] << endl;
	}
	int num;
	cin >> num;
	cout << "Введите новое значение: ";
	char newValue;
	cin >> newValue;
	for (int i = 0; i < size; i++) {
		if (num - 1 == i) {
			arr[i] = newValue;
		}
	}
	cout << "Значение успешно изменено! " << endl;
}

inline void sortChar( char arr[], int size ) {
	for (int i = 0; i < size; i++) {
		char temp = arr[0];
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

inline char maxElChar( char arr[], int size ) {
	char max = arr[0];
	for (int i = 0; i < size; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

inline char minElChar( char arr[], int size ) {
	char min = arr[0];
	for (int i = 0; i < size; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	return min;
}

inline void outputChar( char arr[], int size ) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}