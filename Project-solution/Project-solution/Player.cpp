#include "Player.h"

Player::Player(Tool* myKing) : _myKing(myKing) {}

Player::~Player()
{
	delete _myKing;
}