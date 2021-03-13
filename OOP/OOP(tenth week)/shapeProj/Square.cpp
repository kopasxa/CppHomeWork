#include "Square.h"

Square::Square( const Square& copy ) {
	this->x = copy.x;
	this->y = copy.y;
	this->width = copy.width;
}

Square::Square( double nX, double nY, double nWidth ) {
	this->x = nX;
	this->y = nY;
	if (nWidth > 0) {
		this->width = nWidth;
	}
	else {
		this->width = 1;
	}
}

void Square::Show() {
	cout << "Square: {\n\tx = " << this->x << "\n\ty = " << this->y << "\n\twidth = " << this->width << "\n}\n\n";
}

void Square::Save() {
	f.open( "Square.txt", ios::app );

	if (f) {
		f << "\nSquare: " << this->x << " " << this->y << " " << this->width;
	}

	f.close();
}

void Square::Load() {
	f.open( "Square.txt" );
	string s;

	if (f) {
		while (!f.eof()) {
			f >> s;
			cout << s << " X = ";
			f >> s;
			cout << s << ", Y = ";
			f >> s;
			cout << s << ", Width = ";
			f >> s;
			cout << s << ";";
			cout << "\n\n";
		}
 	}

	f.close();
}
