#include "Ellipse.h"

Ellipse::Ellipse( const Ellipse& copy ) {
	this->x = copy.x;
	this->y = copy.y;
	this->width = copy.width;
	this->height = copy.height;
}

Ellipse::Ellipse( double nX, double nY, double nWidth, double nHeight ) {
	this->x = nX;
	this->y = nY;
	if (nWidth > 0 && nHeight > 0) {
		this->width = nWidth;
		this->height = nHeight;
	}
	else {
		this->width = 1;
		this->height = 1;
	}
}

void Ellipse::Show() {
	cout << "Ellipse: {\n\tx = " << this->x << "\n\ty = " << this->y << "\n\twidth = " << this->width << "\n\theight = " << this->height << "\n}\n\n";
}

void Ellipse::Save() {
	f.open( "Ellipse.txt", ios::app );

	if (f) {
		f << "\nEllipse: " << this->x << " " << this->y << " " << this->width << " " << this->height;
	}

	f.close();
}

void Ellipse::Load() {
	f.open( "Ellipse.txt" );
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
			cout << s << ", Height = ";
			f >> s;
			cout << s << ";";
			cout << "\n\n";
		}
	}

	f.close();
}
