#pragma once
#include "ChessGame.h"
#include "AllTools.h"

#define BOARD_SIZE 8

class Tool;

class Board {
private:
	Tool* _board[BOARD_SIZE][BOARD_SIZE];

public:
	Board();
	~Board();
};