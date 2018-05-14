#pragma once
#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include "vector"

using namespace std;

class Board
{
public:
	Board();

	void create_puzzle();

	~Board();

private:
	unsigned int line_size, column_size;
	vector<char> line, column;
};

