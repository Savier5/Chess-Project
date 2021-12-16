#ifndef PIECEINFO_H
#define PIECEINFO_H
#include <iostream>
#include <string>
#include<windows.h>

using namespace std;

class pieceInfo {

private:

	string name;
	string num;
	string startingPos;

public:

	string getName() { return name; }
	void setName(string name1) { name = name1; }

	string getNum() { return num; }
	void setNum(string num1) { num = num1; }

	string getStartingPos() { return startingPos; }
	void setStartingPos(string startingPos1) { startingPos = startingPos1; }
};

#endif