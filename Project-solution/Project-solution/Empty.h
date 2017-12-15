#pragma once

#include "Tool.h"

class Empty : public Tool {
public:
	Empty();
	virtual ~Empty() = default;
	virtual int isLegal(Board board, int turn, Location src, Location dest) override;
};