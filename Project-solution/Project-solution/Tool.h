#pragma once

#include "Board.h"
#include "Location.h"

#define VALID_MOVE 0
#define VALID_CHECK 1
#define SRC_HAS_NO_TURNS_TOOL 2
#define DST_HAS_TURNS_TOOL 3
#define INVALID_CHECK 4
#define INVALID_MOVE 6
#define SAME_SRC_DST 7
#define CHECKMATE 8

#define VERTICAL 0
#define HORIZONTAL 1
#define DIAGONAL 2

class Board;
class Tool {
public:
	Tool(int color, char sign, vector<int> moves);
	virtual ~Tool() = default;
	char getSign() const;
	int getColor() const;

protected:
	virtual int isLegal(Board board, int turn, Location src, Location dst) = 0;
	map<string, function<bool(Board board, int turn, Location src, Location dst)>> _moves;
	int _color;	//1 = white,  0 = black, -1 = empty.

private:
	char _sign;
};