#pragma once

#include "Tool.h"

class Rook : public Tool {
public:
	Rook(int color);
	virtual ~Rook() = default;
	virtual int isLegal(Board board, int turn, Location src, Location dst) override;
private:
	bool _moved;
};