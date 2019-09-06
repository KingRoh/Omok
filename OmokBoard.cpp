#include "OmokBoard.h"

OmokBoard::OmokBoard()
{
	rows = 19;
	cols = 19;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			matrix[i][j] = None;
	}
}
OmokBoard::OmokBoard(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			matrix[i][j] = None;
	}
}
void OmokBoard::putStone(int x, int y, StoneType stone)
{
	matrix[x][y] = stone;
}
void OmokBoard::removeStone(int x, int y)
{
	matrix[x][y] = None;
}
StoneType OmokBoard::getStone(int x, int y)
{
	return matrix[x][y];
}
void OmokBoard::clear()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			matrix[i][j] = None;
		}
	}
}
int OmokBoard::getRowCount()
{
	return rows;
}
int OmokBoard::getColCount()
{
	return cols;
}
void OmokBoard::countSameColorStones(Position m, StoneType color, int stoneNum[8])
{
	int i[8] = { 0 };
	for (int i = 0; i < 8; i++)
		stoneNum[i] = 0;
	while (matrix[m.getRow() + i[0] + 1][m.getColumn()] == color)
	{
		i[0]++;
		stoneNum[0] = i[0];
	}
	while (matrix[m.getRow() + i[1] + 1][m.getColumn() - i[1] - 1] == color)
	{
		i[1]++;
		stoneNum[1] = i[1];
	}
	while (matrix[m.getRow()][m.getColumn() - i[2] - 1] == color)
	{
		i[2]++;
		stoneNum[2] = i[2];
	}
	while (matrix[m.getRow() - i[3] - 1][m.getColumn() - i[3] - 1] == color)
	{
		i[3]++;
		stoneNum[3] = i[3];
	}
	while (matrix[m.getRow() - i[4] - 1][m.getColumn()] == color)
	{
		i[4]++;
		stoneNum[4] = i[4];
	}
	while (matrix[m.getRow() - i[5] - 1][m.getColumn() + i[5] + 1] == color)
	{
		i[5]++;
		stoneNum[5] = i[5];
	}
	while (matrix[m.getRow()][m.getColumn() + i[6] + 1] == color)
	{
		i[6]++;
		stoneNum[6] = i[6];
	}
	while (matrix[m.getRow() + i[7] + 1][m.getColumn() + i[7] + 1] == color)
	{
		i[7]++;
		stoneNum[7] = i[7];
	}
}

void MyBoard::drawBoard()
{
	system("cls");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (getStone(i, j) == 0)
				cout << "¦« ";
			else if (getStone(i, j) == 1)
				cout << "¡Ü";
			else if (getStone(i, j) == 2)
				cout << "¡Û";
		}
		cout << endl;
	}
}