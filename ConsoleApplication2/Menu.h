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
	
	void ask_position_and_word(Puzzle*);

	bool get_dictionary();


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
};

