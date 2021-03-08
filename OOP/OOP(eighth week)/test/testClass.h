#pragma once
#include <string>

using namespace std;

struct answer {
	string data;
	int weight;
};

class testClass {
	int id = 0;
	string qestion;
	answer *answers;
	bool isActive;

public:
	testClass();

	void createTest();
	void printTask();
	void printTasks();
	void writeTask();
	void copyTask();
	void changeAccess();

	~testClass();
};

