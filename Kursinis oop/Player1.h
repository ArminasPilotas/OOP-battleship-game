#pragma once
using namespace std;
class Player1 {
protected:
	char board1player[10][10];
	char invisible1player[10][10];
	char y1, y2, x1, x2;
	int kiekis;
public:
	Player1();
	~Player1();
	void Set1();
	void Draw1();
	void Invisible1();
	bool Convertcordinates1(char z, int z1);
	void Placeships1(int name);
};