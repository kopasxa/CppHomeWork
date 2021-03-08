#pragma once
#include <iostream>
#include <fstream>
#include <string>

#define MAX_PATH 256
#define MAX_ERR 22

using namespace std;

class flowF {
	char FileName[MAX_PATH];
	char err[MAX_ERR][5] = {
		"CON",
		"PRN",
		"AUX",
		"NUL",
		"COM1",
		"COM2",
		"COM3",
		"COM4",
		"COM5",
		"COM6",
		"COM7",
		"COM8",
		"COM9",
		"LPT1",
		"LPT2",
		"LPT3",
		"LPT4",
		"LPT5",
		"LPT6",
		"LPT7",
		"LPT8",
		"LPT9",
	};
	char err2[8] = { 
		'<',
		'>',
		'|',
		':',
		'/',
		'\\',
		'?',
		'*', 
	};

	bool checkErr(char checkStr[]);
	fstream outF;
	string secretKey = "agent228";

public:
	flowF();

	void write();
	void read();

	~flowF();
};

