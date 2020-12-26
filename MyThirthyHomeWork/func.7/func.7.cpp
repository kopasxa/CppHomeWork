// Написать функцию, определяющую минимум и максимум
// (значение и номер) элементов передаваемого ей массива

#include <iostream>
#include <time.h>

using namespace std;

void minMax(int arr[10]) {
	int min = 0,
		max = 0,
		mini = 0,
		maxi = 0,
		i;

	min = max = arr[0];

	for (i = 1; i < 10; i++) {
		if (min >= arr[i]) {
			min = arr[i];
			mini = i;
		}
		if (max <= arr[i]) {
			max = arr[i];
			maxi = i;
		}
	}

	cout << "min { \n\tValue: " << min << "\n\tNumber: " << mini + 1 << "\n}";
	cout << "\nmax { \n\tValue: " << max << "\n\tNumber: " << maxi + 1 << "\n}";
}

int main() {
	srand(time(NULL));

	const int size = 10;
	int arr[size], i;

	for (i = 0; i < size; i++) {
		arr[i] = rand() % 100;
	}

	for (i = 0; i < size - 1; i++) {
		cout << arr[i] << ", ";
	}

	cout << arr[size - 1] << "." << endl;
	
	minMax(arr);
}


