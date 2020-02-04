#include "pch.h"
#include "Constants.h"

void Game::BattlevsBot() {
	int scoreplayer = 0, scorebot = 0;
	int whoturn = 1;
	char xpla = 0, ypla = 0;
	int botx = 0, boty = 0;
	int yralaivas = 0;
	while (scoreplayer != 18 && scorebot != 18) {
		system("cls");
		if (whoturn == 1) {
			cout << "Your table" << endl;
			Draw1();
			cout << "Bot table" << endl;
			BotInvisible();
			cout << "Write cordinates where to hit for example A6" << endl;
			cin >> xpla >> ypla;
			ypla -= 48;
			if (isupper(xpla)) {
				xpla = xpla + 32; //convert to lovercase
			}

			while (Convertcordinates1(xpla, ypla) != true) {
				cout << endl << "Bad input try again: " << endl;
				cin >> xpla >> ypla;
				if (isupper(xpla)) {
					xpla = xpla + 32; //convert to lovercase
				}
				ypla -= 48;
			}
			xpla = xpla - '0';
			int xtemp = (xpla - 1) - 48;
			int ytemp = ypla;
			if (boardbot[ytemp][xtemp] == pataikyta) {
				scoreplayer++;
				invisiblebot[ytemp][xtemp] = tikraipataikyta;
				boardbot[ytemp][xtemp] = tikraipataikyta;
				if (boardbot[ytemp + 1][xtemp] == pataikyta || boardbot[ytemp - 1][xtemp] == pataikyta || boardbot[ytemp][xtemp + 1] == pataikyta || boardbot[ytemp][xtemp - 1] == pataikyta) {
					cout << endl << "You hit the enemy ship";
					Sleep(5000);
				}
				else {
					cout << "Ship destroyed" << endl;
					Sleep(5000);
				}
			}
			else if (boardbot[ytemp][xtemp] == tikraipataikyta || boardbot[ytemp][xtemp] == nepataikyta) {
				cout << endl << "This position is already hitted";
				Sleep(2000);
			}
			else if (boardbot[ytemp][xtemp] == '~') {
				invisiblebot[ytemp][xtemp] = nepataikyta;
				boardbot[ytemp][xtemp] = nepataikyta;
				cout << endl << "Missed...";
				whoturn = 2;
				Sleep(2000);
			}
		}
		if (scoreplayer == 17) {
			system("cls");
			cout << "You won the battleship!!!";
			Sleep(2000);
			break;
		}
		if (whoturn == 2) {
		letagain:
			system("cls");
			Draw1();
			BotInvisible();
			cout << endl << "Bot turn" << endl;
			srand(time(NULL));
			Sleep(1000);
			botx = rand() % 10;
			boty = rand() % 10;
		rr:
			if (board1player[boty][botx] == pataikyta) {

				scorebot++;
				board1player[boty][botx] = tikraipataikyta;
				if (board1player[boty + 1][botx] == pataikyta && board1player[boty - 1][botx] == pataikyta) {
					botx = botx;
					srand(time(NULL));
					if (rand() % 2 == 0) {
						boty = boty + 1;
					}
					else { boty = boty - 1; }
					system("cls");
					Draw1();
					BotInvisible();
					cout << endl << "Bot turn" << endl;
					cout << endl << "Your ship is hit";
					Sleep(5000);
					goto rr;
				}
				else if (board1player[boty][botx + 1] == pataikyta && board1player[boty][botx - 1] == pataikyta) {
					boty = boty;
					srand(time(NULL));
					if (rand() % 2 == 0) {
						botx = botx + 1;
					}
					else botx = botx - 1;
					system("cls");
					Draw1();
					BotInvisible();
					cout << endl << "Bot turn" << endl;
					cout << endl << "Your ship is hit";
					Sleep(5000);
					goto rr;
				}
				else if (board1player[boty + 1][botx] == pataikyta && board1player[boty - 1][botx] != pataikyta) {
					boty = boty + 1;
					botx = botx;
					system("cls");
					Draw1();
					BotInvisible();
					cout << endl << "Bot turn" << endl;
					cout << endl << "Your ship is hit";
					Sleep(5000);
					goto rr;
				}
				else if (board1player[boty - 1][botx] == pataikyta && board1player[boty + 1][botx] != pataikyta) {
					boty = boty - 1;
					botx = botx;
					system("cls");
					Draw1();
					BotInvisible();
					cout << endl << "Bot turn" << endl;
					cout << endl << "Your ship is hit";
					Sleep(5000);
					goto rr;
				}
				else if (board1player[boty][botx + 1] == pataikyta && board1player[boty][botx - 1] != pataikyta) {
					boty = boty;
					botx = botx + 1;
					system("cls");
					Draw1();
					BotInvisible();
					cout << endl << "Bot turn" << endl;
					cout << endl << "Your ship is hit";
					Sleep(5000);
					goto rr;
				}

				else if (board1player[boty][botx - 1] == pataikyta && board1player[boty][botx + 1] != pataikyta) {
					boty = boty;
					botx = botx - 1;
					system("cls");
					Draw1();
					BotInvisible();
					cout << endl << "Bot turn" << endl;
					cout << endl << "Your ship is hit";
					Sleep(5000);
					goto rr;
				}
				if (board1player[boty + 1][botx] == pataikyta || board1player[boty - 1][botx] == pataikyta || board1player[boty][botx + 1] == pataikyta || board1player[boty][botx - 1] == pataikyta) {
					cout << endl << "Your ship is hit";
					Sleep(5000);
				}
				else {
					cout << "Your ship is sunk" << endl;
					Sleep(5000);
				}
			}
			else if (board1player[boty][botx] == tikraipataikyta || board1player[boty][botx] == nepataikyta) {
				goto letagain;
			}
			else if (board1player[boty][botx] == '~') {
				board1player[boty][botx] = nepataikyta;
				cout << endl << "Missed";
				Sleep(2000);
				whoturn = 1;
			}
		}
		if (scorebot == 17) {
			system("cls");
			cout << "Bot won the battleship!!!";
			break;
		}
	}
}
void Game::Battlevsplayers() {
	char ejimas = 0;
	while (score1player != 18 && score2player != 18) {
		system("cls");
		char ejimas = 0;
		if (turn == 1) {
			cout << "Your table" << endl;
			Draw1();
			cout << "Enemy table" << endl;
			Invisible2();
			cout << "Write the coordinates where to hit for example: A6" << endl;
			cin >> x >> y;
			y -= 48;
			if (isupper(x)) {
				x = x + 32; //convert to lovercase
			}

			while (Convertcordinates1(x, y) != true) {
				cout << endl << "Bloga ivestis meginkite dar karta: " << endl;
				cin >> x >> y;
				if (isupper(x)) {
					x = x + 32; //convert to lovercase
				}
				y -= 48;
			}
			x = x - '0';
			int xtemp = (x - 1) - 48;
			int ytemp = y;
			if (board2player[ytemp][xtemp] == pataikyta) {
				if (board2player[ytemp + 1][xtemp] == pataikyta || board2player[ytemp - 1][xtemp] == pataikyta || board2player[ytemp][xtemp + 1] == pataikyta || board2player[ytemp][xtemp - 1] == pataikyta) {
					cout << endl << "You hit enemy ship";
					invisible2player[ytemp][xtemp] = tikraipataikyta;
					board2player[ytemp][xtemp] = tikraipataikyta;
					score1player++;
					Sleep(2000);
				}
				else {
					cout << endl << "You knock down your opponent's ship";
					invisible2player[ytemp][xtemp] = tikraipataikyta;
					board2player[ytemp][xtemp] = tikraipataikyta;
					score1player++;
					Sleep(2000);
				}

			}
			else if (board2player[ytemp][xtemp] == tikraipataikyta || board2player[ytemp][xtemp] == nepataikyta) {
				cout << endl << "This coordinate is already hitted, choose another one: ";
				Sleep(2000);
			}
			else if (board2player[ytemp][xtemp] == '~') {
				invisible2player[ytemp][xtemp] = nepataikyta;
				board2player[ytemp][xtemp] = nepataikyta;
				cout << endl << "Missed...";
				ejimas = '0';
				while (ejimas != '1') {
					cout << endl << "End turn? 1/0";
					cin >> ejimas;
				}
				turn = 2;


			}
			if (score1player == 17) {
				system("cls");
				cout << endl << "1 Player won the battleship!!!";
				break;
			}

		}
		if (turn == 2) {
			system("cls");
			cout << "Your table " << endl;
			Draw2();
			cout << "Enemy table" << endl;
			Invisible1();
			cout << "Enter the coordinates where to hit for example: A6" << endl;
			cin >> x >> y;
			y -= 48;
			if (isupper(x)) {
				x = x + 32; //convert to lovercase
			}

			while (Convertcordinates2(x, y) != true) {
				cout << endl << "Bad input try again: " << endl;
				cin >> x >> y;
				if (isupper(x)) {
					x = x + 32; //convert to lovercase
				}
				y -= 48;
			}
			x = x - '0';
			int xtemp = (x - 1) - 48;
			int ytemp = y;
			if (board1player[ytemp][xtemp] == pataikyta) {
				if (board1player[ytemp + 1][xtemp] == pataikyta || board1player[ytemp - 1][xtemp] == pataikyta || board1player[ytemp][xtemp + 1] == pataikyta || board1player[ytemp][xtemp - 1] == pataikyta) {
					cout << endl << "You hit a enemy ship";
					invisible1player[ytemp][xtemp] = tikraipataikyta;
					board1player[ytemp][xtemp] = tikraipataikyta;
					score2player++;
					Sleep(2000);
				}
				else {
					cout << endl << "Enemy ship is sunk";
					invisible1player[ytemp][xtemp] = tikraipataikyta;
					board1player[ytemp][xtemp] = tikraipataikyta;
					score2player++;
					Sleep(2000);
				}

			}
			else if (board1player[ytemp][xtemp] == tikraipataikyta || board1player[ytemp][xtemp] == nepataikyta) {
				cout << endl << "This coordinate is already hitted, choose another one: ";
				Sleep(2000);
			}
			else if (board1player[ytemp][xtemp] == '~') {
				invisible1player[ytemp][xtemp] = nepataikyta;
				board1player[ytemp][xtemp] = nepataikyta;
				cout << endl << "Missed...";
				ejimas = '0';
				while (ejimas != '1') {
					cout << endl << "End turn? 1/0";
					cin >> ejimas;
				}
				turn = 1;


			}
			if (score2player == 17) {
				system("cls");
				cout << endl << "2 player won the battleship!!!";
				break;
			}
		}

	}
}