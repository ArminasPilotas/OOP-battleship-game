#include "pch.h"
#include "Constants.h"
int main()
{
	Game obj1;
	obj1.Menus();
	if (obj1.Menureturn() == 1) {
		obj1.Set1();
		obj1.SetBotBoard();
		obj1.FixBotBoard();
		obj1.Placeships1(carrier);
		obj1.Placeships1(battleship);
		obj1.Placeships1(cruiser);
		obj1.Placeships1(submarine);
		obj1.Placeships1(destroyer);
		obj1.BattlevsBot();
		
		
	}
	else if (obj1.Menureturn() == 2) {
		obj1.Set1();
		obj1.Placeships1(carrier);
		obj1.Placeships1(battleship);
		obj1.Placeships1(cruiser);
		obj1.Placeships1(submarine);
		obj1.Placeships1(destroyer);
		obj1.Set2();
		obj1.Placeships2(carrier);
		obj1.Placeships2(battleship);
		obj1.Placeships2(cruiser);
		obj1.Placeships2(submarine);
		obj1.Placeships2(destroyer);
		obj1.Battlevsplayers();
	}
	return 0;
}

