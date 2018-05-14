#pragma once
#include "string"
#include "iostream"
#include "vector"

using namespace std;


struct puzzle_word {
	char positionX;
	char positionY;
	char direction;
	string word_string;
};

class Puzzle {
public:
	Puzzle(int size_x, int size_y, string name);
	Puzzle(int size_x, int size_y, string name, vector<puzzle_word> load_vector);
	bool insert(puzzle_word word);
	bool remove(puzzle_word word);
	bool recreate_verify_2d_vector();
	bool check_word(puzzle_word word);
	vector<puzzle_word> possible_words(vector<string> dictionary_words);
	void fill();
	static void save(Puzzle puzzle_object, ostream output_file);
	static Puzzle load(istream inputput_file);
private:
	int size_x;
	int size_y;
	string name;
	vector<vector<char>> two_d_puzzle_vector;
	vector<puzzle_word> puzzle_word_vector;
};

