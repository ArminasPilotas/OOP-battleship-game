#pragma once
#include <vector>
#include <utility>
using namespace std;
class Bot {
protected:
	char boardbot[10][10];
	char invisiblebot[10][10];
	int raides1;
	int skaiciai1;
	int uporside;
	vector <pair<int, int>> laivupozbot;
	int sudetilaivai = 0;
public:
	Bot();
	void SetBotBoard();
	void DrawBotBoard();
	void BotPlaceships(int shipsize);
	void FixBotBoard();
	void BotInvisible();
	void WhereshipsareBot();
};