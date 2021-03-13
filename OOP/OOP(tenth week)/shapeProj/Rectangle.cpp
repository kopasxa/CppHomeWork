#include "Rectangle.h"

Rectangle::Rectangle( const Rectangle& copy ) {
	this->x = copy.x;
	this->y = copy.y;
	this->width = copy.width;
	this->height = copy.height;
}

Rectangle::Rectangle( double nX, double nY, double nWidth, double nHeight ) {
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

void Rectangle::Show() {
	cout << "Rectangle: {\n\tx = " << this->x << "\n\ty = " << this->y << "\n\twidth = " << this->width << "\n\theight = " << this->height << "\n}\n\n";
}

void Rectangle::Save() {
	f.open( "Rectangle.txt", ios::app );

	if (f) {
		f << "\nRectangle: " << this->x << " " << this->y << " " << this->width << " " << this->height;
	}

	f.close();
}

void Rectangle::Load() {
	f.open( "Rectangle.txt" );
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
