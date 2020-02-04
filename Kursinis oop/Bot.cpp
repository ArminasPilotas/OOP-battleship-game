#include "pch.h"
#include "Constants.h"
Bot::Bot() {
	raides1 = 0; skaiciai1 = 0; uporside = 0;
}
void Bot::SetBotBoard() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			boardbot[i][j] = '~';
			invisiblebot[i][j] = '~';
		}
	}
}
void Bot::DrawBotBoard() {
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			cout << "   ";
		}
		cout << raides[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << skaiciai[i] << "  ";
		for (int j = 0; j < 10; j++) {

			cout << boardbot[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------";
	cout << endl;
}
void Bot::BotPlaceships(int shipsize) {
againn:
	//srand(time(NULL));
	//Sleep(1000);
	raides1 = rand() % 10;
	skaiciai1 = rand() % 10;
	uporside = rand() % 2;
	if (uporside == 0) { //laivas eina i virsu arba i apacia
		if (raides1 + shipsize >= 9) { //deti nuo apacios i virsu
			for (int i = raides1 - (shipsize - 1); i <= raides1; i++) {
				if (boardbot[i][skaiciai1] == '1') { goto againn; break; }
			}
			for (int i = raides1 - (shipsize - 1); i <= raides1; i++) {
				boardbot[i][skaiciai1] = pataikyta;
				if (skaiciai1 != 9) {
					boardbot[i][skaiciai1 + 1] = '1';
				}
				if (skaiciai1 != 0) {
					boardbot[i][skaiciai1 - 1] = '1';
				}
				if (raides1 != 9) {
					boardbot[raides1 + 1][skaiciai1] = '1';
				}
				if (raides1 != 0) {
					boardbot[raides1 - shipsize][skaiciai1] = '1';
				}

			}
		}
		else {
			for (int i = raides1; i <= raides1 + (shipsize - 1); i++) {
				if (boardbot[i][skaiciai1] == '1') { goto againn; break; }
			}
			for (int i = raides1; i <= raides1 + (shipsize - 1); i++) {
				boardbot[i][skaiciai1] = pataikyta;
				if (raides1 != 9) {
					boardbot[i][skaiciai1 + 1] = '1';
				}
				if (skaiciai1 != 0) {
					boardbot[i][skaiciai1 - 1] = '1';
				}
				if (raides1 != 9) {
					boardbot[raides1 + shipsize][skaiciai1] = '1';
				}
				if (raides1 != 0) {
					boardbot[raides1 - 1][skaiciai1] = '1';
				}
			}
		}

	}
	if (uporside == 1) { //laivas eina sonu nuo kaires i desine arba nuo desines i kaire
		if (skaiciai1 + shipsize >= 9) {
			for (int i = skaiciai1 - (shipsize - 1); i <= skaiciai1; i++) {
				if (boardbot[raides1][i] == '1') { goto againn; break; }
			}
			for (int i = skaiciai1 - (shipsize - 1); i <= skaiciai1; i++) {
				boardbot[raides1][i] = pataikyta;
				if (raides1 != 9) {
					boardbot[raides1 + 1][i] = '1';
				}
				if (raides1 != 0) {
					boardbot[raides1 - 1][i] = '1';
				}
				if (skaiciai1 != 9) {
					boardbot[raides1][skaiciai1 + 1] = '1';
				}
				if (skaiciai1 != 0) {
					boardbot[raides1][skaiciai1 - shipsize] = '1';
				}
			}
		}
		else {
			for (int i = skaiciai1; i <= skaiciai1 + (shipsize - 1); i++) {
				if (boardbot[raides1][i] == '1') { goto againn; break; }
			}
			for (int i = skaiciai1; i <= skaiciai1 + (shipsize - 1); i++) {
				boardbot[raides1][i] = pataikyta;
				if (raides1 != 9) {
					boardbot[raides1 + 1][i] = '1';
				}
				if (raides1 != 0) {
					boardbot[raides1 - 1][i] = '1';
				}
				if (skaiciai1 != 9) {
					boardbot[raides1][skaiciai1 + shipsize] = '1';
				}
				if (skaiciai1 != 0) {
					boardbot[raides1][skaiciai1 - 1] = '1';
				}
			}
		}
	}
}
void Bot::FixBotBoard() {
	int botshipamout = 0;
	srand(time(NULL));
	while (botshipamout != 17) {
		botshipamout = 0;
		BotPlaceships(carrier);
		BotPlaceships(battleship);
		BotPlaceships(cruiser);
		BotPlaceships(submarine);
		BotPlaceships(destroyer);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (boardbot[i][j] == '$') { botshipamout++; }
			}
		}
		if (botshipamout != 17) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					boardbot[i][j] = '~';
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (boardbot[i][j] == '1') {
				boardbot[i][j] = '~';
			}
		}
	}
}
void Bot::BotInvisible() {
	cout << endl;
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			cout << "   ";
		}
		cout << raides[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << skaiciai[i] << "  ";
		for (int j = 0; j < 10; j++) {

			cout << invisiblebot[i][j] << " ";
		}
		cout << endl;
	}
}
void Bot::WhereshipsareBot() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (boardbot[i][j] == '$') {
				laivupozbot.push_back(make_pair(j, i));
			}
		}
	}
	sort(laivupozbot.begin(), laivupozbot.end());
}