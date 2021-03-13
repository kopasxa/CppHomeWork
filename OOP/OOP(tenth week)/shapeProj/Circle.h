#pragma once
#include "shape.h"

class Circle :
    public shape {
    double x, y, radius;

    fstream f;
public:
    Circle( const Circle& copy );
    Circle() { x = 1, y = 1, radius = 1; };
    Circle( double nX, double nY, double nRadius );

    void Show();
    void Save();
    void Load();
};

