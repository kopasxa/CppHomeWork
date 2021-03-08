#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	char FileName[80];
	cout << "FileName: ";
	cin >> FileName;

	ofstream outF( FileName, ios::out );
	if (!outF) {
		cout << "\n" << "Error write to file";
		return 1;
	}
	
	outF << "agent228" << "\n";

	int X, Y;

	cout << "Input size matrix:\n";
	cout << "X: ";
	cin >> X;
	cout << "Y: ";
	cin >> Y;
	outF << X << ' ' << Y << "\n";
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