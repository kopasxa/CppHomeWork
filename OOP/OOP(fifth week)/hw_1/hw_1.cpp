#include <iostream>
#include "stack.h"
#include "windows.h"

using namespace std;

void load();
int menu();

int main() {
	stack filo( 0 );

	stack filo2;
	
	load();

	bool run = true;

	while (run) {

		int num = menu();

		if (num == 1) filo.print();
		else if (num == 2) {
			cout << "Input number to add: ";
			int newInt;
			cin >> newInt;
			filo.push( newInt );
		}
		else if (num == 3) filo.pop();
		else if (num == 4) cout << filo.getSize() << endl;
		else if (num == 5) cout << filo.getFirstItem() << endl;
		else if (num == 6) {
			filo2 = filo;
			filo2.print();
		}
		else if (num == 7) {
			cout << "Ok (";
			Sleep( 1000 );
			run = false;
			system( "cls" );
		}
		else cout << "Num not found" << endl;
		
	}
}

void load() {
	for (int i = 1; i < 34; i++) {
		int j = 0;
		while (j < i) {
			cout << "##";
			j++;
		}
		cout << "\n" << i * 3 << "%";
		Sleep( 5 );
		system( "cls" );
	}
	cout << "Status: Loaded!";
	Sleep(1000);
	system( "cls" );
}

int menu() {
	int num;

	cout << "\n\n\t\t **** STACK **** \n";
	cout << "1. Show all item in stack" << endl;
	cout << "2. Add item" << endl;
	cout << "3. Delete last item" << endl;
	cout << "4. Show stack size" << endl;
	cout << "5. Show first item" << endl;
	cout << "6. Copy stack" << endl;
	cout << "7. Close" << endl << endl;

	cout << "Input number menu: ";
	cin >> num;
	return num;
}

