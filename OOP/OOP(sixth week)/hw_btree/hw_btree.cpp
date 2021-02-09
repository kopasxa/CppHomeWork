#include <iostream>
#include "btree.h"

using namespace std;

int menu();
bool logic( btree &ex );

int main() {
	btree ex;
	while (logic( ex ));
}

int menu() {
	cout << "\tBinary Tree\n";
	cout << "1. Add element to tree\n";
	cout << "2. Find by key\n";
	cout << "3. Find min el\n";
	cout << "4. Find max el\n";
	cout << "5. Print el by growth\n";
	cout << "6. Print all leaf tree\n";
	cout << "7. Print tree\n";
	cout << "8. Exit\n";

	int num;
	cin >> num;
	return num;
}

bool logic( btree &ex ) {
	int numMenu = menu();
	bool working = true;
	Tree* root = ex.GetRoot();

	switch (numMenu) {
		case 1:
			cout << "Input el for insert to tree: ";
			int num;
			cin >> num;
			ex.Insert( root, num );
			cout << "Success!" << endl;
			break;
		case 2:
			cout << "Input el for find: ";
			int num2;
			cin >> num2;
			cout << "Element: ";
			ex.findByKey( root, num2 );
			cout << endl;
			break;
		case 3:
			cout << "Min element: " << ex.min( root ) << endl;
			break;
		case 4:
			cout << "Max element: " << ex.max( root ) << endl;
			break;
		case 5:
			ex.PrintSort( root );
			cout << endl;
			break;
		case 6:
			cout << "All leaf on tree: ";
			ex.printLeaf( root );
			cout << endl;
			break;
		case 7:
			ex.Print( root, 0 );
			break;
		default:
			working = !working;
			break;
	}

	return working;
}
