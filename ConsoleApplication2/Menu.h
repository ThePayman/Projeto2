#pragma once
#include "iostream"
#include "fstream"
#include "string"
#include "vector"
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
	ifstream* board_file;


	~Menu();

private:
	string option;
	string position;
	string word;
	Puzzle* puzzle;
	Board* board;
	Dictionary* dictionary;
	string dictionary_file_name;
	ifstream* dictionary_file;
	string board_file_name;
	puzzle_word puzzle_word;
};

