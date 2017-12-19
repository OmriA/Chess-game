#pragma once

#include "Tool.h"

class Queen : public Tool {
public:
	Queen(int color);
	~Queen() = default;
	virtual char isLegal(Board& board, int turn, Location src, Location dst) override;

};