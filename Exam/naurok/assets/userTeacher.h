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

struct question {
	int id;
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
	fstream testQuestion;
	fstream testQuestionTemp;

	int quantityQ(string testName);
	question addQuestion( int id, string nameTest );
	bool delQuestion( int id, string nameTest );
	void allQuestion( string nameTest );

public:
	bool createTest();
	bool startTest();
};

