#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class countingMoney {
	struct group {
		float money;
		string desc;
	};
	
	vector<group> income, costs;
	float numbers = -1;
	int sizeIncome, sizeCosts;
	float balance = 0;

public:
	countingMoney();
	int menu();

	void amountOfIncome();
	void amountOfExpenses();
	void maximumIncome();
	void maximumFlow();

	void checkAllTransaction();
};

