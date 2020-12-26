// 2. � ����� function.cpp ���������� �������� ��������� ������� ��� ������ � ��������
// ������ :
// �) ������� ��� ���������� ������� ���������� ����������;
// �) ������� ��� ������ �������� ������� �� �������;
// �) ������� ��� ������ ������������ ��������;
// �) ������� ��� ������ ������������� ��������;
// �) ������� ��� ����������;
// �) ������� ��� �������������� �������� �������.
// ������ ������� ���������� �������� ��� ������ � �������� �����, �������������� �
// ���������� ��������. (��� ������� ���� �������� ��������� �������) .

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
	cout << endl << "�������� ������� ������� ������ ���������������: " << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << arr[i] << endl;
	}
	int num;
	cin >> num;
	cout << "������� ����� ��������: ";
	int newValue;
	cin >> newValue;
	for (int i = 0; i < size; i++) {
		if (num - 1 == i) {
			arr[i] = newValue;
		}
	}
	cout << "�������� ������� ��������! " << endl;
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
	cout << endl << "�������� ������� ������� ������ ���������������: " << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << arr[i] << endl;
	}
	int num;
	cin >> num;
	cout << "������� ����� ��������: ";
	double newValue;
	cin >> newValue;
	for (int i = 0; i < size; i++) {
		if (num - 1 == i) {
			arr[i] = newValue;
		}
	}
	cout << "�������� ������� ��������! " << endl;
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
	cout << endl << "�������� ������� ������� ������ ���������������: " << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << arr[i] << endl;
	}
	int num;
	cin >> num;
	cout << "������� ����� ��������: ";
	char newValue;
	cin >> newValue;
	for (int i = 0; i < size; i++) {
		if (num - 1 == i) {
			arr[i] = newValue;
		}
	}
	cout << "�������� ������� ��������! " << endl;
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