#pragma once

#include "Board.h"

class Board;

class Tool {
public:
	Tool(int color, char sign);
	virtual ~Tool() = default;
	char getSign() const;
	int getColor() const;
	virtual char isLegal(Board& board, int turn, Location src, Location dst) = 0;

protected:
	void move(Board& board, Location src, Location dst);
	char vertical(Board board, int turn, Location src, Location dst);
	char horizontal(Board board, int turn, Location src, Location dst);
	char diagonalUp(Board board, int turn, Location src, Location dst);
	char diagonalDown(Board board, int turn, Location src, Location dst);
	int _color;	//white = 1,  black = 0, empty = -1.

private:
	char _sign;
};