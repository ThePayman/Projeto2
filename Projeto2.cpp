
#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include "vector"
#include "Dictionary.h"
#include "Menu.h"

using namespace std;



/*
class Dictionaryy {
private:
	Dictionaryy(ifstream dictionary_file);

	vector<string> possible_words = {};
	
	bool check_word(vector<string> word_list){
		for (unsigned int i = 0; i < word_list.size(); i++){
			string word;
			word = word_list[i];
			for (unsigned int a = 0; a < word.length(); a++) {
				if (word[word.length()] == ':'){
					string new_word;
					for (unsigned int i = 0; i < word.length()-1; i++){
						new_word = new_word[i];
					}
					possible_words.push_back(word)
				}
			}
		}
	}

	vector<string> list;
};*/


/*
Class Board {
	create(size_x, size_y)
		show(puzzle_2d_vector, possible_words) //Mostra no ecra
}*/

/*
struct puzzle_word {
	char positionX;
	char positionY;
	char direction;
	string word;
};

class Puzzle {
	public:
		Puzzle(int size_x, int size_y, string name);
		Puzzle(int size_x, int size_y, string name, vector<puzzle_word> load_vector);
		bool insert(puzzle_word word);
	private:
		int size_x;
		int size_y;
		string name;
		vector<vector<char>> two_d_puzzle_vector;
};

Puzzle::Puzzle(int set_size_x, int set_size_y, string set_name) {
	size_x = set_size_x;
	size_y = set_size_y;
	name = set_name;
	for (int x = 0; x < set_size_x; x++) {
		for (int y = 0; y < set_size_y; y++) {
			two_d_puzzle_vector[x][y] = ' ';
		}
	}
}

Puzzle::Puzzle(int set_size_x, int set_size_y, string set_name, vector<puzzle_word> load_vector) {
	size_x = set_size_x;
	size_y = set_size_y;
	name = set_name;
	for (int x = 0; x < set_size_x; x++) {
		for (int y = 0; y < set_size_y; y++) {
			two_d_puzzle_vector[x][y] = ' ';
		}
	}
	for (int i = 0; i < load_vector.size(); i++) {
		puzzle_word word = load_vector[i];
		this->insert(word);
	}
}

bool Puzzle::insert(puzzle_word word) {
	int x_index = word.positionX - 'a';
	int y_index = word.positionY - 'A';
	vector<vector<char>> new_two_d_puzzle_vector = two_d_puzzle_vector;
	if (word.direction == 'h') {
		for (int i = 0; i < word.word.size(); i++) {

		}
	}
}*/

/*Class Menu{
	write()
	ask()

	vector<string> options

	// Precisa de ser bem pensado, podemos dividir em varias partes
}
Struct puzzle_word{
	char positionX
	char positionY
	char direction
	string word
}

*/

int main(){

	Dictionary ricciardo;

	ricciardo.read_dictionary();
	ricciardo.usable_words_sort();

	Menu vettel;
	vettel.Selection();


	return 0;
}

