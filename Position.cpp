#include "Position.h"

Position::Position(int r, int c)
{
	row = r;
	column = c;
}
int Position::getRow()
{
	return row;
}
int Position::getColumn()
{
	return column;
}