#include "Match.h"

int main()
{
	int count = 0;
	int GameStyle = 0;
	int x = 0;
	int y = 0;
	int id1, id2;
	int BoardSize;
	string name1, name2;
	int order, order2 = 0;
	//MyBoard OB;
	Position P(x, y);
	Match M;
	M.setTurn(1);
	
	cout << "오목게임" << endl << endl;

	cout << "오목판의 크기 설정 (최소 10x10, 최대 19x19)" << endl;
	cout << "오목판은 정사각형이므로 하나의 숫자만 입력해주세요" << endl;
	do{
		cin >> BoardSize;
		if (BoardSize < 10 || BoardSize >19)
			cout << "10부터 19사이의 수만 입력해주세요" << endl;
	} while (BoardSize < 10 || BoardSize >19);
	MyBoard OB(BoardSize, BoardSize);

	cout << BoardSize << "x" << BoardSize << " 크기로 설정되었습니다" << endl;
	while (1)
	{
		cout << "1. 사람 vs 사람" << endl;
		cout << "2. 사람 vs 컴퓨터" << endl;

		cin >> GameStyle;

		switch (GameStyle)
		{
		case 1:
		{
				  cout << "Player1의 아이디 입력 : ";
				  cin >> id1;
				  cout << "이름 입력 : ";
				  cin >> name1;
				  Player player1(id1, name1, 1);
				  M.setPlayer(0, &player1);
				  cout << "Player2의 아이디 입력 : ";
				  cin >> id2;
				  cout << "이름 입력 : ";
				  cin >> name2;
				  Player player2(id2, name2, 2);
				  M.setPlayer(1, &player2);

				  OB.clear();
				  M.setBoard(OB);
				  OB.drawBoard();
				  while (1)
				  {
					  if (M.getTurn() == 1)
					  {
						  do {
							  P = M.getPlayer(0)->play();
							  if (M.checkValidity(P) == 1)
							  {
								  OB.putStone(P.getRow(), P.getColumn(), Black);
							  }
							  else
							  {
								  cout << "거기엔 둘 수 없습니다." << endl;
							  }
						  } while (M.checkValidity(P) == 0);
						  M.setBoard(OB);

						  OB.drawBoard();
						  
						  if (M.checkWinningCondition(P) == 1)
						  {
							  cout << M.getPlayer(0)->getName() << " 승리!" << endl;
							  OB.clear();
							  M.setTurn(1);
							  break;
						  }
						  else
							 M.setTurn(2);
					  }
					  if (M.getTurn() == 2)
					  {
						  do {
							  P = M.getPlayer(1)->play();
							  if (M.checkValidity(P) == 1)
							  {
								  OB.putStone(P.getRow(), P.getColumn(), White);
							  }
							  else
							  {
								  cout << "거기엔 둘 수 없습니다." << endl;
							  }
						  } while (M.checkValidity(P) == 0);
						  M.setBoard(OB);

						  OB.drawBoard();

						  if (M.checkWinningCondition(P) == 1)
						  {
							  cout << M.getPlayer(0)->getName() << " 승리!" << endl;
							  M.setTurn(1);
							  break;
						  }
						  else
							  M.setTurn(1);
					  }
				  }
		}
			break;

		case 2:     //사람 대 컴퓨터
		{
						cout << "Player의 아이디 입력 : ";
						cin >> id1;
						cout << "이름 입력 : ";
						cin >> name1;
						cout << "Player의 순서 입력 : ";
						cin >> order;
						if (order == 2)
							order2 = 1;
						else if (order == 1)
							order2 = 2;
						Player player1(id1, name1, order);
						M.setPlayer(0, &player1);
						ComputerPlayer player2(1234, "Computer", order2);
						M.setPlayer(&player2);

						OB.clear();
						M.setBoard(OB);
						OB.drawBoard();
						while (1)
						{
							if (M.getTurn() == order)
							{
								do {
									P = M.getPlayer(0)->play();
									if (M.checkValidity(P) == 1)
									{
										OB.putStone(P.getRow(), P.getColumn(), StoneType(order));
									}
									else
									{
										cout << "거기엔 둘 수 없습니다." << endl;
									}
								} while (M.checkValidity(P) == 0);
								M.setBoard(OB);

								OB.drawBoard();

								if (M.checkWinningCondition(P) == 1)
								{
									cout << M.getPlayer(0)->getName() << " 승리!" << endl;
									OB.clear();
									M.setTurn(1);
									count = 0;
									break;
								}
								else
								{
									M.setTurn(order2);
									count++;
								}

							}
							if (M.getTurn() == order2)    // 컴퓨터 구현
							{

								if (count == 0)
								{
									OB.putStone(BoardSize / 2, BoardSize / 2, StoneType(order2));
								}
								else if (count == 1)
								{
									if (P.getRow() <= BoardSize / 2)
										OB.putStone(P.getRow() + 1, P.getColumn(), StoneType(order2));
									if (P.getRow() > BoardSize / 2)
										OB.putStone(P.getRow() - 1, P.getColumn(), StoneType(order2));
								}
								else
								{
									P = M.getPlayer()->play(OB);
									OB.putStone(P.getRow(), P.getColumn(), StoneType(order2));
								}
								M.setBoard(OB);

								OB.drawBoard();

								if (M.checkWinningCondition(P) == 1)
								{
									cout << M.getPlayer()->getName() << " 승리!" << endl;
									M.setTurn(1);
									count = 0;
									break;
								}
								else
								{
									M.setTurn(order);
									count++;
								}
							}
						}
		}
			break;

		default:
			cout << "1과 2중에서 선택해주세요" << endl;
			break;
		}
	}

}