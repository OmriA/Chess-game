#pragma once
#include "ChessGame.h"
#include "Tool.h"

#define BOARD_SIZE 8

class Tool;

class Board {
private:
	Tool* _board[BOARD_SIZE][BOARD_SIZE];
	string getBoardStr() const;

public:
	Board();
	~Board() = default;
};