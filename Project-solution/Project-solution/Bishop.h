#pragma once

#include "Tool.h"

class Bishop : public Tool {
public:
	Bishop(int color);
	virtual ~Bishop() = default;
	virtual char isLegal(Board& board, int turn, Location src, Location dst, bool test) override;

};