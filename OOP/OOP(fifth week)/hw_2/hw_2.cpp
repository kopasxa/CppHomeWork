#include <iostream>
#include "fifo.h"
#include "windows.h"

using namespace std;

void load();
int menu();

int main() {
	fifo filo( 0 );

	fifo filo2;

	load();

	bool run = true;

	while (run) {

		int num = menu();

		if (num == 1) filo.print();
		else if (num == 2) {
			cout << "Input number to add: ";
			int newInt,
				prior;
			cin >> newInt;
			cout << "Input prioritet: ";
			cin >> prior;
			filo.push( newInt, prior );
		}
		else if (num == 3) filo.pop();
		else if (num == 4) cout << filo.getSize() << endl;
		else if (num == 5) cout << filo.getFirstItem() << endl;
		else if (num == 6) {
			filo2 = filo;
			filo2.print();
		}
		else if (num == 7) cout << filo.getLastItem() << endl;
		else if (num == 8) cout << filo.minPr() << endl;
		else if (num == 9) {
			cout << "Ok (";
			run = false;
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
	Sleep( 1000 );
	system( "cls" );
}

int menu() {
	int num;

	cout << "\n\n\t\t **** FIFO **** \n";
	cout << "1. Show all item in FIFO" << endl;
	cout << "2. Add item" << endl;
	cout << "3. Delete last item" << endl;
	cout << "4. Show FIFO size" << endl;
	cout << "5. Show first item" << endl;
	cout << "6. Copy fifo" << endl;
	cout << "7. Show last item" << endl;
	cout << "8. Show min prioritet" << endl;
	cout << "9. Close" << endl << endl;

	cout << "Input number menu: ";
	cin >> num;
	return num;
}


