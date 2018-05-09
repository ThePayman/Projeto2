#include "stdafx.h"
#include "Puzzle.h"
#include "Dictionary.h"
/*
Class Puzzle {
create(size_x,size_y,name,vector<puzzle_word> load = none) -- O load permite carregar um puzzle pre criado
insert(puzzle_word word) -- Utiliza o check_word para ver se cabe e depois insere e poem pretos
check_word(puzzle_word word) -- Verifica se a palavra cabe
possible_words() -- Pega em palavras random ate encaixar 10 com o check_word
fill() -- Enche o puzzle com pretos
verify() -- Verifica que todas as palavras existem e estao colocadas corretamente

static save(puzzle,file) -- Salva o board para um ficheiro
static load(file) -- Cria um vector<puzzle_word> com todas as palavras, para passar ao create()

vector<puzzle_word> puzzle_words
vector<vector<char>> puzzle_2d_vector
}
*/
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
	if (!check_word(word)) return false;
	vector<vector<char>> new_two_d_puzzle_vector = two_d_puzzle_vector;
	for (int i = 0; i < word.word_string.size(); i++) {
		char selected_vector_position = new_two_d_puzzle_vector[x_index][y_index];

		if (selected_vector_position != word.word_string[i] && selected_vector_position != ' ') return false;
		else {
			new_two_d_puzzle_vector[x_index][y_index] = word.word_string[i];
		}
		if (word.direction == 'H') x_index++;
		else if (word.direction == 'V') y_index++;
	}

	two_d_puzzle_vector = new_two_d_puzzle_vector;
	puzzle_word_vector.push_back(word);
	return true;
}

bool Puzzle::check_word(puzzle_word word) {
	int x_index = word.positionX - 'A';
	int y_index = word.positionY - 'a';
	if (word.direction == 'H') {
		if (x_index + word.word_string.size() > size_x) return false;
	}
	if (word.direction == 'V') {
		if (y_index + word.word_string.size() > size_y) return false;
	}
	for (int i = 0; i < word.word_string.size(); i++) {
		char selected_vector_position = two_d_puzzle_vector[x_index][y_index];
		if (selected_vector_position != word.word_string[i] && selected_vector_position != ' ') return false;
		if (word.direction == 'H') x_index++;
		else if (word.direction == 'V') y_index++;
	}
	return true;
}

vector<puzzle_word> Puzzle::possible_words(vector<string> dictionary_words) {
	//pode so receber o vetor de palavras
	vector<puzzle_word> words;
	while (words.size() < 10) {
		int random_x = rand() % size_x - 1;
		int random_y = rand() % size_y - 1;
		int random_direction = rand() % 1;
		if (isalpha(two_d_puzzle_vector[random_x][random_y])) {
			char initial_letter = two_d_puzzle_vector[random_x][random_y];
			for (const string dictionary_word : dictionary_words) {
				if (dictionary_word[0] == initial_letter) {
					//Get a random word to test
					string random_word = "";//
					puzzle_word new_puzzle_word;
					new_puzzle_word.positionX = random_x;
					new_puzzle_word.positionY = random_y;
					if (random_direction) new_puzzle_word.direction = 'H';
					else random_direction = 'V';
					if (check_word(new_puzzle_word)) words.push_back(new_puzzle_word);
				}
			}
		}
	}
	return words;
}

void Puzzle::fill() {
	for (int x = 0; x < size_x; x++) {
		for (int y = 0; y < size_y; y++) {
			if (two_d_puzzle_vector[x][y] == ' ') two_d_puzzle_vector[x][y] = '#';
		}
	}
}

void Puzzle::save(Puzzle puzzle_object, ostream output_file) {
	for (const puzzle_word puzzle_word : puzzle_object.puzzle_word_vector) {
		output_file << puzzle_word.positionX << puzzle_word.positionY << puzzle_word.direction << " " << puzzle_word.word_string;
	}
}
Puzzle Puzzle::load(istream file) {
	string word;
	int i = 0;
	int size_x = 0;
	int size_y = 0;
	bool getting_2d_puzzle = false;
	bool getting_puzzle_words = false;
	vector<puzzle_word> loaded_puzzle_words;
	string dictionary_file;
	for (string line; getline(file, line); )
	{
		if (i == 0) dictionary_file = line;
		else {
			if (!line.empty()) {
				if (getting_2d_puzzle) {
					if (size_x == 0) {
						for (const char string_char : line) {
							if (string_char != ' ') size_x++;
						}
					}
					size_y++;
				}
				if (getting_puzzle_words) {
					puzzle_word new_puzzle_word;
					new_puzzle_word.positionY = line[0];
					new_puzzle_word.positionX = line[1];
					new_puzzle_word.direction = line[2];
					new_puzzle_word.word_string = line[5]; //TODO
					loaded_puzzle_words.push_back(new_puzzle_word);
				}
			}
			else {
				if (!getting_2d_puzzle && !getting_puzzle_words) getting_2d_puzzle = true;
				else if (getting_2d_puzzle && !getting_puzzle_words) {
					getting_2d_puzzle = false;
					getting_puzzle_words = true;
				}
				else if (!getting_2d_puzzle && getting_puzzle_words) {
					getting_puzzle_words = false;
				}
			}
		}
		i++;
	}
	Puzzle new_puzzle = Puzzle(size_x, size_x, "Puzzle", loaded_puzzle_words);
	return (new_puzzle);
}

