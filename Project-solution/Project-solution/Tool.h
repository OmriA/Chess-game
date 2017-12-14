#pragma once

#include "Board.h"
#include "Location.h"

class Board;
class Tool {
public:
	Tool(int color, char sign);
	virtual ~Tool() = default;
	char getSign() const;
	int getColor() const;

protected:
	virtual int isLegal(Location src, Location dest) = 0;
	map<string, function<bool(Board, int, Location, Location)>> _moves;
	int _color;	//1 = white,  0 = black, -1 = empty.
	char _sign;
};