#pragma once
#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include "vector"

using namespace std;



class Dictionary{

public:
	ifstream dictionary_file;

	//Default constructor
	Dictionary();

	//Overload constructor
	Dictionary(string);

	//Destructor
	~Dictionary();

	//Acessor functions
	vector<string> read_dictionary(ifstream);


private:
	string dictionary_file_name;
	vector<string> usable_words;
	ofstream word_file;
	//ifstream dictionary_file;

};

