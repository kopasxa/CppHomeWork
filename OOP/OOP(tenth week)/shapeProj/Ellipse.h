#pragma once
#include "shape.h"

class Ellipse :
    public shape {
    double x, y, width, height;

    fstream f;
public:
    Ellipse( const Ellipse& copy );
    Ellipse() { x = 1, y = 1, width = 1, height = 1; };
    Ellipse( double nX, double nY, double nWidth, double nHeight );

    void Show();
    void Save();
    void Load();
};

