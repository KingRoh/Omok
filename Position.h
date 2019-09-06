#pragma once

class Position
{
	int row;
	int column;
public:
	Position(int r, int c);
	int getRow();
	int getColumn();
};