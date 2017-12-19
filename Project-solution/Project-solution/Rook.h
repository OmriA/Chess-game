#pragma once

#include "Tool.h"

class Rook : public Tool {
public:
	Rook(int color, unsigned int row, char col);
	virtual ~Rook() = default;
	virtual char isLegal(Board& board, int turn, Location src, Location dst) override;
private:
	bool _moved;
};