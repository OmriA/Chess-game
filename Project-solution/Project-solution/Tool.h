#pragma once

#include "Board.h"
#include "Location.h"

class Board;
class Tool {
public:
	Tool(bool color, char sign);
	virtual ~Tool() = default;
protected:
	virtual bool isLegal(Location src, Location dest) = 0;
	map<string, function<bool(Location, Location)>> _moves;
	bool _color;
	char _sign;
};