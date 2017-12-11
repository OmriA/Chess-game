#pragma once

#include "Board.h"
#include "Location.h"

class Board;
class Tool {
public:
	Tool(bool color, char sign);
	virtual ~Tool() = default;
	char getSign() const;
	bool getColor() const;

protected:
	virtual bool isLegal(Location src, Location dest) = 0;
	map<string, function<bool(Board, bool, Location, Location)>> _moves;
	bool _color;
	char _sign;
};