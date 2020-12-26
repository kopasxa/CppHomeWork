// Используя указатель на массив целых чисел, изменить порядок следования элементов массива на противоположный.

#include <iostream>

using namespace std;

int main() {

	const int size = 6;
	int arr[size] {
		10, 435, 445, 496, 7087, 234
	},
		i,
		*pt = arr,
		temp;

	for (i = 0; i < size; i++) {
		cout << pt[i] << " ";
	}
	
	cout << endl;

	for (i = 0; i < size; i++) {
		temp = pt[i];
		pt[i] = pt[size - i - 1];
		pt[size - i - 1] = temp;
		cout << pt[i] << " ";
	}
}
