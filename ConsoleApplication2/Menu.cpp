#include "stdafx.h"
#include "Menu.h"
#include "Board.h"
#include "Dictionary.h"
#include "Puzzle.h"



Menu::Menu(){
	cout << "CROSSWORDS PUZZLE CREATOR" << endl
		<< "=========================================" << endl
		<< endl
		<< "INSTRUCTIONS:" << endl
		<< endl
		<< "Position (LCD / CTRL - Z = Stop)" << endl
		<< "LCD stands for Line, Column and Direction" << endl
		<< endl
		<< "To define a line you must:" << endl
		<< "Input the letter that marks that line, that letter must be capitalized." << endl
		<< endl
		<< "To define a column you must:" << endl
		<< "Input the letter that marks that column, that letter must be lower case." << endl
		<< endl
		<< "To define the direction you must:" << endl
		<< "Input V (capitalized) if the direction you wish is vertical or H (capitalized) if it is horizontal." << endl
		<< endl
		<< "----------------------------------------"
		<< endl;
}

void Menu::Selection() {
	cout << "Choose from the following options:" << endl
		<< "1 - Create Puzzle" << endl
		<< "2 - Resume Puzzle" << endl
		<< "0 - Exit" << endl
		<< endl
		<< "What is your option?" << endl;
	cin >> option;
	
	if (option == "1") {
		cout << "----------------------------------------" << endl
			<< "CREATE BOARD" << endl
			<< "----------------------------------------" << endl;
		
		
		//dictionary->read_dictionary();
		if(!this->get_dictionary()) return;
		//dictionary->usable_words_sort();
		board = new Board();
		board->create_board();
		board->show_board();
		
		puzzle = new Puzzle(board->line_size, board->column_size, "", dictionary);

		this->ask_position_and_word(puzzle);
		

		

	}
	else if(option == "2") {
		
	}
	else if(option == "0"){
		this->~Menu();
	}
	else {
		cout << endl;
		cout << "Invalid input, please select a valid option." << endl;
		cout << endl;
		this->Selection();
	}

}

void Menu::ask_position_and_word(Puzzle* puzzle){
	cout << "Position (LCD / CTRL-Z = stop)   ?" << endl;
	cin >> position;
	while (position != "^Z") {
		cout << "Word ( - = remove / ? = help)   ?" << endl;
		cin >> word;
		for (const char word_char : word) {
			toupper(word_char);
		}
		puzzle->insert_string(position, word);
		board->update_board(puzzle->two_d_puzzle_vector);
		board->show_board();
		this->ask_position_and_word(puzzle);
	}
}

bool Menu::get_dictionary() {
	cout << "What is the dictionary file name?" << endl;
	cin >> dictionary_file_name;
	dictionary_file = new ifstream();
	dictionary_file->open(dictionary_file_name);
	if (!dictionary_file->is_open()) {
		cout << "Invalid File" << endl;
		return this->get_dictionary();
	}
	dictionary = new Dictionary(dictionary_file);
	return true;
}

Menu::~Menu(){}
