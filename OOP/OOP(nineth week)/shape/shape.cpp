#include <iostream>
#include <vector>

using namespace std;

class Point {
protected:
	int x;
	int y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	//получение x
	int& GetX() {
		return x;
	}
	//получение y
	int& GetY() {
		return y;
	}
};

class figura : public Point {
	int width;
	int height;
public:
	figura( int W, int H ) {
		width = W;
		height = H;
	}

	//получение ширины
	int& GetWidth() {
		return width;
	}

	int& GetHeight() {
	return height;
	}
	//функции сдвига
	void MoveX( int DX ) {
		x += DX;
	}
	void MoveY( int DY ) {
		y = DY;
	}
	//показ на экран
	void Show() {
		cout << "--------------\n\n";
		cout << "X = " << x << "\n\n";
		cout << "Y = " << y << "\n\n";
		cout << "W = " << width << "\n\n";
		cout << "H = " << height << "\n\n";
		cout << "--------------\n\n";
	}
};

class composition {
	vector<figura*> _figura;

public:

	composition() {
		
	};

	void add( figura* fig ) {
		_figura.push_back( fig );
	}

	friend ostream& operator<<( ostream& out, const composition& comp ) {
		for (int i = 0; i < comp._figura.size(); i++) {
			out << "--------------\n\n";
			out << "X = " << comp._figura[i]->GetX() << "\n\n";
			out << "Y = " << comp._figura[i]->GetY() << "\n\n";
			out << "W = " << comp._figura[i]->GetWidth() << "\n\n";
			out << "H = " << comp._figura[i]->GetHeight() << "\n\n";
			out << "--------------\n\n";
		}
		return out;
	}
};

int main() {
	//создание объекта
	composition cp = composition();

	figura* A = new figura( 10, 10 );

	A->GetX() = 5;
	A->GetY() = 3;
	A->GetWidth() = 40;
	A->GetHeight() = 50;
	cp.add( A );

	figura* B = new figura( 10, 10 );

	B->GetX() = 23;
	B->GetY() = 60;
	cp.add( B );
	
	cout << cp;

	delete A, B;
}
