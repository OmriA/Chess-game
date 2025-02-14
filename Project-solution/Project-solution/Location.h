#pragma once

class Location {
public:
	Location(unsigned int row, char col);
	~Location() = default;
	void setRow(unsigned int row);
	void setCol(char col);
	unsigned int getRow() const;
	unsigned int getCol() const;
	bool operator!=(Location other);
	int operator-(Location other);

private:
	char _col;
	unsigned int _row;
};
