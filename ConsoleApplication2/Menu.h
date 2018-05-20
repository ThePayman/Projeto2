#pragma once
#include "iostream"
#include "fstream"
#include "string"
#include "vector"
#include "Dictionary.h"
#include "Puzzle.h"
#include "Board.h"
#include "Menu.h"

using namespace std;

class Menu
{
public:
	Menu();

	void Selection();
	
	void ask_position_and_word();
	bool ask_puzzle_options();
	ifstream get_input_file();
	ofstream *get_output_file();
	bool get_dictionary();
	bool get_board_file();
	pair<int,int> get_board_size();
	ifstream* board_file;
	void static trow_error(string error);
	void static trow_error(int error);

	~Menu();

	Puzzle* puzzle;
	Board* board;
	Dictionary* dictionary;

private:
	string option;
	string position;
	string word;
	string dictionary_file_name;
	ifstream* dictionary_file;
	string board_file_name;
	puzzle_word puzzle_word;
};

