#pragma once
#include "string"
#include "iostream"
#include "vector"
#include "Dictionary.h"

using namespace std;


struct puzzle_word {
	char positionX;
	char positionY;
	char direction;
	string word_string;
};

class Puzzle {
public:
	Puzzle(unsigned int size_x, unsigned int size_y, string name, Dictionary* dictionary_object);
	Puzzle(unsigned int size_x, unsigned int size_y, string name, vector<puzzle_word> load_vector, Dictionary* dictionary_object);
	bool insert(puzzle_word word);
	bool insert_string(string puzzle_word_pos, string puzzle_word_string);
	bool remove(puzzle_word word);
	bool recreate_verify_2d_vector();
	bool check_word(puzzle_word word);
	vector<puzzle_word> possible_words();
	void fill();
	bool save(ostream output_file);
	static Puzzle load(istream inputput_file, Dictionary* dictionary_object);

	vector<vector<char>> two_d_puzzle_vector;

private:
	unsigned int size_x;
	unsigned int size_y;
	string name;
	vector<puzzle_word> puzzle_word_vector;
	Dictionary* dictionary;
};