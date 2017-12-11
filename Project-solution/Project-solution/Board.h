#pragma once

#include "ChessGame.h"
#include "Tool.h"

#define BOARD_SIZE 8

class Tool;

class Board {
private:
	Tool* _board[BOARD_SIZE][BOARD_SIZE];

public:
	Board();
	~Board() = default;
	string getBoardStr() const;
	Tool* getIndex(const int x,const int y) const;
};