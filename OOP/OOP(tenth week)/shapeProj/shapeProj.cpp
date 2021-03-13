#include <iostream>
#include "shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Circle.h"
#include <vector>
#include <fstream>

using namespace std;

int main() {
	Square s(5, 10, 1), s1(5, 6, 7);

	Rectangle r(1, 5, 10, 8);
	r.Show();
	r.Save();
	r.Load();

	Circle c;
	c.Show();
	c.Save();
	c.Load();

	Ellipse e;
	e.Show();
	e.Save();
	e.Load();

	vector<Square> arrSq;
	arrSq.push_back(s);
	arrSq.push_back(s1);

	for (int i = 0; i < arrSq.size(); i++) {
		arrSq[i].Save();
	}

	s.Load();
}

