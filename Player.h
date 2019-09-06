#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "OmokBoard.h"
#include "Position.h"
using namespace std;

class Player
{
protected:
	int id;
	int order;
	string name;
public:
	Player() {}
	Player(int id, string name, int order) : id(id), name(name), order(order) {}
	int getId();
	string getName();
	int getOrder();
	Position play();
};

class ComputerPlayer : public Player
{
public:
	ComputerPlayer() {}
	ComputerPlayer(int id, string name, int order) : Player(id, name, order) {}
	Position play(OmokBoard board); // ��ǻ�Ͱ� ���� ���� ��ġ�� �ڵ����� ����Ͽ� ����. �� ��ġ�� evaluatePosition �޼ҵ带 ����Ͽ� �� �߿� ���� ���� ���� ��ġ�� ���� 
	int evaluatePosition(OmokBoard board, int x, int y); //(x, y) ��ġ�� �߿䵵�� ��ġ�� ���Ͽ� ����. ��ǻ�Ϳ��� �߿��� ��ġ�ϼ��� ���� ���� ���� (100�� ����)
	
};