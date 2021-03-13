#include <iostream>
#include <math.h> 

using namespace std;

class main {
public:
	virtual void getMain() = 0;
	virtual ~main() = default;
};

class linear : public main {
	float num1,
		  num2;

public:
	linear( float a, float b ) : num1(a), num2(b) {};
	void getMain() {
		float res;
		if (num1 && num2) {
			res = num2 / num1; 
		}
		else {
			res = 0;
		}
		
		cout << "Result: " << res << "\n";
	}
};

class sq : public main {
	float num1,
		num2,
		num3;

public:
	sq( float a, float b, float c ) : num1( a ), num2( b ), num3( c ) {};
	void getMain() {
		float x1, x2, dis;
		if (num1 == 0) {
			cout << "i don`t know how to do it ( \n";
		}
		dis = pow(num2, 2) - (4 * num1 * num3);
		cout << dis << endl;
		if (dis > 0) {
			x1 = (-num2 + sqrt( dis )) / (num1 * 2);
			x2 = (-num2 - sqrt( dis )) / (num1 * 2);
			cout << "x1 = " << x1 << "\nx2 = " << x2 << endl; 
		}
		else if ( dis == 0 ) {
			x1 = (-num2 / (2 * num1));
			cout << "x = " << x1 << endl;
		}
		else {
			cout << "err ( \n";
		}
	}
};

int main() {
	linear *l1 = new linear(5, -10);
	l1->getMain();

	sq* s1 = new sq( 1, -8, 12 );
	s1->getMain();

	delete l1;
	delete s1;
}
