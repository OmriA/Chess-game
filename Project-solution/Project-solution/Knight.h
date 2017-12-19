#pragma once

#include "Tool.h"	

class Knight : public Tool {
	public:
		Knight(int color);
		virtual ~Knight() = default;
		virtual char isLegal(Board& board, int turn, Location src, Location dst, bool test) override;
};