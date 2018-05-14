#include "stdafx.h"
#include "Board.h"


Board::Board(){
}

void Board::create_puzzle() {
	
	cout <<
		"What is the board size (lines and columns separated by a space)?" << endl;
	cin >> line_size >> column_size;
	while ( line_size <= 0 || column_size <= 0){
		cout << "Invalid board size, please input new values that are greater than 0." << endl;
		cin.clear();
		cin >> line_size >> column_size;
	}
	for (unsigned int i = 0; i < line_size; i++){	//for cicle to print the lines
		line.push_back(char(97 + i));
		for (unsigned int i = 0; i < column_size; i++) {	//for cicle to print the columns
			column.push_back(char(65 + i));
		}
	}
	for (unsigned int i = 0; i < line.size(); i++) {
		cout << line[i];
	}
	cout << endl;
	for (unsigned int i = 0; i < column.size(); i++) {
		cout << column[i] << endl;
	}
}

Board::~Board(){ //save the board and exit
}
