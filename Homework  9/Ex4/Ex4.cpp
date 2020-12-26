#include <iostream>
#include <string>
#include <time.h>
#define STUDENTS 5

using namespace std;

struct person {
	string surname;
	int group;
	struct bits {
		unsigned pass : 1;
	} passed;
};

void sort( person arr[] ) {
	person temp;
	cout << "Сортировка..." << endl;
	int i;
	for (i = 0; i < STUDENTS; i++) {
		for (int j = i + 1; j < STUDENTS; j++) {
			if (arr[i].surname > arr[j].surname) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void print(person arr[], string pr) {
	int i;
	if (pr == "all") {
		for (i = 0; i < STUDENTS; i++) {
			cout << "Фамилия: " << arr[i].surname << endl;
			cout << "Группа: " << arr[i].group << endl;
			cout << "Зачет: ";
			if (arr[i].passed.pass == 1)
				cout << "Сдан";
			else
				cout << "Не сдан";
			cout << endl << endl;
		}
	}
	else if(pr == "sdan") {
		cout << "Сдали: " << endl;
		for (i = 0; i < STUDENTS; i++) {
			if (arr[i].passed.pass != 0) {
				cout << "Фамилия: " << arr[i].surname << endl;
				cout << "Группа: " << arr[i].group << endl;
				cout << "Зачет: " << "Сдан";
				cout << endl << endl;
			}
		}
	}
	else if (pr == "nesdan") {
		cout << "Не cдали: " << endl;
		for (i = 0; i < STUDENTS; i++) {
			if (arr[i].passed.pass != 1) {
				cout << "Фамилия: " << arr[i].surname << endl;
				cout << "Группа: " << arr[i].group << endl;
				cout << "Зачет: " << "Не сдан";
				cout << endl << endl;
			}
		}
	}

	cout << endl << endl << endl;
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	int i;
	person arr[STUDENTS];

	string surNameStudents[] = {"ckapysta", "bpetrov", "korolenko", "asavenko", "dsemenuk"};

	for (i = 0; i < STUDENTS; i++) {
		arr[i].surname = surNameStudents[i];
		arr[i].group = rand() % 3 + 1;
		arr[i].passed.pass = rand() % 2;
	}

	print(arr, "all");

	sort(arr);

	print( arr, "all" );

	print(arr, "sdan");

	print( arr, "nesdan" );
}


