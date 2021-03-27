#include "countingMoney.h"

countingMoney::countingMoney() {
	group temp;
	while (numbers != 0) {
		cout << "Enter the amount \n";
		cin >> numbers;
		temp.money = numbers;
		
		if (numbers != 0) {
			cout << "Enter description of profitability \n";
			cin >> temp.desc;
		}

		if (numbers > 0) {
			income.push_back( temp );
			balance += numbers;
		}
		else if (numbers < 0 && balance > 0) {
			costs.push_back( temp );
			balance -= numbers;
		}
		else if (balance <= 0) {
			cout << "It is impossible to deduct the expense ((\n";
		}
	}

	sizeIncome = income.size();
	sizeCosts = costs.size();
}

int countingMoney::menu() {
	cout << "\n1. Amount of income\n2. Amount of expenses\n3. Maximum income\n4. Maximum flow\n5. All transaction\n6. Exit\n";
	int num;
	cin >> num;
	return num;
}

void countingMoney::amountOfIncome() {
	if (sizeIncome > 0) {
		float sumIncome = 0;
		for (int i = 0; i < sizeIncome; i++) {
			sumIncome += income.at( i ).money;
		}

		cout << "Amount of income: " << sumIncome << "\n";
	}
	else {
		cout << "Not found (\n";
	}
}

void countingMoney::amountOfExpenses() {
	if (sizeCosts > 0) {
		float sumCosts = 0;
		for (int i = 0; i < sizeCosts; i++) {
			sumCosts += costs.at( i ).money;
		}

		cout << "Amount of expenses: " << sumCosts << "\n";
	}
	else {
		cout << "Not found (\n";
	}
}

void countingMoney::maximumIncome() {
	if (sizeIncome > 0) {
		group minIncome = income.at( 0 );

		for (int i = 0; i < sizeIncome; i++) {
			if (minIncome.money < income.at( i ).money) {
				minIncome = income.at( i );
			}
		}

		cout << "Maximum income: " << minIncome.money << " : " << minIncome.desc << "\n";
	}
	else {
		cout << "Not found (\n";
	}
}

void countingMoney::maximumFlow() {
	if (sizeCosts > 0) {
		group minCosts = costs.at( 0 );

		for (int i = 0; i < sizeCosts; i++) {
			if (minCosts.money > costs.at( i ).money) {
				minCosts = costs.at( i );
			}
		}

		cout << "Maximum flow: " << minCosts.money << " : " << minCosts.desc << "\n";
	}
	else {
		cout << "Not found (\n";
	}
}

void countingMoney::checkAllTransaction() {
	if (sizeIncome > 0) {
		for (int i = 0; i < sizeIncome; i++) {
			cout << income.at( i ).money << " : " << income.at( i ).money << "\n";
		}
	}

	if (sizeCosts > 0) {
		for (int i = 0; i < sizeCosts; i++) {
			cout << costs.at( i ).money << " : " << costs.at( i ).money << "\n";
		}
	}
}

