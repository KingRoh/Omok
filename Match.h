#pragma once
#include "OmokBoard.h"
#include "Player.h"
#include "Position.h"

class Match
{
	Player *players;
	int turn;
	OmokBoard playBoard;
	int boardSize;
	ComputerPlayer *Cplayer;
public:
	Match();
	int getTurn();
	void setTurn(int n);
	Player* getPlayer(int n); // n번째 플레이어를 반환
	ComputerPlayer* getPlayer();
	Player* getCurrentPlayer();
	StoneType getCurrentColor();
	OmokBoard getBoard();
	void setPlayer(int n, Player *player);
	void setPlayer(ComputerPlayer *player);
	void setBoard(OmokBoard board);
	bool checkWinningCondition(Position m);
	bool checkValidity(Position m);
};