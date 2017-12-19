#include "Player.h"

Player::Player(int color) : _myKing(nullptr), _color(color) {}

Player::~Player()
{
	_myKing = nullptr;
}

int Player::getColor()
{
	return _color;
}

void Player::setKing(Tool* myKing)
{
	_myKing = myKing;
}

Tool* Player::getKing()
{
	return _myKing;
}