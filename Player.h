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
	Position play(OmokBoard board); // 컴퓨터가 돌을 놓을 위치를 자동으로 계산하여 전달. 각 위치를 evaluatePosition 메소드를 사용하여 그 중에 가장 좋은 곳의 위치를 전달 
	int evaluatePosition(OmokBoard board, int x, int y); //(x, y) 위치의 중요도를 수치로 평가하여 전달. 컴퓨터에게 중요한 위치일수록 높은 값을 갖게 (100점 만점)
	
};