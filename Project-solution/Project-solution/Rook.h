#pragma once

#include "Tool.h"

class Rook : public Tool {
public:
	Rook(int color);
	virtual ~Rook() = default;
	virtual int isLegal(Location src, Location dest) override;
private:
	bool _moved;
};