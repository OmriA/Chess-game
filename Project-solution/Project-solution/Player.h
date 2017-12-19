#pragma once

#include "ChessGame.h"
#include "Tool.h"

class Tool;

class Player {
public:
	Player(int color);
	~Player();
	int getColor();
	void setKing(Tool* myKing);
	Tool* getKing();

private:
	Tool* _myKing;
	int _color;
};