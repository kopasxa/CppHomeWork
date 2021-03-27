#include <iostream>
#include "countingMoney.h"

using namespace std;

int main() {
	countingMoney *c = new countingMoney;

	while (1) {
		int num = c->menu();

		if (num == 1) {
			c->amountOfIncome();
		}
		else if (num == 2) {
			c->amountOfExpenses();
		}
		else if (num == 3) {
			c->maximumIncome();
		}
		else if (num == 4) {
			c->maximumFlow();
		}
		else if (num == 5) {
			c->checkAllTransaction();
		}
		else if (num == 6) {
			cout << "Good bye (\n";
			break;
		}
		else {
			cout << "No number found (\n";
		}
	}
	
	delete c;
}
