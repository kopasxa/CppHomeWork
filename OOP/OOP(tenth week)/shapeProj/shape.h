#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class shape {
public:
	virtual void Show() = 0;
	virtual void Save() = 0;
	virtual void Load() = 0;

	~shape() = default;
};

