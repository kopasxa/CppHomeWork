#include <iostream>

using namespace std;

template <typename T1, typename T2>
class base {
public:
	T1 value1;
	T2 value2;

	template <typename T3, typename T4>
	class child1 {
	public:
		T3 value3;
		T4 value4;
	};

	template <typename T5, typename T6>
	class child2 {
	public:
		T5 value5;
		T6 value6;
	};
};

int main() {
	base<int, int> *A = new base<int, int>();

	A->value1 = 1;
	A->value2 = 2;

	cout << "class base->val1 = " << A->value1 << "\nclass base->val2 = " << A->value2 << "\n\n";

	base<int, int>::child1<int, int> *B = new base<int, int>::child1<int, int>();

	B->value3 = 3;
	B->value4 = 4;

	cout << "class base::child1->val4 = " << B->value3 << "\nclass base::child1->val4 = " << B->value4 << "\n\n";

	base<int, int>::child2<int, int> *C = new base<int, int>::child2<int, int>();

	C->value5 = 5;
	C->value6 = 6;

	cout << "class base::child2->val5 = " << C->value5 << "\nclass base::child2->val6 = " << C->value6<< "\n\n";
	
}

