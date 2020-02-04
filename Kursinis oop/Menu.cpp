#include "pch.h"
#include "Constants.h"

void Menu::Menus() {
	cout << "BATTLESHIP GAME" << endl;
	cout << endl;
	cout << "Choose a gamemode" << endl;
	cout << "1. Player vs Bot" << endl;
	cout << "2. Player vs Player" << endl;
	cin >> gamemode;
	while (gamemode != '1' && gamemode != '2') {
		cout << endl << "Bad input try again" << endl;
		cin >> gamemode;
	}
	system("cls");
}
int Menu::Menureturn() {
	if (gamemode == '1') {
		converted = 1;
	}
	else if (gamemode == '2') {
		converted = 2;
	}
	return converted;
}