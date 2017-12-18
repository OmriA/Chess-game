#include "Location.h"

/**
Constractor to the location.
Input:	row - the row of the location.
		col - the column of the location.
Output:	None.
**/
Location::Location(unsigned int row, char col) : _row(row), _col(col) {}

/**
Setter for the row.
Input:	row - the row to set to.
Output:	None.
**/
void Location::setRow(unsigned int row)
{
	_row = row;
}

/**
Setter for the column.
Input:	col - the column to set to.
Output:	None.
**/
void Location::setCol(char col)
{
	_col = col;
}

/**
Getter for the row.
Input:	None.
Output:	The location's row.
**/
unsigned int Location::getRow() const
{
	return _row;
}

/**
Getter for the col.
Input:	None.
Output:	The location's col.
**/
unsigned int Location::getCol() const
{
	return _col - 'a';
}

/**
Checking if the Two locations are different.
Input:	other - the other location.
Output:	true if they are different, false if not.
**/
bool Location::operator!=(Location other)
{
	return _col != other._col || _row != other._row;
}