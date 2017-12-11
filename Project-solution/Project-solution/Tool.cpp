#include "Tool.h"

Tool::Tool(bool color, char sign) : _color(color), _sign(sign) {}

/**
The function returns the sign of the tool.
Input:	None.
Output:	The tool sign.
**/
char Tool::getSign() const
{
	return _sign;
}