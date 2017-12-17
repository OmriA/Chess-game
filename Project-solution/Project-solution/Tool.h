#pragma once

#include "Board.h"

class Board;

class Tool {
public:
	Tool(int color, char sign, vector<int> moves);
	virtual ~Tool() = default;
	char getSign() const;
	int getColor() const;
	void move(Board board, Location src, Location dst);
	virtual char isLegal(Board board, int turn, Location src, Location dst) = 0;

protected:
	map<string, function<char(Board board, int turn, Location src, Location dst)>> _moves;
	int _color;	//white = 1,  black = 0, empty = -1.

private:
	char _sign;
};