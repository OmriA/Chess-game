#pragma once

#include <vector>
#include <functional>

class Tool
{
public:
	Tool();
	~Tool();

protected:
	std::vector<function> _moves;
};

Tool::Tool()
{
}

Tool::~Tool()
{
}