#pragma once

#include "ChessGame.h"
#include "Tool.h"
#include "Player.h"

#define BOARD_SIZE 8

class Tool;

class Board {
public:
	Board();
	~Board() = default;
	void freeBoard();
	void initBoard(const char* str);
	void printBoard() const;
	Tool* getIndex(const Location cell) const;
	void setIndex(const Location cell, Tool* newTool);
	Tool* getTool(char sign);
	Location getToolIndex(char sign);

private:
	Tool* _board[BOARD_SIZE][BOARD_SIZE];
	void reverseBoard();
};