#pragma once
#include "ChessGame.h"
#include "Tool.h"

#define BOARD_SIZE 8

class Tool;

class Board {
private:f
	Tool* _board[BOARD_SIZE][BOARD_SIZE];

public:
	Board();
	~Board() = default;
};