#include "Player.h"

int Player::getId()
{
	return id;
}
string Player::getName()
{
	return name;
}
int Player::getOrder()
{
	return order;
}
Position Player::play()
{
	int r, c;
	cout << name << " 움직일 좌표 입력: ";
	cin >> r >> c;
	Position p(r, c);
	return p;
}
Position ComputerPlayer::play(OmokBoard board) // 컴퓨터가 돌을 놓을 위치를 자동으로 계산하여 전달. 각 위치를 evaluatePosition 메소드를 사용하여 그 중에 가장 좋은 곳의 위치를 전달 
{
	int BoardPoint[ROWS][COLS];
	int Max = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
			BoardPoint[i][j] = evaluatePosition(board, i, j);
	}
	Max = BoardPoint[0][0];
	for (int i = 0; i < 19; i++)
	{
		for (int j = 1; j < 19; j++)
		{
			if (BoardPoint[i][j] > Max)
				Max = BoardPoint[i][j];
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (BoardPoint[i][j] == Max)
			{
				Position CP(i, j);
				return CP;
			}
		}
	}
}
int ComputerPlayer::evaluatePosition(OmokBoard board, int x, int y) //(x, y) 위치의 중요도를 수치로 평가하여 전달. 컴퓨터에게 중요한 위치일수록 높은 값을 갖게 (100점 만점)
{
	Position CP(x, y);

	int PlusPoint = 0;
	double d = 0;
	double L = 0;
	double ten = 10;
	d = sqrt(pow(x - 10, 2) + pow(y - 10, 2));
	L = board.getRowCount() / ten;
	if (d <= L)
	{
		PlusPoint = 5;
	}
	if (L < d && d <= 2L)
	{
		PlusPoint = 4;
	}
	if (2L < d && d <= 3L)
	{
		PlusPoint = 3;
	}
	if (3L < d && d <= 4L)
	{
		PlusPoint = 2;
	}
	if (4L < d)
	{
		PlusPoint = 1;
	}

	int order2 = 0;
	if (order == 2)
		order2 = 1;
	else if (order == 1)
		order2 = 2;

	if (board.getStone(x, y) == 0)
	{
		int stoneNum[8];
		int stoneNum2[8];
		board.countSameColorStones(CP, StoneType(order), stoneNum);
		board.countSameColorStones(CP, StoneType(order2), stoneNum2);

		if (order == 1)
		{
			for (int i = 0; i < 7; i++)       // 33
			{
				if (stoneNum[i] == 2)
				{
					if ((i == 0) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
					{ // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
					{ // 1

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 2) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
					{ // 2

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 3) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
					{ // 3

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 4) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
					{ // 4

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 5) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
					{ // 5

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 6) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
					{ // 6

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 7) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
					{ // 7

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6
					}
				}

				if (stoneNum[i] == 1)
				{
					if ((i == 0) && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
					{ // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 1) && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
					{ // 1

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 2) && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
					{ // 2

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 3) && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
					{ // 3

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 4) && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
					{ // 4

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 5) && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
					{ // 5

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 6) && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
					{ // 6

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 7) && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
					{ // 7

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6
					}
				}

				if (stoneNum[i] == 0)
				{
					if ((i == 0) && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
					{ // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 1) && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
					{ // 1

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 2) && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
					{ // 2

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 3) && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
					{ // 3

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 4) && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
					{ // 4

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 5) && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
					{ // 5

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 6) && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
					{ // 6

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[7] == 2 && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 3, y + 3) == 0))
							return 0;
						else if (stoneNum[7] == 1 && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0;
						else if (stoneNum[7] == 0 && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
							return 0; // 7
					}
					if ((i == 7) && (board.getStone(x + 2, y + 2) == 1) && (board.getStone(x + 3, y + 3) == 1) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x + 4, y + 4) == 0))
					{ // 7

						if (stoneNum[0] == 2 && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 3, y) == 0))
							return 0;
						if (stoneNum[0] == 1 && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0;
						if (stoneNum[0] == 0 && (board.getStone(x + 2, y) == 1) && (board.getStone(x + 3, y) == 1) && (board.getStone(x - 1, y) == 0) && (board.getStone(x + 4, y) == 0))
							return 0; // 0

						if (stoneNum[1] == 2 && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 3, y - 3) == 0))
							return 0;
						else if (stoneNum[1] == 1 && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0;
						else if (stoneNum[1] == 0 && (board.getStone(x + 2, y - 2) == 1) && (board.getStone(x + 3, y - 3) == 1) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x + 4, y - 4) == 0))
							return 0; // 1

						else if (stoneNum[2] == 2 && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 3) == 0))
							return 0;
						else if (stoneNum[2] == 1 && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0;
						else if (stoneNum[2] == 0 && (board.getStone(x, y - 2) == 1) && (board.getStone(x, y - 3) == 1) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y - 4) == 0))
							return 0; // 2

						else if (stoneNum[3] == 2 && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 3, y - 3) == 0))
							return 0;
						else if (stoneNum[3] == 1 && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0;
						else if (stoneNum[3] == 0 && (board.getStone(x - 2, y - 2) == 1) && (board.getStone(x - 3, y - 3) == 1) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x - 4, y - 4) == 0))
							return 0; // 3

						else if (stoneNum[4] == 2 && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 3, y) == 0))
							return 0;
						else if (stoneNum[4] == 1 && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0;
						else if (stoneNum[4] == 0 && (board.getStone(x - 2, y) == 1) && (board.getStone(x - 3, y) == 1) && (board.getStone(x + 1, y) == 0) && (board.getStone(x - 4, y) == 0))
							return 0; // 4

						else if (stoneNum[5] == 2 && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 3, y + 3) == 0))
							return 0;
						else if (stoneNum[5] == 1 && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0;
						else if (stoneNum[5] == 0 && (board.getStone(x - 2, y + 2) == 1) && (board.getStone(x - 3, y + 3) == 1) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x - 4, y + 4) == 0))
							return 0; // 5

						else if (stoneNum[6] == 2 && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 3) == 0))
							return 0;
						else if (stoneNum[6] == 1 && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0;
						else if (stoneNum[6] == 0 && (board.getStone(x, y + 2) == 1) && (board.getStone(x, y + 3) == 1) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y + 4) == 0))
							return 0; // 6
					}
				}
			}
		}
		for (int i = 0; i < 7; i++)       // 컴퓨터가 5개
		{
			if (stoneNum[i] == 4)
				return 100 + PlusPoint;
		}
		for (int j = 0; j < 4; j++)
		{
			if (stoneNum[j] + stoneNum[j + 4] == 4)
				return 100 + PlusPoint;
		}

		for (int i = 0; i < 7; i++)       // Player가 5개
		{
			if (stoneNum2[i] == 4)
				return 90 + PlusPoint;
		}
		for (int j = 0; j < 4; j++)
		{
			if (stoneNum2[j] + stoneNum2[j + 4] == 4)
				return 90 + PlusPoint;
		}
		for (int i = 0; i < 7; i++)       // 컴퓨터가 열린 4개
		{
			if (stoneNum[i] == 3)
			{
				if (i == 0)
				{
					if (board.getStone(x - 1, y) == 0 && board.getStone(x + 4, y) == 0)
						return 80 + PlusPoint;
				}
				if (i == 1)
				{
					if (board.getStone(x - 1, y + 1) == 0 && board.getStone(x + 4, y - 4) == 0)
						return 80 + PlusPoint;
				}
				if (i == 2)
				{
					if (board.getStone(x, y + 1) == 0 && board.getStone(x, y - 4) == 0)
						return 80 + PlusPoint;
				}
				if (i == 3)
				{
					if (board.getStone(x + 1, y + 1) == 0 && board.getStone(x - 4, y - 4) == 0)
						return 80 + PlusPoint;
				}
				if (i == 4)
				{
					if (board.getStone(x + 1, y) == 0 && board.getStone(x - 4, y) == 0)
						return 80 + PlusPoint;
				}
				if (i == 5)
				{
					if (board.getStone(x + 1, y - 1) == 0 && board.getStone(x - 4, y + 4) == 0)
						return 80 + PlusPoint;
				}
				if (i == 6)
				{
					if (board.getStone(x, y - 1) == 0 && board.getStone(x, y + 4) == 0)
						return 80 + PlusPoint;
				}
				if (i == 7)
				{
					if (board.getStone(x - 1, y - 1) == 0 && board.getStone(x + 4, y + 4) == 0)
						return 80 + PlusPoint;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			if (stoneNum[j] + stoneNum[j + 4] == 3)
			{
				if (j == 0)
				{
					if (stoneNum[j] == 1)
					{
						if (board.getStone(x + 2, y) == 0 && board.getStone(x - 3, y) == 0)
							return 80 + PlusPoint;
					}
					if (stoneNum[j] == 2)
					{
						if (board.getStone(x + 3, y) == 0 && board.getStone(x - 2, y) == 0)
							return 80 + PlusPoint;
					}
				}
				if (j == 1)
				{
					if (stoneNum[j] == 1)
					{
						if (board.getStone(x + 2, y - 2) == 0 && board.getStone(x - 3, y + 3) == 0)
							return 80 + PlusPoint;
					}
					if (stoneNum[j] == 2)
					{
						if (board.getStone(x + 3, y - 3) == 0 && board.getStone(x - 2, y + 2) == 0)
							return 80 + PlusPoint;
					}
				}
				if (j == 2)
				{
					if (stoneNum[j] == 1)
					{
						if (board.getStone(x, y - 2) == 0 && board.getStone(x, y + 3) == 0)
							return 80 + PlusPoint;
					}
					if (stoneNum[j] == 2)
					{
						if (board.getStone(x, y - 3) == 0 && board.getStone(x, y + 2) == 0)
							return 80 + PlusPoint;
					}
				}
				if (j == 3)
				{
					if (stoneNum[j] == 1)
					{
						if (board.getStone(x - 2, y - 2) == 0 && board.getStone(x + 3, y + 3) == 0)
							return 80 + PlusPoint;
					}
					if (stoneNum[j] == 2)
					{
						if (board.getStone(x - 3, y - 3) == 0 && board.getStone(x + 2, y + 2) == 0)
							return 80 + PlusPoint;
					}
				}
			}
		}
		for (int i = 0; i < 7; i++)         // Player가 열린 4개
		{
			if (stoneNum2[i] == 3)
			{
				if (i == 0)
				{
					if (board.getStone(x - 1, y) == 0 && board.getStone(x + 4, y) == 0)
						return 75 + PlusPoint;
				}
				if (i == 1)
				{
					if (board.getStone(x - 1, y + 1) == 0 && board.getStone(x + 4, y - 4) == 0)
						return 75 + PlusPoint;
				}
				if (i == 2)
				{
					if (board.getStone(x, y + 1) == 0 && board.getStone(x, y - 4) == 0)
						return 75 + PlusPoint;
				}
				if (i == 3)
				{
					if (board.getStone(x + 1, y + 1) == 0 && board.getStone(x - 4, y - 4) == 0)
						return 75 + PlusPoint;
				}
				if (i == 4)
				{
					if (board.getStone(x + 1, y) == 0 && board.getStone(x - 4, y) == 0)
						return 75 + PlusPoint;
				}
				if (i == 5)
				{
					if (board.getStone(x + 1, y - 1) == 0 && board.getStone(x - 4, y + 4) == 0)
						return 75 + PlusPoint;
				}
				if (i == 6)
				{
					if (board.getStone(x, y - 1) == 0 && board.getStone(x, y + 4) == 0)
						return 75 + PlusPoint;
				}
				if (i == 7)
				{
					if (board.getStone(x - 1, y - 1) == 0 && board.getStone(x + 4, y + 4) == 0)
						return 75 + PlusPoint;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			if (stoneNum2[j] + stoneNum2[j + 4] == 3)
			{
				if (j == 0)
				{
					if (stoneNum2[j] == 1)
					{
						if (board.getStone(x + 2, y) == 0 && board.getStone(x - 3, y) == 0)
							return 75 + PlusPoint;
					}
					if (stoneNum2[j] == 2)
					{
						if (board.getStone(x + 3, y) == 0 && board.getStone(x - 2, y) == 0)
							return 75 + PlusPoint;
					}
				}
				if (j == 1)
				{
					if (stoneNum2[j] == 1)
					{
						if (board.getStone(x + 2, y - 2) == 0 && board.getStone(x - 3, y + 3) == 0)
							return 75 + PlusPoint;
					}
					if (stoneNum2[j] == 2)
					{
						if (board.getStone(x + 3, y - 3) == 0 && board.getStone(x - 2, y + 2) == 0)
							return 75 + PlusPoint;
					}
				}
				if (j == 2)
				{
					if (stoneNum2[j] == 1)
					{
						if (board.getStone(x, y - 2) == 0 && board.getStone(x, y + 3) == 0)
							return 75 + PlusPoint;
					}
					if (stoneNum2[j] == 2)
					{
						if (board.getStone(x, y - 3) == 0 && board.getStone(x, y + 2) == 0)
							return 75 + PlusPoint;
					}
				}
				if (j == 3)
				{
					if (stoneNum2[j] == 1)
					{
						if (board.getStone(x - 2, y - 2) == 0 && board.getStone(x + 3, y + 3) == 0)
							return 75 + PlusPoint;
					}
					if (stoneNum2[j] == 2)
					{
						if (board.getStone(x - 3, y - 3) == 0 && board.getStone(x + 2, y + 2) == 0)
							return 75 + PlusPoint;
					}
				}
			}
		}
		for (int i = 0; i < 7; i++)        // 컴퓨터가 닫힌 4개
		{
			if (stoneNum[i] == 3)
			{
				if (i == 0)
				{
					if (board.getStone(x - 1, y) == 0 && board.getStone(x + 4, y) == order2)
						return 70 + PlusPoint;
				}
				if (i == 1)
				{
					if (board.getStone(x - 1, y + 1) == 0 && board.getStone(x + 4, y - 4) == order2)
						return 70 + PlusPoint;
				}
				if (i == 2)
				{
					if (board.getStone(x, y + 1) == 0 && board.getStone(x, y - 4) == order2)
						return 70 + PlusPoint;
				}
				if (i == 3)
				{
					if (board.getStone(x + 1, y + 1) == 0 && board.getStone(x - 4, y - 4) == order2)
						return 70 + PlusPoint;
				}
				if (i == 4)
				{
					if (board.getStone(x + 1, y) == 0 && board.getStone(x - 4, y) == order2)
						return 70 + PlusPoint;
				}
				if (i == 5)
				{
					if (board.getStone(x + 1, y - 1) == 0 && board.getStone(x - 4, y + 4) == order2)
						return 70 + PlusPoint;
				}
				if (i == 6)
				{
					if (board.getStone(x, y - 1) == 0 && board.getStone(x, y + 4) == order2)
						return 70 + PlusPoint;
				}
				if (i == 7)
				{
					if (board.getStone(x - 1, y - 1) == 0 && board.getStone(x + 4, y + 4) == order2)
						return 70 + PlusPoint;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			if (stoneNum[j] + stoneNum[j + 4] == 3)
			{
				if (j == 0)
				{
					if (stoneNum[j] == 1)
					{
						if (board.getStone(x + 2, y) == 0 && board.getStone(x - 3, y) == order2)
							return 70 + PlusPoint;
						if (board.getStone(x + 2, y) == order2 && board.getStone(x - 3, y) == 0)
							return 70 + PlusPoint;
					}
					if (stoneNum[j] == 2)
					{
						if (board.getStone(x + 3, y) == 0 && board.getStone(x - 2, y) == order2)
							return 70 + PlusPoint;
						if (board.getStone(x + 3, y) == order2 && board.getStone(x - 2, y) == 0)
							return 70 + PlusPoint;
					}
				}
				if (j == 1)
				{
					if (stoneNum[j] == 1)
					{
						if (board.getStone(x + 2, y - 2) == 0 && board.getStone(x - 3, y + 3) == order2)
							return 70 + PlusPoint;
						if (board.getStone(x + 2, y - 2) == order2 && board.getStone(x - 3, y + 3) == 0)
							return 70 + PlusPoint;
					}
					if (stoneNum[j] == 2)
					{
						if (board.getStone(x + 3, y - 3) == 0 && board.getStone(x - 2, y + 2) == order2)
							return 70 + PlusPoint;
						if (board.getStone(x + 3, y - 3) == order2 && board.getStone(x - 2, y + 2) == 0)
							return 70 + PlusPoint;
					}
				}
				if (j == 2)
				{
					if (stoneNum[j] == 1)
					{
						if (board.getStone(x, y - 2) == 0 && board.getStone(x, y + 3) == order2)
							return 70 + PlusPoint;
						if (board.getStone(x, y - 2) == order2 && board.getStone(x, y + 3) == 0)
							return 70 + PlusPoint;
					}
					if (stoneNum[j] == 2)
					{
						if (board.getStone(x, y - 3) == 0 && board.getStone(x, y + 2) == order2)
							return 70 + PlusPoint;
						if (board.getStone(x, y - 3) == order2 && board.getStone(x, y + 2) == 0)
							return 70 + PlusPoint;
					}
				}
				if (j == 3)
				{
					if (stoneNum[j] == 1)
					{
						if (board.getStone(x - 2, y - 2) == 0 && board.getStone(x + 3, y + 3) == order2)
							return 70 + PlusPoint;
						if (board.getStone(x - 2, y - 2) == order2 && board.getStone(x + 3, y + 3) == 0)
							return 70 + PlusPoint;
					}
					if (stoneNum[j] == 2)
					{
						if (board.getStone(x - 3, y - 3) == 0 && board.getStone(x + 2, y + 2) == order2)
							return 70 + PlusPoint;
						if (board.getStone(x - 3, y - 3) == order2 && board.getStone(x + 2, y + 2) == 0)
							return 70 + PlusPoint;
					}
				}
			}
		}
		for (int i = 0; i < 7; i++)      // Player가 닫힌 4개
		{
			if (stoneNum2[i] == 3)
			{
				if (i == 0)
				{
					if (board.getStone(x - 1, y) == 0 && board.getStone(x + 4, y) == order)
						return 65 + PlusPoint;
				}
				if (i == 1)
				{
					if (board.getStone(x - 1, y + 1) == 0 && board.getStone(x + 4, y - 4) == order)
						return 65 + PlusPoint;
				}
				if (i == 2)
				{
					if (board.getStone(x, y + 1) == 0 && board.getStone(x, y - 4) == order)
						return 65 + PlusPoint;
				}
				if (i == 3)
				{
					if (board.getStone(x + 1, y + 1) == 0 && board.getStone(x - 4, y - 4) == order)
						return 65 + PlusPoint;
				}
				if (i == 4)
				{
					if (board.getStone(x + 1, y) == 0 && board.getStone(x - 4, y) == order)
						return 65 + PlusPoint;
				}
				if (i == 5)
				{
					if (board.getStone(x + 1, y - 1) == 0 && board.getStone(x - 4, y + 4) == order)
						return 65 + PlusPoint;
				}
				if (i == 6)
				{
					if (board.getStone(x, y - 1) == 0 && board.getStone(x, y + 4) == order)
						return 65 + PlusPoint;
				}
				if (i == 7)
				{
					if (board.getStone(x - 1, y - 1) == 0 && board.getStone(x + 4, y + 4) == order)
						return 65 + PlusPoint;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			if (stoneNum2[j] + stoneNum2[j + 4] == 3)
			{
				if (j == 0)
				{
					if (stoneNum2[j] == 1)
					{
						if (board.getStone(x + 2, y) == 0 && board.getStone(x - 3, y) == order)
							return 65 + PlusPoint;
						if (board.getStone(x + 2, y) == order && board.getStone(x - 3, y) == 0)
							return 65 + PlusPoint;
					}
					if (stoneNum2[j] == 2)
					{
						if (board.getStone(x + 3, y) == 0 && board.getStone(x - 2, y) == order)
							return 65 + PlusPoint;
						if (board.getStone(x + 3, y) == order && board.getStone(x - 2, y) == 0)
							return 65 + PlusPoint;
					}
				}
				if (j == 1)
				{
					if (stoneNum2[j] == 1)
					{
						if (board.getStone(x + 2, y - 2) == 0 && board.getStone(x - 3, y + 3) == order)
							return 65 + PlusPoint;
						if (board.getStone(x + 2, y - 2) == order && board.getStone(x - 3, y + 3) == 0)
							return 65 + PlusPoint;
					}
					if (stoneNum2[j] == 2)
					{
						if (board.getStone(x + 3, y - 3) == 0 && board.getStone(x - 2, y + 2) == order)
							return 65 + PlusPoint;
						if (board.getStone(x + 3, y - 3) == order && board.getStone(x - 2, y + 2) == 0)
							return 65 + PlusPoint;
					}
				}
				if (j == 2)
				{
					if (stoneNum2[j] == 1)
					{
						if (board.getStone(x, y - 2) == 0 && board.getStone(x, y + 3) == order)
							return 65 + PlusPoint;
						if (board.getStone(x, y - 2) == order && board.getStone(x, y + 3) == 0)
							return 65 + PlusPoint;
					}
					if (stoneNum2[j] == 2)
					{
						if (board.getStone(x, y - 3) == 0 && board.getStone(x, y + 2) == order)
							return 65 + PlusPoint;
						if (board.getStone(x, y - 3) == order && board.getStone(x, y + 2) == 0)
							return 65 + PlusPoint;
					}
				}
				if (j == 3)
				{
					if (stoneNum2[j] == 1)
					{
						if (board.getStone(x - 2, y - 2) == 0 && board.getStone(x + 3, y + 3) == order)
							return 65 + PlusPoint;
						if (board.getStone(x - 2, y - 2) == order && board.getStone(x + 3, y + 3) == 0)
							return 65 + PlusPoint;
					}
					if (stoneNum2[j] == 2)
					{
						if (board.getStone(x - 3, y - 3) == 0 && board.getStone(x + 2, y + 2) == order)
							return 65 + PlusPoint;
						if (board.getStone(x - 3, y - 3) == order && board.getStone(x + 2, y + 2) == 0)
							return 65 + PlusPoint;
					}
				}
			}
		}
		for (int i = 0; i < 7; i++)       // 컴퓨터가 열린 3개
		{
			if (stoneNum[i] == 2)
			{
				if (i == 0)
				{
					if (board.getStone(x - 1, y) == 0 && board.getStone(x + 3, y) == 0)
						return 60 + PlusPoint;
				}
				if (i == 1)
				{
					if (board.getStone(x - 1, y + 1) == 0 && board.getStone(x + 3, y - 3) == 0)
						return 60 + PlusPoint;
				}
				if (i == 2)
				{
					if (board.getStone(x, y + 1) == 0 && board.getStone(x, y - 3) == 0)
						return 60 + PlusPoint;
				}
				if (i == 3)
				{
					if (board.getStone(x + 1, y + 1) == 0 && board.getStone(x - 3, y - 3) == 0)
						return 60 + PlusPoint;
				}
				if (i == 4)
				{
					if (board.getStone(x + 1, y) == 0 && board.getStone(x - 3, y) == 0)
						return 60 + PlusPoint;
				}
				if (i == 5)
				{
					if (board.getStone(x + 1, y - 1) == 0 && board.getStone(x - 3, y + 3) == 0)
						return 60 + PlusPoint;
				}
				if (i == 6)
				{
					if (board.getStone(x, y - 1) == 0 && board.getStone(x, y + 3) == 0)
						return 60 + PlusPoint;
				}
				if (i == 7)
				{
					if (board.getStone(x - 1, y - 1) == 0 && board.getStone(x + 3, y + 3) == 0)
						return 60 + PlusPoint;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			if (stoneNum[j] + stoneNum[j + 4] == 2)
			{
				if (j == 0)
				{
					if (board.getStone(x + 2, y) == 0 && board.getStone(x - 2, y) == 0)
						return 60 + PlusPoint;
				}
				if (j == 1)
				{
					if (board.getStone(x + 2, y - 2) == 0 && board.getStone(x - 2, y + 2) == 0)
						return 60 + PlusPoint;
				}
				if (j == 2)
				{
					if (board.getStone(x, y - 2) == 0 && board.getStone(x, y + 2) == 0)
						return 60 + PlusPoint;
				}
				if (j == 3)
				{
					if (board.getStone(x - 2, y - 2) == 0 && board.getStone(x + 2, y + 2) == 0)
						return 60 + PlusPoint;
				}
			}
		}
		for (int i = 0; i < 7; i++)     // Player가 열린 3개
		{
			if (stoneNum2[i] == 2)
			{
				if (i == 0)
				{
					if (board.getStone(x - 1, y) == 0 && board.getStone(x + 3, y) == 0)
						return 55 + PlusPoint;
				}
				if (i == 1)
				{
					if (board.getStone(x - 1, y + 1) == 0 && board.getStone(x + 3, y - 3) == 0)
						return 55 + PlusPoint;
				}
				if (i == 2)
				{
					if (board.getStone(x, y + 1) == 0 && board.getStone(x, y - 3) == 0)
						return 55 + PlusPoint;
				}
				if (i == 3)
				{
					if (board.getStone(x + 1, y + 1) == 0 && board.getStone(x - 3, y - 3) == 0)
						return 55 + PlusPoint;
				}
				if (i == 4)
				{
					if (board.getStone(x + 1, y) == 0 && board.getStone(x - 3, y) == 0)
						return 55 + PlusPoint;
				}
				if (i == 5)
				{
					if (board.getStone(x + 1, y - 1) == 0 && board.getStone(x - 3, y + 3) == 0)
						return 55 + PlusPoint;
				}
				if (i == 6)
				{
					if (board.getStone(x, y - 1) == 0 && board.getStone(x, y + 3) == 0)
						return 55 + PlusPoint;
				}
				if (i == 7)
				{
					if (board.getStone(x - 1, y - 1) == 0 && board.getStone(x + 3, y + 3) == 0)
						return 55 + PlusPoint;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			if (stoneNum2[j] + stoneNum2[j + 4] == 2)
			{
				if (j == 0)
				{
					if (board.getStone(x + 2, y) == 0 && board.getStone(x - 2, y) == 0)
						return 55 + PlusPoint;
				}
				if (j == 1)
				{
					if (board.getStone(x + 2, y - 2) == 0 && board.getStone(x - 2, y + 2) == 0)
						return 55 + PlusPoint;
				}
				if (j == 2)
				{
					if (board.getStone(x, y - 2) == 0 && board.getStone(x, y + 2) == 0)
						return 55 + PlusPoint;
				}
				if (j == 3)
				{
					if (board.getStone(x - 2, y - 2) == 0 && board.getStone(x + 2, y + 2) == 0)
						return 55 + PlusPoint;
				}
			}
		}
		for (int i = 0; i < 7; i++)       // 컴퓨터가 닫힌 3개
		{
			if (stoneNum[i] == 2)
			{
				if (i == 0)
				{
					if ((board.getStone(x - 1, y) == 0) && (board.getStone(x - 2, y) == 0) && (board.getStone(x + 3, y) == order2))
						return 50 + PlusPoint;
				}
				if (i == 1)
				{
					if ((board.getStone(x - 1, y + 1) == 0) && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x + 3, y - 3) == order2))
						return 50 + PlusPoint;
				}
				if (i == 2)
				{
					if ((board.getStone(x, y + 1) == 0) && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y - 3) == order2))
						return 50 + PlusPoint;
				}
				if (i == 3)
				{
					if ((board.getStone(x + 1, y + 1) == 0) && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x - 3, y - 3) == order2))
						return 50 + PlusPoint;
				}
				if (i == 4)
				{
					if ((board.getStone(x + 1, y) == 0) && (board.getStone(x + 2, y) == 0) && (board.getStone(x - 3, y) == order2))
						return 50 + PlusPoint;
				}
				if (i == 5)
				{
					if ((board.getStone(x + 1, y - 1) == 0) && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x - 3, y + 3) == order2))
						return 50 + PlusPoint;
				}
				if (i == 6)
				{
					if ((board.getStone(x, y - 1) == 0) && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y + 3) == order2))
						return 50 + PlusPoint;
				}
				if (i == 7)
				{
					if ((board.getStone(x - 1, y - 1) == 0) && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x + 3, y + 3) == order2))
						return 50 + PlusPoint;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			if (stoneNum[j] + stoneNum[j + 4] == 2)
			{
				if (j == 0)
				{
					if ((board.getStone(x + 2, y) == order2) && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 0))
						return 50 + PlusPoint;
					if ((board.getStone(x - 2, y) == order2) && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 0))
						return 50 + PlusPoint;
				}
				if (j == 1)
				{
					if ((board.getStone(x + 2, y - 2) == order2) && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 0))
						return 50 + PlusPoint;
					if ((board.getStone(x - 2, y + 2) == order2) && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 0))
						return 50 + PlusPoint;
				}
				if (j == 2)
				{
					if ((board.getStone(x, y - 2) == order2) && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 0))
						return 50 + PlusPoint;
					if ((board.getStone(x, y + 2) == order2) && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 0))
						return 50 + PlusPoint;
				}
				if (j == 3)
				{
					if ((board.getStone(x - 2, y - 2) == order2) && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 0))
						return 50 + PlusPoint;
					if ((board.getStone(x + 2, y + 2) == order2) && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 0))
						return 50 + PlusPoint;
				}
			}
		}
		for (int i = 0; i < 7; i++)      // Player가 닫힌 3개
		{
			if (stoneNum2[i] == 2)
			{
				if (i == 0)
				{
					if ((board.getStone(x - 1, y) == 0) && (board.getStone(x - 2, y) == 0) && (board.getStone(x + 3, y) == order))
						return 45 + PlusPoint;
				}
				if (i == 1)
				{
					if ((board.getStone(x - 1, y + 1) == 0) && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x + 3, y - 3) == order))
						return 45 + PlusPoint;
				}
				if (i == 2)
				{
					if ((board.getStone(x, y + 1) == 0) && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y - 3) == order))
						return 45 + PlusPoint;
				}
				if (i == 3)
				{
					if ((board.getStone(x + 1, y + 1) == 0) && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x - 3, y - 3) == order))
						return 45 + PlusPoint;
				}
				if (i == 4)
				{
					if ((board.getStone(x + 1, y) == 0) && (board.getStone(x + 2, y) == 0) && (board.getStone(x - 3, y) == order))
						return 45 + PlusPoint;
				}
				if (i == 5)
				{
					if ((board.getStone(x + 1, y - 1) == 0) && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x - 3, y + 3) == order))
						return 45 + PlusPoint;
				}
				if (i == 6)
				{
					if ((board.getStone(x, y - 1) == 0) && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y + 3) == order))
						return 45 + PlusPoint;
				}
				if (i == 7)
				{
					if ((board.getStone(x - 1, y - 1) == 0) && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x + 3, y + 3) == order))
						return 45 + PlusPoint;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			if (stoneNum2[j] + stoneNum2[j + 4] == 2)
			{
				if (j == 0)
				{
					if ((board.getStone(x + 2, y) == order) && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == 0))
						return 45 + PlusPoint;
					if ((board.getStone(x - 2, y) == order) && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == 0))
						return 45 + PlusPoint;
				}
				if (j == 1)
				{
					if ((board.getStone(x + 2, y - 2) == order) && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == 0))
						return 45 + PlusPoint;
					if ((board.getStone(x - 2, y + 2) == order) && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == 0))
						return 45 + PlusPoint;
				}
				if (j == 2)
				{
					if ((board.getStone(x, y - 2) == order) && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == 0))
						return 45 + PlusPoint;
					if ((board.getStone(x, y + 2) == order) && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == 0))
						return 45 + PlusPoint;
				}
				if (j == 3)
				{
					if ((board.getStone(x - 2, y - 2) == order) && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == 0))
						return 45 + PlusPoint;
					if ((board.getStone(x + 2, y + 2) == order) && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == 0))
						return 45 + PlusPoint;
				}
			}
		}
		for (int i = 0; i < 7; i++)     // 컴퓨터가 열린 2개
		{
			if (stoneNum[i] == 1)
			{
				if (i == 0)
				{
					if ((board.getStone(x - 1, y) == 0) && (board.getStone(x - 2, y) == 0) && (board.getStone(x + 2, y) == 0))
						return 40 + PlusPoint;
				}
				if (i == 1)
				{
					if ((board.getStone(x - 1, y + 1) == 0) && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x + 2, y - 2) == 0))
						return 40 + PlusPoint;
				}
				if (i == 2)
				{
					if ((board.getStone(x, y + 1) == 0) && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y - 2) == 0))
						return 40 + PlusPoint;
				}
				if (i == 3)
				{
					if ((board.getStone(x + 1, y + 1) == 0) && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x - 2, y - 2) == 0))
						return 40 + PlusPoint;
				}
				if (i == 4)
				{
					if ((board.getStone(x + 1, y) == 0) && (board.getStone(x + 2, y) == 0) && (board.getStone(x - 2, y) == 0))
						return 40 + PlusPoint;
				}
				if (i == 5)
				{
					if ((board.getStone(x + 1, y - 1) == 0) && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x - 2, y + 2) == 0))
						return 40 + PlusPoint;
				}
				if (i == 6)
				{
					if ((board.getStone(x, y - 1) == 0) && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y + 2) == 0))
						return 40 + PlusPoint;
				}
				if (i == 7)
				{
					if ((board.getStone(x - 1, y - 1) == 0) && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x + 2, y + 2) == 0))
						return 40 + PlusPoint;
				}
			}
		}
		for (int i = 0; i < 7; i++)      // Player가 열린 2개
		{
			if (stoneNum2[i] == 1)
			{
				if (i == 0)
				{
					if ((board.getStone(x - 1, y) == 0) && (board.getStone(x - 2, y) == 0) && (board.getStone(x + 2, y) == 0))
						return 35 + PlusPoint;
				}
				if (i == 1)
				{
					if ((board.getStone(x - 1, y + 1) == 0) && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x + 2, y - 2) == 0))
						return 35 + PlusPoint;
				}
				if (i == 2)
				{
					if ((board.getStone(x, y + 1) == 0) && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y - 2) == 0))
						return 35 + PlusPoint;
				}
				if (i == 3)
				{
					if ((board.getStone(x + 1, y + 1) == 0) && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x - 2, y - 2) == 0))
						return 35 + PlusPoint;
				}
				if (i == 4)
				{
					if ((board.getStone(x + 1, y) == 0) && (board.getStone(x + 2, y) == 0) && (board.getStone(x - 2, y) == 0))
						return 35 + PlusPoint;
				}
				if (i == 5)
				{
					if ((board.getStone(x + 1, y - 1) == 0) && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x - 2, y + 2) == 0))
						return 35 + PlusPoint;
				}
				if (i == 6)
				{
					if ((board.getStone(x, y - 1) == 0) && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y + 2) == 0))
						return 35 + PlusPoint;
				}
				if (i == 7)
				{
					if ((board.getStone(x - 1, y - 1) == 0) && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x + 2, y + 2) == 0))
						return 35 + PlusPoint;
				}
			}
		}
		for (int i = 0; i < 7; i++)    // 컴퓨터가 닫힌 2개
		{
			if (stoneNum[i] == 1)
			{
				if (i == 0)
				{
					if ((board.getStone(x - 1, y) == 0) && (board.getStone(x - 2, y) == 0) && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == order2))
						return 30 + PlusPoint;
				}
				if (i == 1)
				{
					if ((board.getStone(x - 1, y + 1) == 0) && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == order2))
						return 30 + PlusPoint;
				}
				if (i == 2)
				{
					if ((board.getStone(x, y + 1) == 0) && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == order2))
						return 30 + PlusPoint;
				}
				if (i == 3)
				{
					if ((board.getStone(x + 1, y + 1) == 0) && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == order2))
						return 30 + PlusPoint;
				}
				if (i == 4)
				{
					if ((board.getStone(x + 1, y) == 0) && (board.getStone(x + 2, y) == 0) && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == order2))
						return 30 + PlusPoint;
				}
				if (i == 5)
				{
					if ((board.getStone(x + 1, y - 1) == 0) && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == order2))
						return 30 + PlusPoint;
				}
				if (i == 6)
				{
					if ((board.getStone(x, y - 1) == 0) && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == order2))
						return 30 + PlusPoint;
				}
				if (i == 7)
				{
					if ((board.getStone(x - 1, y - 1) == 0) && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == order2))
						return 30 + PlusPoint;
				}
			}
		}
		for (int i = 0; i < 7; i++)      // Player가 닫힌 2개
		{
			if (stoneNum2[i] == 1)
			{
				if (i == 0)
				{
					if ((board.getStone(x - 1, y) == 0) && (board.getStone(x - 2, y) == 0) && (board.getStone(x + 2, y) == 0) && (board.getStone(x + 3, y) == order))
						return 25 + PlusPoint;
				}
				if (i == 1)
				{
					if ((board.getStone(x - 1, y + 1) == 0) && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x + 3, y - 3) == order))
						return 25 + PlusPoint;
				}
				if (i == 2)
				{
					if ((board.getStone(x, y + 1) == 0) && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y - 3) == order))
						return 25 + PlusPoint;
				}
				if (i == 3)
				{
					if ((board.getStone(x + 1, y + 1) == 0) && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x - 3, y - 3) == order))
						return 25 + PlusPoint;
				}
				if (i == 4)
				{
					if ((board.getStone(x + 1, y) == 0) && (board.getStone(x + 2, y) == 0) && (board.getStone(x - 2, y) == 0) && (board.getStone(x - 3, y) == order))
						return 25 + PlusPoint;
				}
				if (i == 5)
				{
					if ((board.getStone(x + 1, y - 1) == 0) && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x - 3, y + 3) == order))
						return 25 + PlusPoint;
				}
				if (i == 6)
				{
					if ((board.getStone(x, y - 1) == 0) && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y + 3) == order))
						return 25 + PlusPoint;
				}
				if (i == 7)
				{
					if ((board.getStone(x - 1, y - 1) == 0) && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x + 3, y + 3) == order))
						return 25 + PlusPoint;
				}
			}
		}
		for (int i = 0; i < 7; i++)     // 컴퓨터가 열린 1개
		{
			if (stoneNum[i] == 0)
			{
				if (i == 0)
				{
					if ((board.getStone(x - 1, y) == 0) && (board.getStone(x - 2, y) == 0) && (board.getStone(x + 1, y) == 0) && (board.getStone(x + 2, y) == 0))
						return 20 + PlusPoint;
				}
				if (i == 1)
				{
					if ((board.getStone(x - 1, y + 1) == 0) && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x + 2, y - 2) == 0))
						return 20 + PlusPoint;
				}
				if (i == 2)
				{
					if ((board.getStone(x, y + 1) == 0) && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y - 2) == 0))
						return 20 + PlusPoint;
				}
				if (i == 3)
				{
					if ((board.getStone(x + 1, y + 1) == 0) && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x - 2, y - 2) == 0))
						return 20 + PlusPoint;
				}
				if (i == 4)
				{
					if ((board.getStone(x + 1, y) == 0) && (board.getStone(x + 2, y) == 0) && (board.getStone(x - 1, y) == 0) && (board.getStone(x - 2, y) == 0))
						return 20 + PlusPoint;
				}
				if (i == 5)
				{
					if ((board.getStone(x + 1, y - 1) == 0) && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x - 2, y + 2) == 0))
						return 20 + PlusPoint;
				}
				if (i == 6)
				{
					if ((board.getStone(x, y - 1) == 0) && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y + 2) == 0))
						return 20 + PlusPoint;
				}
				if (i == 7)
				{
					if ((board.getStone(x - 1, y - 1) == 0) && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x + 2, y + 2) == 0))
						return 20 + PlusPoint;
				}
			}
		}
		for (int i = 0; i < 7; i++)       // Player가 열린 1개
		{
			if (stoneNum2[i] == 0)
			{
				if (i == 0)
				{
					if ((board.getStone(x - 1, y) == 0) && (board.getStone(x - 2, y) == 0) && (board.getStone(x + 1, y) == 0) && (board.getStone(x + 2, y) == 0))
						return 15 + PlusPoint;
				}
				if (i == 1)
				{
					if ((board.getStone(x - 1, y + 1) == 0) && (board.getStone(x - 2, y + 2) == 0) && (board.getStone(x + 1, y - 1) == 0) && (board.getStone(x + 2, y - 2) == 0))
						return 15 + PlusPoint;
				}
				if (i == 2)
				{
					if ((board.getStone(x, y + 1) == 0) && (board.getStone(x, y + 2) == 0) && (board.getStone(x, y - 1) == 0) && (board.getStone(x, y - 2) == 0))
						return 15 + PlusPoint;
				}
				if (i == 3)
				{
					if ((board.getStone(x + 1, y + 1) == 0) && (board.getStone(x + 2, y + 2) == 0) && (board.getStone(x - 1, y - 1) == 0) && (board.getStone(x - 2, y - 2) == 0))
						return 15 + PlusPoint;
				}
				if (i == 4)
				{
					if ((board.getStone(x + 1, y) == 0) && (board.getStone(x + 2, y) == 0) && (board.getStone(x - 1, y) == 0) && (board.getStone(x - 2, y) == 0))
						return 15 + PlusPoint;
				}
				if (i == 5)
				{
					if ((board.getStone(x + 1, y - 1) == 0) && (board.getStone(x + 2, y - 2) == 0) && (board.getStone(x - 1, y + 1) == 0) && (board.getStone(x - 2, y + 2) == 0))
						return 15 + PlusPoint;
				}
				if (i == 6)
				{
					if ((board.getStone(x, y - 1) == 0) && (board.getStone(x, y - 2) == 0) && (board.getStone(x, y + 1) == 0) && (board.getStone(x, y + 2) == 0))
						return 15 + PlusPoint;
				}
				if (i == 7)
				{
					if ((board.getStone(x - 1, y - 1) == 0) && (board.getStone(x - 2, y - 2) == 0) && (board.getStone(x + 1, y + 1) == 0) && (board.getStone(x + 2, y + 2) == 0))
						return 15 + PlusPoint;
				}
			}
		}
		for (int i = 0; i < 7; i++)        // 컴퓨터가 닫힌 1개
		{
			if (stoneNum[i] == 0)
			{
				if (i == 0)
				{
					if ((board.getStone(x - 1, y) == order2) || (board.getStone(x - 2, y) == order2) || (board.getStone(x + 1, y) == order2) || (board.getStone(x + 2, y) == order2))
						return 10 + PlusPoint;
				}
				if (i == 1)
				{
					if ((board.getStone(x - 1, y + 1) == order2) || (board.getStone(x - 2, y + 2) == order2) || (board.getStone(x + 1, y - 1) == order2) || (board.getStone(x + 2, y - 2) == order2))
						return 10 + PlusPoint;
				}
				if (i == 2)
				{
					if ((board.getStone(x, y + 1) == order2) || (board.getStone(x, y + 2) == order2) || (board.getStone(x, y - 1) == order2) || (board.getStone(x, y - 2) == order2))
						return 10 + PlusPoint;
				}
				if (i == 3)
				{
					if ((board.getStone(x + 1, y + 1) == order2) || (board.getStone(x + 2, y + 2) == order2) || (board.getStone(x - 1, y - 1) == order2) || (board.getStone(x - 2, y - 2) == order2))
						return 10 + PlusPoint;
				}
				if (i == 4)
				{
					if ((board.getStone(x + 1, y) == order2) || (board.getStone(x + 2, y) == order2) || (board.getStone(x - 1, y) == order2) || (board.getStone(x - 2, y) == order2))
						return 10 + PlusPoint;
				}
				if (i == 5)
				{
					if ((board.getStone(x + 1, y - 1) == order2) || (board.getStone(x + 2, y - 2) == order2) || (board.getStone(x - 1, y + 1) == order2) || (board.getStone(x - 2, y + 2) == order2))
						return 10 + PlusPoint;
				}
				if (i == 6)
				{
					if ((board.getStone(x, y - 1) == order2) || (board.getStone(x, y - 2) == order2) || (board.getStone(x, y + 1) == order2) || (board.getStone(x, y + 2) == order2))
						return 10 + PlusPoint;
				}
				if (i == 7)
				{
					if ((board.getStone(x - 1, y - 1) == order2) || (board.getStone(x - 2, y - 2) == order2) || (board.getStone(x + 1, y + 1) == order2) || (board.getStone(x + 2, y + 2) == order2))
						return 10 + PlusPoint;
				}
			}
		}
		for (int i = 0; i < 7; i++)       // Player가 닫힌 1개
		{
			if (stoneNum2[i] == 0)
			{
				if (i == 0)
				{
					if ((board.getStone(x - 1, y) == order) || (board.getStone(x - 2, y) == order) || (board.getStone(x + 1, y) == order) || (board.getStone(x + 2, y) == order))
						return 5 + PlusPoint;
				}
				if (i == 1)
				{
					if ((board.getStone(x - 1, y + 1) == order) || (board.getStone(x - 2, y + 2) == order) || (board.getStone(x + 1, y - 1) == order) || (board.getStone(x + 2, y - 2) == order))
						return 5 + PlusPoint;
				}
				if (i == 2)
				{
					if ((board.getStone(x, y + 1) == order) || (board.getStone(x, y + 2) == order) || (board.getStone(x, y - 1) == order) || (board.getStone(x, y - 2) == order))
						return 5 + PlusPoint;
				}
				if (i == 3)
				{
					if ((board.getStone(x + 1, y + 1) == order) || (board.getStone(x + 2, y + 2) == order) || (board.getStone(x - 1, y - 1) == order) || (board.getStone(x - 2, y - 2) == order))
						return 5 + PlusPoint;
				}
				if (i == 4)
				{
					if ((board.getStone(x + 1, y) == order) || (board.getStone(x + 2, y) == order) || (board.getStone(x - 1, y) == order) || (board.getStone(x - 2, y) == order))
						return 5 + PlusPoint;
				}
				if (i == 5)
				{
					if ((board.getStone(x + 1, y - 1) == order) || (board.getStone(x + 2, y - 2) == order) || (board.getStone(x - 1, y + 1) == order) || (board.getStone(x - 2, y + 2) == order))
						return 5 + PlusPoint;
				}
				if (i == 6)
				{
					if ((board.getStone(x, y - 1) == order) || (board.getStone(x, y - 2) == order) || (board.getStone(x, y + 1) == order) || (board.getStone(x, y + 2) == order))
						return 5 + PlusPoint;
				}
				if (i == 7)
				{
					if ((board.getStone(x - 1, y - 1) == order) || (board.getStone(x - 2, y - 2) == order) || (board.getStone(x + 1, y + 1) == order) || (board.getStone(x + 2, y + 2) == order))
						return 5 + PlusPoint;
				}
			}
		}
	}
	else
		return 0;
}