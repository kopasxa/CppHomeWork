#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define pathToTests "db/tests.txt"
#define pathToQuestion "db/question.txt"
#define pathToTestsTemp "db/testsTemp.txt"
#define pathToQuestionTemp "db/questionTemp.txt"
#define pathToResults "db/result.txt"

struct question {
	int id, variantQ;
	string header;

	struct answer {
		string answerStr;
		float weight = 0;
	};
	answer str;

	vector<answer> answers;
};

class userTeacher {
	void SetPos( int x, int y );

	fstream testFile;
	fstream testFileTemp;
	fstream testQuestion;
	fstream testQuestionTemp;
	fstream result;

	int quantityQ(string testName);
	bool delQuestion( int id, string nameTest );
	question findQ(int id);

public:
	string qById( int id );
	question addQuestion( int id, string nameTest );
	question addQuestion( question quest, string nameTest );
	question addQuestion( string nameTest );
	void qAddTo();
	void allQuestion();
	void printTests();
	bool printTests(bool trueS);
	bool changeStatusTest();
	bool createTest();
	bool readResults();
};

