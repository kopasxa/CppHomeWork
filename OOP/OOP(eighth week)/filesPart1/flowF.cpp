#include "flowF.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

flowF::flowF() {
	cout << "FileName: ";
	cin >> FileName;
	
	while (!checkErr( FileName )) {
		cout << "ERR: mistake in name (\n";
		cout << "FileName: ";
		cin >> FileName;
	}

	if (checkErr(FileName)) {
		strcat_s(FileName, ".txt");
	}
}

bool flowF::checkErr( char checkStr[] ) {
	int i,
		j;

	for (i = 0; i < strlen( checkStr ); i++) {
		for (j = 0; j < MAX_ERR; j++) {
			if (checkStr == err[j] || checkStr[i] == err2[j]) {
				return false;
			}
		}
	}

	if (checkStr[strlen( checkStr ) - 1] == '.' || checkStr[strlen( checkStr ) - 1] == ' ') {
		return false;
	}

	return true;
}

void flowF::write() {
	outF.open(FileName, ios::out);
	if (!outF) {
		cout << "\n" << "Error write to file";
		exit(1);
	}

	outF << "SecretKey: " << secretKey << "\n";

	int X, Y;

	cout << "Input size matrix:\n";
	cout << "X: ";
	cin >> X;
	cout << "Y: ";
	cin >> Y;
	outF << X << ' ' << Y << "\n\n";
	cout << "Elements: \n";

	int num;

	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			cout << "A[" << i << "][" << j << "] = ";
			cin >> num;
			outF << num << " ";
		}
		outF << "\n";
	}
	outF.close();
}

void flowF::read() {
	outF.open( FileName, ios::in | ios::_Nocreate );
	if (!outF.is_open()) {
		cout << "\n" << "Error read file";
		exit( 1 );
	}

	string s; 
	int i;
	for (i = 0; i < 2; i++) {
		outF >> s;
	}

	if (s == secretKey) {
		int X, Y;

		outF >> X;
		outF >> Y;


		int** arr = new int* [X];
		for (int i = 0; i < X; ++i) {
			arr[i] = new int[Y];
		}

		int i,
			j;

		for (i = 0; i < X; i++) {
			for (j = 0; j < Y; j++) {
				outF >> s;
				arr[i][j] = atoi(s.c_str());
			}
		}

		for (i = 0; i < X; i++) {
			for (j = 0; j < Y; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "Not our file (\n";
	}

	outF.close();
}

flowF::~flowF() {
	/*outF.close();*/
}
