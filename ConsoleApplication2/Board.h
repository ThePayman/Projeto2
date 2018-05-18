#pragma once
#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include "vector"
#include "ctime"
#include "cstdlib"
#include "windows.h"

using namespace std;

class Board
{
public:
	Board();

	void create_puzzle();

	void show_puzzle();

	~Board();


private:
	unsigned int line_size, column_size;
	vector<vector<char>> board;
};

