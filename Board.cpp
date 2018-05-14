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


	board[line_size][1 + 2*column_size];
	board[0].push_back(' ');

	for (unsigned int i = 0; i < line_size; i++) {
		board[0].push_back(char(32));
		board[0].push_back(char(97 + i));
	}
	for (unsigned int i = 0; i < column_size; i++) {
			board[i].push_back(char(65 + i));
	}
}

void Board::show_puzzle() {
	for (unsigned int y = 0; y < board.size(); y++){
		for (unsigned int x = 0; x < board[0].size(); x++){
			cout << board[y][x];
		}
		cout << endl;
	}
}

Board::~Board(){
	//save the board and exit
}
