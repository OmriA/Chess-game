#pragma once

#include "Tool.h"

class Empty : public Tool {
public:
	Empty();
	virtual ~Empty() = default;
	virtual bool isLegal(Location src, Location dest) override;
};