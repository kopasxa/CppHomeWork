#pragma once
#include <iostream>
#include <list>
#include <string>

using namespace std;

class listClass {
	struct group {
		float money;
		string desc;
	};

	list<group> income, costs;
	float numbers = -1;
	int sizeIncome, sizeCosts;
	float balance = 0;

public:
	listClass();
	int menu();

	void amountOfIncome();
	void amountOfExpenses();
	void maximumIncome();
	void maximumFlow();

	void checkAllTransaction();
};

