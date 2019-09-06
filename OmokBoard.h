#pragma once
#include "Position.h"
#include <iostream>
using namespace std;
enum StoneType { None = 0, Black = 1, White = 2 };

const int ROWS = 19;
const int COLS = 19;


class OmokBoard
{
protected:
	StoneType matrix[ROWS][COLS];
	int rows;
	int cols;
public:
	OmokBoard();
	OmokBoard(int rows, int cols);
	void putStone(int x, int y, StoneType stone);
	void removeStone(int x, int y);
	StoneType getStone(int x, int y);
	void clear();
	int getRowCount();
	int getColCount();
	void countSameColorStones(Position m, StoneType color, int stoneNum[8]);
};

class MyBoard : public OmokBoard
{
public:
	MyBoard() {}
	MyBoard(int rows, int cols) : OmokBoard(rows, cols) {}
	void drawBoard();
};