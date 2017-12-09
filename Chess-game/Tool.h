#pragma once
#include "Board.h"
#include "Location.h"
class Board;
class Tool {
public:
	Tool();
	virtual ~Tool();
protected:
	virtual bool isLegal(Location, Location);
	map<string, function<bool(Location, Location)>> _moves;
	bool _color;

};