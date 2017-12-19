#pragma once

#include "Tool.h"	

class Knight : public Tool {
	public:
		Knight(int color, unsigned int row, char col);
		virtual ~Knight() = default;
		virtual char isLegal(Board& board, int turn, Location src, Location dst) override;
};