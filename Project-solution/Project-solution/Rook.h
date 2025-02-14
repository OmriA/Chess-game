#pragma once

#include "Tool.h"

class Rook : public Tool {
public:
	Rook(int color);
	virtual ~Rook() = default;
	virtual char isLegal(Board& board, int turn, Location src, Location dst, bool test) override;

};