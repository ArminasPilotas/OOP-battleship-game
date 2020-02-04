#pragma once
using namespace std;
class Menu
{
protected:
	char gamemode;
	int converted = 0;

public:
	virtual void Menus();
	int Menureturn();
};
