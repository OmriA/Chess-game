#pragma once
#include "Tool.h"
class Pawn : public Tool {
public:
	Pawn(int color);
	virtual ~Pawn() = default;
	virtual char isLegal(Board& board, int turn, Location src, Location dst) override;

private:
	bool _moved;
	bool _movingUp;
};