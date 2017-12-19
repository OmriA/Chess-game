#pragma once

#include "Tool.h"

class Empty : public Tool {
public:
	Empty(unsigned int row, char col);
	virtual ~Empty() = default;
	virtual char isLegal(Board& board, int turn, Location src, Location dest) override;
};