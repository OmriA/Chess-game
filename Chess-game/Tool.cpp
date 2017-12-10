#include "Tool.h"

Tool::Tool(bool color, char sign) : _color(color), _sign(sign) {}

char Tool::getSign() const
{
	return _sign;
}