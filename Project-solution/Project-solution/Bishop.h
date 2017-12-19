#pragma once

#include "Tool.h"

class Bishop : public Tool {
public:
	Bishop(int color, unsigned int row, char col);
	virtual ~Bishop() = default;
	virtual char isLegal(Board& board, int turn, Location src, Location dst) override;
};