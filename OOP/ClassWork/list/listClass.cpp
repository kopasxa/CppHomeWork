#include "listClass.h"

listClass::listClass() {
	group temp;
	while (numbers != 0) {
		cout << "Enter the amount \n";
		cin >> this->numbers;
		temp.money = this->numbers;

		if (this->numbers != 0) {
			cout << "Enter description of profitability \n";
			cin >> temp.desc;
		}

		if (this->numbers > 0) {
			income.push_back( temp );
			this->balance += this->numbers;
		}
		else if (this->numbers < 0 && this->balance > 0) {
			this->costs.push_back( temp );
			this->balance -= numbers;
		}
		else if (this->balance <= 0) {
			cout << "It is impossible to deduct the expense ((\n";
		}
	}

	this->sizeIncome = this->income.size();
	this->sizeCosts = this->costs.size();
}

int listClass::menu() {
	cout << "\n1. Amount of income\n2. Amount of expenses\n3. Maximum income\n4. Maximum flow\n5. All transaction\n6. Exit\n";
	int num;
	cin >> num;
	return num;
}

void listClass::amountOfIncome() {
	if (this->sizeIncome > 0) {
		float sumIncome = 0;
		list<group>::iterator it = this->income.begin();

		for (int i = 0; i < this->income.size(); i++) {
			advance( it, i );
			sumIncome += it->money;
		}

		cout << "Amount of income: " << sumIncome << "\n";
	}
	else {
		cout << "Not found (\n";
	}
}

void listClass::amountOfExpenses() {
	if (this->sizeCosts > 0) {
		float sumCosts = 0;
		list<group>::iterator it = this->costs.begin();

		for (int i = 0; i < this->sizeCosts; i++) {
			advance( it, i );
			sumCosts += it->money;
		}

		cout << "Amount of expenses: " << sumCosts << "\n";
	}
	else {
		cout << "Not found (\n";
	}
}

void listClass::maximumIncome() {
	if (this->sizeIncome > 0) {
		list<group>::iterator it = this->income.begin();
		advance( it, 0 );
		group minIncome = *it;

		for (int i = 0; i < this->sizeIncome; i++) {
			advance( it, i );
			if (minIncome.money < it->money) {
				minIncome = *it;
			}
		}

		cout << "Maximum income: " << minIncome.money << " : " << minIncome.desc << "\n";
	}
	else {
		cout << "Not found (\n";
	}
}

void listClass::maximumFlow() {
	if (sizeCosts > 0) {
		list<group>::iterator it = this->costs.begin();
		advance( it, 0 );
		group minCosts = *it;

		for (int i = 0; i < this->sizeCosts; i++) {
			advance( it, i );
			if (minCosts.money > it->money) {
				minCosts = *it;
			}
		}

		cout << "Maximum flow: " << minCosts.money << " : " << minCosts.desc << "\n";
	}
	else {
		cout << "Not found (\n";
	}
}

void listClass::checkAllTransaction() {
	if (this->sizeIncome > 0) {
		list<group>::iterator it = this->income.begin();

		for (int i = 0; i < this->sizeIncome; i++) {
			advance( it, i );

			cout << it->money << " : " << it->money << "\n";
		}
	}

	if (sizeCosts > 0) {
		list<group>::iterator it = this->costs.begin();

		for (int i = 0; i < this->sizeCosts; i++) {
			advance( it, i );

			cout << it->money << " : " << it->money << "\n";
		}
	}
}

