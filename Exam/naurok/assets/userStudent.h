#pragma once
#include <ctime>
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

#define pathToQuestion "db/question.txt"
#define pathToResults "db/result.txt"

using namespace std;

struct questionSt {
	int id, variantQ;
	string header;

	struct answer {
		string answerStr;
		float weight = 0;
	};
	answer str;

	vector<answer> answers;
};

struct answerStudent {
	string headerQ;
	vector<string> answer;
	float appraisal = 0;
};

class userStudent {
	fstream question;
	fstream result;

	bool writeResults( vector<answerStudent> answers, string login, string testName, float appraisal );
	void printResult( vector<answerStudent> answers );
public:
	void startTest( string nameTest, string login );
};