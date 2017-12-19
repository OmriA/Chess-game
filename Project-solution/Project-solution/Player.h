#pragma once

#include "ChessGame.h"
#include "Tool.h"

class Player {
public:
	Player(Tool* myKing);
	~Player();

private:
	Tool* _myKing;

};