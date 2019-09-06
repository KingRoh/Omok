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
	
	cout << "�������" << endl << endl;

	cout << "�������� ũ�� ���� (�ּ� 10x10, �ִ� 19x19)" << endl;
	cout << "�������� ���簢���̹Ƿ� �ϳ��� ���ڸ� �Է����ּ���" << endl;
	do{
		cin >> BoardSize;
		if (BoardSize < 10 || BoardSize >19)
			cout << "10���� 19������ ���� �Է����ּ���" << endl;
	} while (BoardSize < 10 || BoardSize >19);
	MyBoard OB(BoardSize, BoardSize);

	cout << BoardSize << "x" << BoardSize << " ũ��� �����Ǿ����ϴ�" << endl;
	while (1)
	{
		cout << "1. ��� vs ���" << endl;
		cout << "2. ��� vs ��ǻ��" << endl;

		cin >> GameStyle;

		switch (GameStyle)
		{
		case 1:
		{
				  cout << "Player1�� ���̵� �Է� : ";
				  cin >> id1;
				  cout << "�̸� �Է� : ";
				  cin >> name1;
				  Player player1(id1, name1, 1);
				  M.setPlayer(0, &player1);
				  cout << "Player2�� ���̵� �Է� : ";
				  cin >> id2;
				  cout << "�̸� �Է� : ";
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
								  cout << "�ű⿣ �� �� �����ϴ�." << endl;
							  }
						  } while (M.checkValidity(P) == 0);
						  M.setBoard(OB);

						  OB.drawBoard();
						  
						  if (M.checkWinningCondition(P) == 1)
						  {
							  cout << M.getPlayer(0)->getName() << " �¸�!" << endl;
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
								  cout << "�ű⿣ �� �� �����ϴ�." << endl;
							  }
						  } while (M.checkValidity(P) == 0);
						  M.setBoard(OB);

						  OB.drawBoard();

						  if (M.checkWinningCondition(P) == 1)
						  {
							  cout << M.getPlayer(0)->getName() << " �¸�!" << endl;
							  M.setTurn(1);
							  break;
						  }
						  else
							  M.setTurn(1);
					  }
				  }
		}
			break;

		case 2:     //��� �� ��ǻ��
		{
						cout << "Player�� ���̵� �Է� : ";
						cin >> id1;
						cout << "�̸� �Է� : ";
						cin >> name1;
						cout << "Player�� ���� �Է� : ";
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
										cout << "�ű⿣ �� �� �����ϴ�." << endl;
									}
								} while (M.checkValidity(P) == 0);
								M.setBoard(OB);

								OB.drawBoard();

								if (M.checkWinningCondition(P) == 1)
								{
									cout << M.getPlayer(0)->getName() << " �¸�!" << endl;
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
							if (M.getTurn() == order2)    // ��ǻ�� ����
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
									cout << M.getPlayer()->getName() << " �¸�!" << endl;
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
			cout << "1�� 2�߿��� �������ּ���" << endl;
			break;
		}
	}

}