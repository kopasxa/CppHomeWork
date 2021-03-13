#pragma once
#include "shape.h"

class Rectangle :
    public shape {
    double x, y, width, height;

    fstream f;
public:
    Rectangle( const Rectangle& copy );
    Rectangle() { x = 1, y = 1, width = 1, height = 1; };
    Rectangle( double nX, double nY, double nWidth, double nHeight );

    void Show();
    void Save();
    void Load();
};

