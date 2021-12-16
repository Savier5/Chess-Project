#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include<windows.h>
using namespace std;
const int ROWS = 8;
const int COLS = 8;

class board {

private:

	const int numOfKings = 1;
	const int numOfQueens = 1;
	const int numOfRooks = 2;
	const int numOfBishop = 2;
	const int numOfKnight = 2;
	const int numOfPawn = 8;

public:

	int getNumOfKings() { return numOfKings; }
	int getNumOfQueens() { return numOfQueens; }
	int getNumOfRooks() { return numOfRooks; }
	int getNumOfBishop() { return numOfBishop; }
	int getNumOfKnight() { return numOfKnight; }
	int getNumOfPawn() { return numOfPawn; }

	void legalMoves();
	void showBoard();
	char numToLetter();
};

#endif

