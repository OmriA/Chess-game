#pragma once

#include "ChessGame.h"
#include "Tool.h"

#define BOARD_SIZE 8

class Tool;

class Board {
private:
	Tool* _board[BOARD_SIZE][BOARD_SIZE];
	void reverseBoard();

public:
	Board();
	~Board() = default;
	void initBoard(const char* str);
	void printBoard() const;
	Tool* getIndex(const Location cell) const;
	void setIndex(const Location cell, Tool* newTool);
};