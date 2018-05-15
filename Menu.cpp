#include "stdafx.h"
#include "Menu.h"
#include "Board.h"
#include "Dictionary.h"



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
		
		//Dictionary rosberg;
		//rosberg.read_dictionary();
		//rosberg.usable_words_sort();
		
		Board vettel;
		vettel.create_puzzle();
		vettel.show_puzzle();
	}
	else if(option == "2") {
		//Board::something2
		cout << "//Board::something2";
	}
	else if(option == "0"){
		Menu::~Menu();
	}
	else {
		cout << endl;
		cout << "Invalid input, please select a valid option." << endl;
		cout << endl;
		Menu::Selection();
	}

}


Menu::~Menu(){}
