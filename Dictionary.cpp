#include "stdafx.h"
#include "Dictionary.h"


Dictionary::Dictionary() {
	cout << "Nah m8";

}

Dictionary::Dictionary(string fail_text = "Invalid file") {
	cout << "What is the dictionary file?" << endl;
	cin >> dictionary_file_name;
	dictionary_file.open(dictionary_file_name);
	if (!dictionary_file.is_open()) {
		cout << fail_text << endl;
	}
}

vector<string> Dictionary::read_dictionary(ifstream dictionary_file) {
	string word;
	while (dictionary_file >> word) {
		string newWord = "";
		bool ignore_word = false;
		for (unsigned int i = 0; i < word.length(); i++) {
			if (!(word[word.length()] != ':')) {
				ignore_word = true;
				break;
			}
		}
		if (!ignore_word) {
			if (word.length() > 1) {
				for (unsigned int i = 0; i < word.length() - 1 ; i++){
					newWord = newWord + word[i];
				}
				usable_words.push_back(newWord);
			}
		}
	}
	return usable_words;
}


Dictionary::~Dictionary(){


}
