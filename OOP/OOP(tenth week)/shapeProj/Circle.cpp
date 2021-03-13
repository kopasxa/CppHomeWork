#include "Circle.h"

Circle::Circle( const Circle& copy ) {
	this->x = copy.x;
	this->y = copy.y;
	this->radius = copy.radius;
}

Circle::Circle( double nX, double nY, double nRadius ) {
	this->x = nX;
	this->y = nY;
	if (nRadius > 0) {
		this->radius = nRadius;
	}
	else {
		this->radius = 1;
	}
}

void Circle::Show() {
	cout << "Circle: {\n\tx = " << this->x << "\n\ty = " << this->y << "\n\tradius = " << this->radius << "\n}\n\n";
}

void Circle::Save() {
	f.open( "Circle.txt", ios::app );

	if (f) {
		f << "\nCircle: " << this->x << " " << this->y << " " << this->radius;
	}

	f.close();
}

void Circle::Load() {
	f.open( "Circle.txt" );
	string s;

	if (f) {
		while (!f.eof()) {
			f >> s;
			cout << s << " X = ";
			f >> s;
			cout << s << ", Y = ";
			f >> s;
			cout << s << ", Radius = ";
			f >> s;
			cout << s << ";";
			cout << "\n\n";
		}
	}

	f.close();
}
