#pragma once

class Location {
public:
	Location(unsigned int row, char col);
	~Location() = default;
	void setRow(unsigned int row);
	void setCol(char col);
	unsigned int getRow() const;
	char getCol() const;
	bool operator!=(Location other);

private:
	char _col;
	unsigned int _row;
};
