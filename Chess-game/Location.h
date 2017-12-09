#pragma once

class Location {
public:
	explicit Location(char,int);
	~Location() = default;
	void setRow(unsigned int);
	void setCol(char);
	unsigned int getRow(void);
	char getCol(void);
private:
	char _col;
	unsigned int _row;
};
