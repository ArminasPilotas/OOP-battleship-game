#pragma once
#include <vector>
#include <utility>
using namespace std;
class Game :public Menu, public Player1, public Player2, public Bot {
protected:
	int score1player = 0, score2player = 0;
	int turn = 1;
	char x = 0, y = 0;
public:
	virtual void Battlevsplayers();
	virtual void BattlevsBot();

};