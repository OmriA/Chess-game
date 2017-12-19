#pragma once

#include "Tool.h"

class King : public Tool {
public:
	King(int color);
	virtual ~King() = default;
	virtual char isLegal(Board& board, int turn, Location src, Location dst, bool test) override;

};