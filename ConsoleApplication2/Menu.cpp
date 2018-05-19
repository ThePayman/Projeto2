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
/*
	Main Menu function. Gives general options to the user.
*/
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

		this->ask_position_and_word();
		
		return;
		

	}
	else if(option == "2") {
		cout << "----------------------------------------" << endl
			<< "EDIT LOADED BOARD" << endl
			<< "----------------------------------------" << endl;
		if (!this->get_dictionary()) return;

		if (!this->get_board_file()) return;
		
		Puzzle::load( board_file , dictionary);
		

		return;
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
/*
	Asks a position and word to insert into a position on the puzzle. Loops until EOF of Cin.
*/
void Menu::ask_position_and_word(){
	string position = "";
	while (!cin.eof()) {
		cout << "Position (LCD / CTRL-Z = stop)   ?" << endl;
		cin >> position;
		if (position.size() != 3) {
			cout << "Invalid input, please input a valid position." << endl;
			this->ask_position_and_word();
		}
		if (!(('a' <= position[0] && position[0] <= 'z') && ('A' <= position[1] && position[1] <= 'Z') && (position[2] == 'V' || position[2] == 'H'))) {
			cout << "Invalid input, please input a valid position." << endl;
			this->ask_position_and_word();
		}
		cout << "Word ( - = remove / ? = help)   ?" << endl;
		cin >> word;
		if (cin.eof()) continue;
		for (const char word_char : word) {
			toupper(word_char);
		}
		puzzle->insert_string(position, word);
		board->update_board(puzzle->two_d_puzzle_vector);
		board->show_board();
	}
	cin.clear();
	this->ask_puzzle_options();
}

/*
	Puzzle Menu function. Gives options especific to a puzzle to the user.
*/
bool Menu::ask_puzzle_options() {
	cout << "Choose from the following options:" << endl
	<< "1 - Continue editing Puzzle" << endl
	<< "2 - Save Puzzle" << endl
	<< "0 - Exit" << endl
	<< endl
	<< "What is your option?" << endl;
	cin >> option;
	if (option == "1") {
		this->ask_position_and_word();
	}
	if (option == "2") {
		//Needs to use pointers
		ofstream* save_file = get_output_file();
		puzzle->save(save_file);
	}
	if (option == "0") {
		return false;
	}
	return true;
}
/*
	Loops until a valid input file is open.
*/
ifstream Menu::get_input_file() {
	string file_name;
	cout << "What is the file name?" << endl;
	cin >> file_name;
	ifstream file;
	file.open(file_name);
	if (!file.is_open()) {
		cout << "Invalid File" << endl;
		return this->get_input_file();
	}
	return file;
}

/*
	Loops until a valid output file is open.
*/
ofstream* Menu::get_output_file() {
	string file_name;
	cout << "What is the file name?" << endl;
	cin >> file_name;
	ofstream* file = new ofstream();
	file->open(file_name);
	if (!file->is_open()) {
		cout << "Invalid File" << endl;
		return this->get_output_file();
	}
	return file;
}
#pragma endregion

/*
	Loops until a valid dictionary file is open and creates the dictionary object.
*/
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

bool Menu::get_board_file() {
	cout << "What is the board file name?" << endl;
	cin >> board_file_name;
	board_file = new ifstream();
	board_file->open(board_file_name);
	if (!board_file->is_open()) {
		cout << "Invalid File" << endl;
		return this->get_board_file();
	}
	return true;
}


Menu::~Menu(){}

