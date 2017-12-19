#pragma once

#include "Tool.h"

class Empty : public Tool {
public:
	Empty();
	virtual ~Empty() = default;
	virtual char isLegal(Board& board, int turn, Location src, Location dst, bool test) override;

};