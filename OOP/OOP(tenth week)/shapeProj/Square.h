#pragma once
#include "shape.h"

using namespace std;

class Square : public shape {
	double x, y, width;

	fstream f;
public:
	Square( const Square& copy );
	Square() { x = 1, y = 1, width = 1; }
	Square( double nX, double nY, double nWidth );

	void Show();
	void Save();
	void Load();
};

