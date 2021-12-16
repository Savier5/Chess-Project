#include<windows.h>
#include "board.h"
#include "pieceInfo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string arr[ROWS][COLS];
int xSearch;
int ySearch;
string xYSearch = "";
string tempString = "";
string tempString2 = "";
string tempString3 = "";
bool endGame = false;
int exShow = 8;
string pieceSelected;
bool tempBool = false;
bool tempBool2 = true;
int tempInt = 0;
int tempInt2 = 0;
int row, col;
pieceInfo pieces[2][8];
int i = 1;
int i2 = 1;
int itw = 1;
int newGame = 0;

struct tempCache {
	int x;
	int y;
	string numShow;
	string numString;
	int numInt;
};

void board::legalMoves()
{
	
	tempCache tC[64];

	for (int i = 0; i < 64; i++)
	{
		stringstream ss;
		ss << i2;
		string newString = ss.str();

		if (i > 9)
		{
			tC[i].numShow = newString + " ";
		}
		else {
		
			tC[i].numShow = " " + newString + " ";
		}

		tC[i].numString = newString;
		i2++;
	}
	i2 = 1;

	for (int i = 0; i < 64; i++) {
		tC[i].numInt = i + 1;
	}

	pieces[0][0].setName("RK1");
	pieces[0][1].setName("KT1");
	pieces[0][2].setName("BP1");
	pieces[0][3].setName("QN1");
	pieces[0][4].setName("KG1");
	pieces[0][5].setName("BP2");
	pieces[0][6].setName("KT2");
	pieces[0][7].setName("RK2");
	pieces[1][0].setName("PN1");
	pieces[1][1].setName("PN2");
	pieces[1][2].setName("PN3");
	pieces[1][3].setName("PN4");
	pieces[1][4].setName("PN5");
	pieces[1][5].setName("PN6");
	pieces[1][6].setName("PN7");
	pieces[1][7].setName("PN8");

	do
	{
		endGame = false;

	//Initialize array with empty spaces
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			arr[r][c] = "   ";
		}
	}

	//Placing the pieces
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < 2; c++)
		{
			arr[r][c] = pieces[c][r].getName();
		}
	}

	do {

		for (int i = 0; i < 64; i++) {
			tC[i].x = NULL;
		}

		for (int i = 0; i < 64; i++) {
			tC[i].y = NULL;
		}

		if (system("CLS")) {
			system("clear");
		}

		showBoard();

		cout << "\nType coordinates to move it, -1 to start a new game or 999 to quit the game: ";


		getline(cin, xYSearch);


		if(xYSearch == "-1"){

			endGame = true;
		}
		else if (endGame == true) {
			newGame = -1;
			endGame = true;
			tempBool = true;
		}
		else if (xYSearch == "999") {
			newGame = -1;
			endGame = true;
			tempBool = true;
		}
		else if (xYSearch[1] == '1' && xYSearch[2] == '0') {


			while (xYSearch.length() != 3) {
				cout << "Error: Type coordinates to move it or 999 to quit the game: ";
				cin >> xYSearch;
			}
		}
		else {

			while (xYSearch.length() != 2) {
				cout << "Error: Type coordinates to move it or 999 to quit the game: ";
				cin >> xYSearch;
				if (xYSearch == "999") {
					endGame = true;
				}
			}


			while ((xYSearch[0] != 'A' && xYSearch[0] != 'a') && (xYSearch[0] != 'B' && xYSearch[0] != 'b') && (xYSearch[0] != 'C' && xYSearch[0] != 'c') && (xYSearch[0] != 'D' && xYSearch[0] != 'd') && (xYSearch[0] != 'E' && xYSearch[0] != 'e') && (xYSearch[0] != 'F' && xYSearch[0] != 'f') && (xYSearch[0] != 'G' && xYSearch[0] != 'g') && (xYSearch[0] != 'H' && xYSearch[0] != 'h') && (xYSearch[0] != 'I' && xYSearch[0] != 'i') && (xYSearch[0] != 'J' && xYSearch[0] != 'j')) {
				cout << "Error: Type coordinates to move it or 999 to quit the game: ";
				cin >> xYSearch;
				if (xYSearch == "999") {
					endGame = true;
				}
			}



			while (xYSearch[1] >= 1 && xYSearch[1] <= 9) {
				cout << "Error: Type coordinates to move it or 999 to quit the game: ";
				cin >> xYSearch;
				if (xYSearch == "999") {
					endGame = true;
				}
			}
		}

		if (xYSearch == "-1" || xYSearch == "999")
		{

		}else{


		if (xYSearch[0] == 'A' || xYSearch[0] == 'a') {

			xSearch = 0;
		}
		else if (xYSearch[0] == 'B' || xYSearch[0] == 'b') {

			xSearch = 1;
		}
		else if (xYSearch[0] == 'C' || xYSearch[0] == 'c') {

			xSearch = 2;
		}
		else if (xYSearch[0] == 'D' || xYSearch[0] == 'd') {

			xSearch = 3;
		}
		else if (xYSearch[0] == 'E' || xYSearch[0] == 'e') {

			xSearch = 4;
		}
		else if (xYSearch[0] == 'F' || xYSearch[0] == 'f') {

			xSearch = 5;
		}
		else if (xYSearch[0] == 'G' || xYSearch[0] == 'g') {

			xSearch = 6;
		}
		else if (xYSearch[0] == 'H' || xYSearch[0] == 'h') {

			xSearch = 7;
		}
		else if (xYSearch[0] == 'I' || xYSearch[0] == 'i') {

			xSearch = 8;
		}
		else if (xYSearch[0] == 'J' || xYSearch[0] == 'j') {

			xSearch = 9;
		}


		if (xYSearch[1] == '1') {

			ySearch = 0;
		}
		else if (xYSearch[1] == '2') {

			ySearch = 1;
		}
		else if (xYSearch[1] == '3') {

			ySearch = 2;
		}
		else if (xYSearch[1] == '4') {

			ySearch = 3;
		}
		else if (xYSearch[1] == '5') {

			ySearch = 4;
		}
		else if (xYSearch[1] == '6') {

			ySearch = 5;
		}
		else if (xYSearch[1] == '7') {

			ySearch = 6;
		}
		else if (xYSearch[1] == '8') {

			ySearch = 7;
		}
		else if (xYSearch[1] == '9') {

			ySearch = 8;
		}

		if (system("CLS")) {
			system("clear");
		}

		tempInt = 0;
		tempBool = false;
		cout << "" << arr[xSearch][ySearch] << " selected, legal moves are:\n";


		if (arr[xSearch][ySearch][0] == 'P' && arr[xSearch][ySearch][1] == 'N') {

			if (ySearch == 1)
			{
				tC[0].x = xSearch;
				tC[0].y = ySearch + 1;
				tC[1].x = xSearch;
				tC[1].y = ySearch + 2;
				arr[tC[0].x][tC[0].y] = tC[0].numShow;
				arr[tC[1].x][tC[1].y] = tC[1].numShow;


				showBoard();

				arr[tC[0].x][tC[0].y] = "   ";
				arr[tC[1].x][tC[1].y] = "   ";

				cout << "Select where to move: ";

				while (tempString != "1" && tempString != "2")
				{
					getline(cin, tempString);

					if (tempString == "1")
					{
						tempString = arr[xSearch][ySearch];
						arr[tC[0].x][tC[0].y] = tempString;
						arr[xSearch][ySearch] = "   ";
						tempString = "1";
					}
					else if (tempString == "2")
					{
						tempString = arr[xSearch][ySearch];
						arr[tC[1].x][tC[1].y] = tempString;
						arr[xSearch][ySearch] = "   ";
						tempString = "2";
					}
					else
					{
						cout << "Error: Wrong move, select where to move: ";
					}
				}
				tempString = "";
			}
			else
			{
				tC[0].x = xSearch;
				tC[0].y = ySearch + 1;
				arr[tC[0].x][tC[0].y] = tC[0].numShow;

				showBoard();

				arr[tC[0].x][tC[0].y] = "   ";

				cout << "Select where to move: ";

				while (tempString != "1")
				{
					getline(cin, tempString);

					if (tempString == "1")
					{
						tempString = arr[xSearch][ySearch];
						arr[tC[0].x][tC[0].y] = tempString;
						arr[xSearch][ySearch] = "   ";
						tempString = "1";
					}
					else
					{
						cout << "Error: Wrong move, select where to move: ";
					}
				}
				tempString = "";
			}
		}
		else if (arr[xSearch][ySearch][0] == 'R' && arr[xSearch][ySearch][1] == 'K') {

			i = 1;
			i2 = 1;
			tempInt = 1;

			//Move up
			while (i <= 7)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch; col = ySearch + i2;
				if (col < 8 && arr[row][col] != "   ") {
					i = 7;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			//Move right
			while (i <= 14)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch + i2; col = ySearch;
				if (col < 8 && arr[row][col] != "   ") {
					i = 14;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			//Move down
			while (i <= 21)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch; col = ySearch - i2;
				if (col < 8 && arr[row][col] != "   ") {
					i = 21;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			//Move left
			while (i <= 28)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch - i2; col = ySearch;
				if (col < 8 && arr[row][col] != "   ") {
					i = 28;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			showBoard();

			i = 1;
			i2 = 1;
			tempInt = 1;
			tempString = "";
			tempBool = false;

			for (int r = 0; r < ROWS; r++)
			{
				for (int c = 0; c < COLS; c++)
				{
					tempString3 = arr[r][c];
					if (arr[r][c] == (" 1 "))
					{
						tempBool2 = true;
						c = COLS;
						r = ROWS;
					}
					else
					{
						tempBool2 = false;
					}
				}
			}

			if (tempBool2 == false)
			{
				cout << "No legal moves, to continue type anything: ";
				getline(cin, tempString);
			}
			else
			{
				cout << "\nSelect where to move: ";

				while (tempBool == false)
				{
					getline(cin, tempString);

					for (int i = 0; i < 64; i++)
					{
						if (tC[i].numString == tempString)
						{
							tempString2 = arr[xSearch][ySearch];
							arr[xSearch][ySearch] = "   ";

							for (int r = 0; r < ROWS; r++)
							{
								for (int c = 0; c < COLS; c++)
								{
									tempString3 = arr[r][c];
									if (arr[r][c] == (" " + tC[i].numString + " "))
									{
										arr[r][c] = tempString2;
									}
									else if (arr[r][c] == (tC[i].numString + " "))
									{
										arr[r][c] = tempString2;
									}
									else if (tempString3 != "RK1" && tempString3 != "KT1" && tempString3 != "BP1" && tempString3 != "QN1" && tempString3 != "KG1" && tempString3 != "BP2" && tempString3 != "KT2" && tempString3 != "RK2" && tempString3 != "PN1" && tempString3 != "PN2" && tempString3 != "PN3" && tempString3 != "PN4" && tempString3 != "PN5" && tempString3 != "PN6" && tempString3 != "PN7" && tempString3 != "PN8")
									{
										arr[r][c] = "   ";
									}
								}
							}
							i == 64;
							tempBool = true;
						}
						else if (tempBool == false)
						{
							cout << tempString << "Error: Wrong move, select where to move: ";
						}
					}
				}
			}
			tempBool = false;
			tempBool2 = true;
			tempString = "";
		}
		else if (arr[xSearch][ySearch][0] == 'K' && arr[xSearch][ySearch][1] == 'T') {

			tempInt = 1;
			i = 1;

			stringstream ss;
			ss << tempInt;
			string newString = ss.str();

			// to move up
			row = xSearch - 2; col = ySearch + 1;
			if (col < 8 && arr[row][col] != "   ") {
			}
			else if (row >= 0 && row < 8 && col >= 0 && col < 8)
			{
				cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
				if (newString.length() >= 2)
				{
					arr[row][col] = newString + " ";
				}
				else {
					arr[row][col] = " " + newString + " ";
				}
				tC[i - 1].x = row;
				tC[i - 1].y = col;
				tempInt++;
			}
			i++;
			
			stringstream ss2;
			ss2 << tempInt;
			string newString2 = ss2.str();

			row = xSearch - 1; col = ySearch + 2;
			if (col < 8 && arr[row][col] != "   ") {
			}
			else if (row >= 0 && row < 8 && col >= 0 && col < 8)
			{
				cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
				if (newString2.length() >= 2)
				{
					arr[row][col] = newString2 + " ";
				}
				else {
					arr[row][col] = " " + newString2 + " ";
				}
				tC[i - 1].x = row;
				tC[i - 1].y = col;
				tempInt++;
			}
			i++;
			stringstream ss3;
			ss3 << tempInt;
			string newString3 = ss3.str();

			// to move right
			row = xSearch + 1; col = ySearch + 2;
			if (col < 8 && arr[row][col] != "   ") {
			}
			else if (row >= 0 && row < 8 && col >= 0 && col < 8)
			{
				cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
				if (newString3.length() >= 2)
				{
					arr[row][col] = newString3 + " ";
				}
				else {
					arr[row][col] = " " + newString3 + " ";
				}
				tC[i - 1].x = row;
				tC[i - 1].y = col;
				tempInt++;
			}
			i++;
			stringstream ss4;
			ss4 << tempInt;
			string newString4 = ss4.str();

			row = xSearch + 2; col = ySearch + 1;
			if (col < 8 && arr[row][col] != "   ") {
			}
			else if (row >= 0 && row < 8 && col >= 0 && col < 8)
			{
				cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
				if (newString4.length() >= 2)
				{
					arr[row][col] = newString4 + " ";
				}
				else {
					arr[row][col] = " " + newString4 + " ";
				}
				tC[i - 1].x = row;
				tC[i - 1].y = col;
				tempInt++;
			}
			i++;
			stringstream ss5;
			ss5 << tempInt;
			string newString5 = ss5.str();

			// to move down
			row = xSearch + 2; col = ySearch - 1;
			if (col < 8 && arr[row][col] != "   ") {
			}
			else if (row >= 0 && row < 8 && col >= 0 && col < 8)
			{
				cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
				if (newString5.length() >= 2)
				{
					arr[row][col] = newString5 + " ";
				}
				else {
					arr[row][col] = " " + newString5 + " ";
				}
				tC[i - 1].x = row;
				tC[i - 1].y = col;
				tempInt++;
			}
			i++;
			stringstream ss6;
			ss6 << tempInt;
			string newString6 = ss6.str();

			row = xSearch + 1; col = ySearch - 2;
			if (col < 8 && arr[row][col] != "   ") {
			}
			else if (row >= 0 && row < 8 && col >= 0 && col < 8)
			{
				cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
				if (newString6.length() >= 2)
				{
					arr[row][col] = newString6 + " ";
				}
				else {
					arr[row][col] = " " + newString6 + " ";
				}
				tC[i - 1].x = row;
				tC[i - 1].y = col;
				tempInt++;
			}
			i++;
			stringstream ss7;
			ss7 << tempInt;
			string newString7 = ss7.str();

			// to move left
			row = xSearch - 1; col = ySearch - 2;
			if (col < 8 && arr[row][col] != "   ") {
			}
			else if (row >= 0 && row < 8 && col >= 0 && col < 8)
			{
				cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
				if (newString7.length() >= 2)
				{
					arr[row][col] = newString7 + " ";
				}
				else {
					arr[row][col] = " " + newString7 + " ";
				}
				tC[i - 1].x = row;
				tC[i - 1].y = col;
				tempInt++;
			}
			i++;
			stringstream ss8;
			ss8 << tempInt;
			string newString8 = ss8.str();

			row = xSearch - 2; col = ySearch - 1;
			if (col < 8 && arr[row][col] != "   ") {
			}
			else if (row >= 0 && row < 8 && col >= 0 && col < 8)
			{
				cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
				if (newString8.length() >= 2)
				{
					arr[row][col] = newString8 + " ";
				}
				else {
					arr[row][col] = " " + newString8 + " ";
				}
				tC[i - 1].x = row;
				tC[i - 1].y = col;
				tempInt++;
			}
			i++;

			showBoard();

			i = 1;
			i2 = 1;
			tempInt = 1;
			tempString = "";
			tempBool = false;

			for (int r = 0; r < ROWS; r++)
			{
				for (int c = 0; c < COLS; c++)
				{
					tempString3 = arr[r][c];
					if (arr[r][c] == (" 1 "))
					{
						tempBool2 = true;
						c = COLS;
						r = ROWS;
					}
					else
					{
						tempBool2 = false;
					}
				}
			}

			if (tempBool2 == false)
			{
				cout << "No legal moves, to continue type anything: ";
				getline(cin, tempString);
			}
			else
			{
				cout << "\nSelect where to move: ";

				while (tempBool == false)
				{
					getline(cin, tempString);

					for (int i = 0; i < 64; i++)
					{
						if (tC[i].numString == tempString)
						{
							tempString2 = arr[xSearch][ySearch];
							arr[xSearch][ySearch] = "   ";

							for (int r = 0; r < ROWS; r++)
							{
								for (int c = 0; c < COLS; c++)
								{
									tempString3 = arr[r][c];
									if (arr[r][c] == (" " + tC[i].numString + " "))
									{
										arr[r][c] = tempString2;
									}
									else if (arr[r][c] == (tC[i].numString + " "))
									{
										arr[r][c] = tempString2;
									}
									else if (tempString3 != "RK1" && tempString3 != "KT1" && tempString3 != "BP1" && tempString3 != "QN1" && tempString3 != "KG1" && tempString3 != "BP2" && tempString3 != "KT2" && tempString3 != "RK2" && tempString3 != "PN1" && tempString3 != "PN2" && tempString3 != "PN3" && tempString3 != "PN4" && tempString3 != "PN5" && tempString3 != "PN6" && tempString3 != "PN7" && tempString3 != "PN8")
									{
										arr[r][c] = "   ";
									}
								}
							}
							i == 64;
							tempBool = true;
						}
						else if (tempBool == false)
						{
							cout << tempString << "Error: Wrong move, select where to move: ";
						}
					}
				}
			}
			tempBool = false;
			tempBool2 = true;
			tempString = "";

		}
		else if (arr[xSearch][ySearch][0] == 'B' && arr[xSearch][ySearch][1] == 'P') {

			i = 1;
			i2 = 1;
			tempInt = 1;

			//Move up
			while (i <= 7)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch + i2; col = ySearch + i2;
				if (col < 8 && arr[row][col] != "   ") {
					i = 7;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			//Move right
			while (i <= 14)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch + i2; col = ySearch - i2;
				if (col < 8 && arr[row][col] != "   ") {
					i = 14;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			//Move down
			while (i <= 21)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch - i2; col = ySearch - i2;
				if (col < 8 && arr[row][col] != "   ") {
					i = 21;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			//Move left
			while (i <= 28)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch - i2; col = ySearch + i2;
				if (col < 8 && arr[row][col] != "   ") {
					i = 28;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			showBoard();

			i = 1;
			i2 = 1;
			tempInt = 1;
			tempString = "";
			tempBool = false;

			for (int r = 0; r < ROWS; r++)
			{
				for (int c = 0; c < COLS; c++)
				{
					tempString3 = arr[r][c];
					if (arr[r][c] == (" 1 "))
					{
						tempBool2 = true;
						c = COLS;
						r = ROWS;
					}
					else
					{
						tempBool2 = false;
					}
				}
			}

			if (tempBool2 == false)
			{
				cout << "No legal moves, to continue type anything: ";
				getline(cin, tempString);
			}
			else
			{
				cout << "\nSelect where to move: ";

				while (tempBool == false)
				{
					getline(cin, tempString);

					for (int i = 0; i < 64; i++)
					{
						if (tC[i].numString == tempString)
						{
							tempString2 = arr[xSearch][ySearch];
							arr[xSearch][ySearch] = "   ";

							for (int r = 0; r < ROWS; r++)
							{
								for (int c = 0; c < COLS; c++)
								{
									tempString3 = arr[r][c];
									if (arr[r][c] == (" " + tC[i].numString + " "))
									{
										arr[r][c] = tempString2;
									}
									else if (arr[r][c] == (tC[i].numString + " "))
									{
										arr[r][c] = tempString2;
									}
									else if (tempString3 != "RK1" && tempString3 != "KT1" && tempString3 != "BP1" && tempString3 != "QN1" && tempString3 != "KG1" && tempString3 != "BP2" && tempString3 != "KT2" && tempString3 != "RK2" && tempString3 != "PN1" && tempString3 != "PN2" && tempString3 != "PN3" && tempString3 != "PN4" && tempString3 != "PN5" && tempString3 != "PN6" && tempString3 != "PN7" && tempString3 != "PN8")
									{
										arr[r][c] = "   ";
									}
								}
							}
							i == 64;
							tempBool = true;
						}
						else if (tempBool == false)
						{
							cout << tempString << "Error: Wrong move, select where to move: ";
						}
					}
				}
			}
			tempBool = false;
			tempBool2 = true;
			tempString = "";

		}
		else if (arr[xSearch][ySearch][0] == 'Q' && arr[xSearch][ySearch][1] == 'N') {

			i = 1;
			i2 = 1;
			tempInt = 1;

			//Move up
			while (i <= 7)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch; col = ySearch + i2;
				if (col < 8 && arr[row][col] != "   ") {
					i = 7;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			//Move up
			while (i <= 14)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch + i2; col = ySearch + i2;
				if (col < 8 && arr[row][col] != "   ") {
					i = 14;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			//Move right
			while (i <= 21)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch + i2; col = ySearch;
				if (col < 8 && arr[row][col] != "   ") {
					i = 21;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			//Move right
			while (i <= 28)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch + i2; col = ySearch - i2;
				if (col < 8 && arr[row][col] != "   ") {
					i = 28;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			//Move down
			while (i <= 35)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch; col = ySearch - i2;
				if (col < 8 && arr[row][col] != "   ") {
					i = 35;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			//Move down
			while (i <= 42)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch - i2; col = ySearch - i2;
				if (col < 8 && arr[row][col] != "   ") {
					i = 42;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			//Move left
			while (i <= 49)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch - i2; col = ySearch;
				if (col < 8 && arr[row][col] != "   ") {
					i = 49;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			//Move left
			while (i <= 56)
			{
				stringstream ss;
				ss << tempInt;
				string newString = ss.str();

				row = xSearch - i2; col = ySearch + i2;
				if (col < 8 && arr[row][col] != "   ") {
					i = 56;
				}
				else if (row >= 0 && row < 8 && col >= 0 && col < 8)
				{
					cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
					if (newString.length() >= 2)
					{
						arr[row][col] = newString + " ";
					}
					else {

						arr[row][col] = " " + newString + " ";

					}
					tC[i - 1].x = row;
					tC[i - 1].y = col;
					tempInt++;
				}
				i++;
				i2++;
			}
			i2 = 1;

			showBoard();

			i = 1;
			i2 = 1;
			tempInt = 1;
			tempString = "";
			tempBool = false;

			for (int r = 0; r < ROWS; r++)
			{
				for (int c = 0; c < COLS; c++)
				{
					tempString3 = arr[r][c];
					if (arr[r][c] == (" 1 "))
					{
						tempBool2 = true;
						c = COLS;
						r = ROWS;
					}
					else
					{
						tempBool2 = false;
					}
				}
			}

			if (tempBool2 == false)
			{
				cout << "No legal moves, to continue type anything: ";
				getline(cin, tempString);
			}
			else
			{
				cout << "\nSelect where to move: ";

				while (tempBool == false)
				{
					getline(cin, tempString);

					for (int i = 0; i < 64; i++)
					{
						if (tC[i].numString == tempString)
						{
							tempString2 = arr[xSearch][ySearch];
							arr[xSearch][ySearch] = "   ";

							for (int r = 0; r < ROWS; r++)
							{
								for (int c = 0; c < COLS; c++)
								{
									tempString3 = arr[r][c];
									if (arr[r][c] == (" " + tC[i].numString + " "))
									{
										arr[r][c] = tempString2;
									}
									else if (arr[r][c] == (tC[i].numString + " "))
									{
										arr[r][c] = tempString2;
									}
									else if (tempString3 != "RK1" && tempString3 != "KT1" && tempString3 != "BP1" && tempString3 != "QN1" && tempString3 != "KG1" && tempString3 != "BP2" && tempString3 != "KT2" && tempString3 != "RK2" && tempString3 != "PN1" && tempString3 != "PN2" && tempString3 != "PN3" && tempString3 != "PN4" && tempString3 != "PN5" && tempString3 != "PN6" && tempString3 != "PN7" && tempString3 != "PN8")
									{
										arr[r][c] = "   ";
									}
								}
							}
							i == 64;
							tempBool = true;
						}
						else if (tempBool == false)
						{
							cout << tempString << "Error: Wrong move, select where to move: ";
						}
					}
				}
			}
			tempBool = false;
			tempBool2 = true;
			tempString = "";

		}
		else if (arr[xSearch][ySearch][0] == 'K' && arr[xSearch][ySearch][1] == 'G') {

		i = 1;
		i2 = 1;
		tempInt = 1;
		int s = 0;

		//Move up
		while (i <= 2)
		{
			stringstream ss;
			ss << tempInt;
			string newString = ss.str();

			if (s == 0)
			{
				row = xSearch; col = ySearch + i2;
				s++;
			}
			else {
				row = xSearch + i2; col = ySearch + i2;
			}

			if (col < 8 && arr[row][col] != "   ") {
			
			}
			else if (row >= 0 && row < 8 && col >= 0 && col < 8)
			{
				cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
				if (newString.length() >= 2)
				{
					arr[row][col] = newString + " ";
				}
				else {

					arr[row][col] = " " + newString + " ";

				}
				tC[i - 1].x = row;
				tC[i - 1].y = col;
				tempInt++;
			}
			i++;
		}
		i2 = 1;
		s = 0;

		//Move right
		while (i <= 4)
		{
			stringstream ss;
			ss << tempInt;
			string newString = ss.str();

			if (s == 0)
			{
				row = xSearch + i2; col = ySearch;
				s++;
			}
			else {
				row = xSearch + i2; col = ySearch - i2;
			}

			if (col < 8 && arr[row][col] != "   ") {
				
			}
			else if (row >= 0 && row < 8 && col >= 0 && col < 8)
			{
				cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
				if (newString.length() >= 2)
				{
					arr[row][col] = newString + " ";
				}
				else {

					arr[row][col] = " " + newString + " ";

				}
				tC[i - 1].x = row;
				tC[i - 1].y = col;
				tempInt++;
			}
			i++;
		}
		i2 = 1;
		s = 0;

		//Move down
		while (i <= 6)
		{
			stringstream ss;
			ss << tempInt;
			string newString = ss.str();

			if (s == 0)
			{
				row = xSearch; col = ySearch - i2;
				s++;
			}
			else {
				row = xSearch - i2; col = ySearch - i2;
			}

			if (col < 8 && arr[row][col] != "   ") {
				
			}
			else if (row >= 0 && row < 8 && col >= 0 && col < 8)
			{
				cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
				if (newString.length() >= 2)
				{
					arr[row][col] = newString + " ";
				}
				else {

					arr[row][col] = " " + newString + " ";

				}
				tC[i - 1].x = row;
				tC[i - 1].y = col;
				tempInt++;
			}
			i++;
		}
		i2 = 1;
		s = 0;

		//Move left
		while (i <= 8)
		{
			stringstream ss;
			ss << tempInt;
			string newString = ss.str();

			if (s == 0)
			{
				row = xSearch - i2; col = ySearch;
				s++;
			}
			else {
				row = xSearch - i2; col = ySearch + i2;
			}

			if (col < 8 && arr[row][col] != "   ") {
				
			}
			else if (row >= 0 && row < 8 && col >= 0 && col < 8)
			{
				cout << tC[tempInt - 1].numInt << ". board: " << numToLetter() << col + 1 << "\n";
				if (newString.length() >= 2)
				{
					arr[row][col] = newString + " ";
				}
				else {

					arr[row][col] = " " + newString + " ";

				}
				tC[i - 1].x = row;
				tC[i - 1].y = col;
				tempInt++;
			}
			i++;
		}
		i2 = 1;
		s = 0;

		showBoard();

		i = 1;
		i2 = 1;
		tempInt = 1;
		tempString = "";
		tempBool = false;

		for (int r = 0; r < ROWS; r++)
		{
			for (int c = 0; c < COLS; c++)
			{
				tempString3 = arr[r][c];
				if (arr[r][c] == (" 1 "))
				{
					tempBool2 = true;
					c = COLS;
					r = ROWS;
				}
				else
				{
					tempBool2 = false;
				}
			}
		}

		if (tempBool2 == false)
		{
			cout << "No legal moves, to continue type anything: ";
			getline(cin, tempString);
		}
		else
		{
			cout << "\nSelect where to move: ";

			while (tempBool == false)
			{
				getline(cin, tempString);

				for (int i = 0; i < 64; i++)
				{
					if (tC[i].numString == tempString)
					{
						tempString2 = arr[xSearch][ySearch];
						arr[xSearch][ySearch] = "   ";

						for (int r = 0; r < ROWS; r++)
						{
							for (int c = 0; c < COLS; c++)
							{
								tempString3 = arr[r][c];
								if (arr[r][c] == (" " + tC[i].numString + " "))
								{
									arr[r][c] = tempString2;
								}
								else if (arr[r][c] == (tC[i].numString + " "))
								{
									arr[r][c] = tempString2;
								}
								else if (tempString3 != "RK1" && tempString3 != "KT1" && tempString3 != "BP1" && tempString3 != "QN1" && tempString3 != "KG1" && tempString3 != "BP2" && tempString3 != "KT2" && tempString3 != "RK2" && tempString3 != "PN1" && tempString3 != "PN2" && tempString3 != "PN3" && tempString3 != "PN4" && tempString3 != "PN5" && tempString3 != "PN6" && tempString3 != "PN7" && tempString3 != "PN8")
								{
									arr[r][c] = "   ";
								}
							}
						}
						i == 64;
						tempBool = true;
					}
					else if (tempBool == false)
					{
						cout << tempString << "Error: Wrong move, select where to move: ";
					}
				}
			}
		}
		tempBool = false;
		tempBool2 = true;
		tempString = "";
		}


		//Resets the tempCache

		for (int i = 0; i < 64; i++) {
			tC[i].x = NULL;
		}

		for (int i = 0; i < 64; i++) {
			tC[i].y = NULL;
		}
		}

	} while (endGame != true);

	} while (newGame == 0);
}

void board::showBoard() {
	int exShow = 8;
	//Show the array current position on the board

	for (int c = 7; c >= 0; c--)
	{
		cout << "\n					    ---------------------------------\n";
		cout << "					  " << exShow << " |";

		for (int r = 0; r < ROWS; r++)
		{
			cout << arr[r][c] << "|";
		}
		exShow--;
	}
	exShow = 8;
	cout << "\n					    ---------------------------------";
	cout << "\n					      A   B   C   D   E   F   G   H" << endl << endl;
}

char board::numToLetter() {
	char string1;

	if (row == 0) {

		string1 = 'A';
	}
	else if (row == 1) {

		string1 = 'B';
	}
	else if (row == 2) {

		string1 = 'C';
	}
	else if (row == 3) {

		string1 = 'D';
	}
	else if (row == 4) {

		string1 = 'E';
	}
	else if (row == 5) {

		string1 = 'F';
	}
	else if (row == 6) {

		string1 = 'G';
	}
	else if (row == 7) {

		string1 = 'H';
	}
	else if (row == 8) {

		string1 = 'I';
	}
	else if (row == 9) {

		string1 = 'J';
	}

	return string1;
}