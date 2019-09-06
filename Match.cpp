#include "Match.h"

Match::Match()
{
	players = new Player[2];
	Cplayer = new ComputerPlayer;
}
int Match::getTurn()
{
	return turn;
}
void Match::setTurn(int n)
{
	turn = n;
}
Player* Match::getPlayer(int n) // n번째 플레이어를 반환
{
	return &players[n];
}
ComputerPlayer* Match::getPlayer()
{
	return Cplayer;
}
Player* Match::getCurrentPlayer()
{
	return &players[turn];
}
StoneType Match::getCurrentColor()
{
	return StoneType(turn);
}
OmokBoard Match::getBoard()
{
	return playBoard;
}
void Match::setPlayer(int n, Player *player)
{
	players[n] = *player;
}
void Match::setPlayer(ComputerPlayer *player)
{
	*Cplayer = *player;
}
void Match::setBoard(OmokBoard board)
{
	playBoard = board;
}
bool Match::checkWinningCondition(Position m)
{
	int stoneNum[8];
	playBoard.countSameColorStones(m, getCurrentColor(), stoneNum);

	for (int i = 0; i < 7; i++)
	{
		if (stoneNum[i] == 4)
			return true;
	}
	for (int j = 0; j < 4; j++)
	{
		if (stoneNum[j] + stoneNum[j + 4] == 4)
			return true;
	}
	return false;
}
bool Match::checkValidity(Position m)
{
	if ((m.getRow() < 0) || (m.getRow() >= getBoard().getRowCount()) || (m.getColumn() < 0) || (m.getColumn() >= getBoard().getColCount()))
		return false;
	if (playBoard.getStone(m.getRow(), m.getColumn()) == 0)
	{
		if (turn == 1)
		{
			if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
			{ //0
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
			{ // 1
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
			{ // 2
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
			{ // 3
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
			{ // 4
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
			{ // 5
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
			{ // 6
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
			{ // 7
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6
			}

			if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
			{ //0
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
			{ // 1
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
			{ // 2
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
			{ // 3
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
			{ // 4
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
			{ // 5
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
			{ // 6
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
			{ // 7
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6
			}

			if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
			{ //0
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
			{ // 1
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
			{ // 2
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
			{ // 3
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
			{ // 4
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
			{ // 5
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
			{ // 6
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
					return false; // 7
			}
			if ((playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() + 4) == 0))
			{ // 7
				if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn()) == 0))
					return false; // 0

				if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() + 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() + 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() + 4, m.getColumn() - 4) == 0))
					return false; // 1

				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() - 4) == 0))
					return false; // 2

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() - 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() - 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() - 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() - 4) == 0))
					return false; // 3

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn()) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn()) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn()) == 0))
					return false; // 4

				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow() - 1, m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow() - 2, m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow() - 3, m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow() + 1, m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow() - 4, m.getColumn() + 4) == 0))
					return false; // 5

				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false;
				else if ((playBoard.getStone(m.getRow(), m.getColumn() + 1) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() + 2) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 3) == 1) && (playBoard.getStone(m.getRow(), m.getColumn() - 1) == 0) && (playBoard.getStone(m.getRow(), m.getColumn() + 4) == 0))
					return false; // 6
			}
		}
		return true;
	}
		
	else
		return false;
	// 33구현
}