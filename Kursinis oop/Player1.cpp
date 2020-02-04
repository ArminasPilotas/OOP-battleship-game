#include "pch.h"
#include "Constants.h"

Player1::Player1() {
	y1 = 0; y2 = 0; x1 = 0; x2 = 0; kiekis = 0;
}
Player1::~Player1() {}
void Player1::Set1() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board1player[i][j] = '~';
			invisible1player[i][j] = '~';
		}
	}
}
void Player1::Draw1() {
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

			cout << board1player[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------";
	cout << endl;
}
void Player1::Invisible1() {
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

			cout << invisible1player[i][j] << " ";
		}
		cout << endl;
	}

}
bool Player1::Convertcordinates1(char z, int z1) {
	if (z == 'a'&&z1 < 10 && z1 >= 0) return true;
	else if (z == 'b'&&z1 < 10 && z1 >= 0) return true;
	else if (z == 'c'&&z1 < 10 && z1 >= 0) return true;
	else if (z == 'd'&&z1 < 10 && z1 >= 0) return true;
	else if (z == 'e'&&z1 < 10 && z1 >= 0) return true;
	else if (z == 'f'&&z1 < 10 && z1 >= 0) return true;
	else if (z == 'g'&&z1 < 10 && z1 >= 0) return true;
	else if (z == 'h'&&z1 < 10 && z1 >= 0) return true;
	else if (z == 'i'&&z1 < 10 && z1 >= 0) return true;
	else if (z == 'j'&&z1 < 10 && z1 >= 0) return true;

	else return false;

}
void Player1::Placeships1(int name) {
again:
	bool cantplace = false;
	int susiliecia = 0;
	Draw1();
	cout << "You entering " << name << " space ship" << endl;
	cout << "Enter first coordinate for example: A7 " << endl;
	cin >> x1 >> y1;
	y1 -= 48;
	if (isupper(x1)) {
		x1 = x1 + 32; //convert to lovercase
	}

	while (Convertcordinates1(x1, y1) != true) {
		cout << endl << "Bad input try again: " << endl;
		cin >> x1 >> y1;
		if (isupper(x1)) {
			x1 = x1 + 32; //convert to lovercase
		}
		y1 -= 48;
	}

	cout << endl << "Enter last coordinate for example: A8" << endl;
	cin >> x2 >> y2;
	y2 -= 48;
	if (isupper(x2)) {
		x2 = x2 + 32; //convert to lovercase
	}
	while (Convertcordinates1(x2, y2) != true) {
		cout << endl << "Bad input try again: " << endl;
		cin >> x2 >> y2;
		if (isupper(x2)) {
			x2 = x2 + 32; //convert to lovercase
		}
		y2 -= 48;
	}
	x1 = x1 - '0'; //convert to int
	x2 = x2 - '0'; //convert to int
	int x1temp = 0, x2temp = 0, y1temp = 0, y2temp = 0;
	x1temp = (x1 - 1) - 48;
	x2temp = (x2 - 1) - 48;
	y1temp = y1;
	y2temp = y2;
	if (x1 == x2 && y1temp > y2temp&&y1temp - y2temp == name - 1) {
		for (int i = y2temp; i <= y1temp; i++) {
			if (board1player[i][x2temp] == pataikyta)
			{
				cantplace = true;
				break;
			}
			if (x2temp != 0 && x2temp != 9) {
				if (board1player[i][x2temp - 1] == pataikyta || board1player[i][x2temp + 1] == pataikyta || board1player[y2temp - 1][x2temp] == pataikyta || board1player[y1temp + 1][x2temp] == pataikyta) { susiliecia++; }
			}
			if (x2temp == 0) {
				if (board1player[i][x2temp + 1] == pataikyta || board1player[y2temp - 1][x2temp] == pataikyta || board1player[y1temp + 1][x2temp] == pataikyta) { susiliecia++; }
			}
			if (x2temp == 9) {
				if (board1player[i][x2temp - 1] == pataikyta || board1player[y2temp - 1][x2temp] == pataikyta || board1player[y1temp + 1][x2temp] == pataikyta) { susiliecia++; }
			}


		}
		for (int i = y2temp; i <= y1temp; i++) {
			if (board1player[i][x2temp] != pataikyta && cantplace == false && susiliecia == 0) {
				board1player[i][x2temp] = pataikyta;
			}
		}
	}
	else if (x1 == x2 && y2 > y1&&y2 - y1 == name - 1) {
		for (int i = y1temp; i <= y2temp; i++) {
			if (board1player[i][x2temp] == pataikyta)
			{
				cantplace = true;
			}
			if (x1temp != 0 && x1temp != 9) {
				if (board1player[i][x2temp - 1] == pataikyta || board1player[i][x2temp + 1] == pataikyta || board1player[y2temp + 1][x2temp] == pataikyta || board1player[y1temp - 1][x2temp] == pataikyta) { susiliecia++; }
			}
			if (x1temp == 0) {
				if (board1player[i][x2temp + 1] == pataikyta || board1player[y2temp + 1][x2temp] == pataikyta || board1player[y1temp - 1][x2temp] == pataikyta) { susiliecia++; }
			}
			if (x1temp == 9) {
				if (board1player[i][x2temp - 1] == pataikyta || board1player[y2temp + 1][x2temp] == pataikyta || board1player[y1temp - 1][x2temp] == pataikyta) { susiliecia++; }
			}
		}
		for (int i = y1temp; i <= y2temp; i++) {
			if (board1player[i][x2temp] != pataikyta && cantplace == false && susiliecia == 0) {
				board1player[i][x2temp] = pataikyta;
			}
		}


	}
	else if (y1temp == y2temp && x1 > x2&&x1 - x2 == name - 1) {
		for (int i = x2temp; i <= x1temp; i++) {
			if (board1player[y1temp][i] == pataikyta)
			{
				cantplace = true;
			}
			if (x1temp != 9 && x2temp != 0) {
				if (board1player[y1temp - 1][i] == pataikyta || board1player[y1temp + 1][i] == pataikyta || board1player[y1temp][x2temp - 1] == pataikyta || board1player[y1temp][x1temp + 1] == pataikyta) { susiliecia++; }
			}
			if (x1temp == 9) {
				if (board1player[y1temp - 1][i] == pataikyta || board1player[y1temp + 1][i] == pataikyta || board1player[y1temp][x2temp - 1] == pataikyta) { susiliecia++; }
			}
			if (x2temp == 0) {
				if (board1player[y1temp - 1][i] == pataikyta || board1player[y1temp + 1][i] == pataikyta || board1player[y1temp][x1temp + 1] == pataikyta) { susiliecia++; }
			}
		}
		for (int i = x2temp; i <= x1temp; i++) {
			if (board1player[y1temp][i] != pataikyta && cantplace == false && susiliecia == 0) {
				board1player[y1temp][i] = pataikyta;
			}
		}
	}
	else if (y1temp == y2temp && x2 > x1&&x2 - x1 == name - 1) {
		for (int i = x1temp; i <= x2temp; i++) {
			if (board1player[y1temp][i] == pataikyta)
			{
				cantplace = true;
			}
			if (x2temp != 9 && x1temp != 0) {
				if (board1player[y1temp - 1][i] == pataikyta || board1player[y1temp + 1][i] == pataikyta || board1player[y1temp][x2temp + 1] == pataikyta || board1player[y1temp][x1temp - 1] == pataikyta) { susiliecia++; }
			}
			if (x2temp == 9) {
				if (board1player[y1temp - 1][i] == pataikyta || board1player[y1temp + 1][i] == pataikyta || board1player[y1temp][x1temp - 1] == pataikyta) { susiliecia++; }
			}
			if (x1temp == 0) {
				if (board1player[y1temp - 1][i] == pataikyta || board1player[y1temp + 1][i] == pataikyta || board1player[y1temp][x2temp + 1] == pataikyta) { susiliecia++; }
			}
		}
		for (int i = x1temp; i <= x2temp; i++) {
			if (board1player[y1temp][i] != pataikyta && cantplace == false && susiliecia == 0) {
				board1player[y1temp][i] = pataikyta;
			}
		}
	}

	else {
		system("cls");
		cout << endl << "Yours ship does not match the proportions enter " << name << " space ship" << endl;
		cout << endl;
		goto again;
	}
	if (cantplace == true) {
		system("cls");
		cout << endl << "These coordinates is already taken try again" << endl;
		goto again;
	}

	if (susiliecia != 0) {
		system("cls");
		cout << endl << "Yours ship make contact with each other try again" << endl;
		goto again;
	}




	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board1player[i][j] == pataikyta) {
				kiekis++;
			}
		}

	}
	if (kiekis == 17) {
		system("cls");
		Draw1();
		cout << endl << "Ships placed after 5 seconds game begins";
		Sleep(5000);
	}

	system("cls");
}