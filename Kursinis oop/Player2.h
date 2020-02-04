#pragma once
using namespace std;
class Player2 {
protected:
	char board2player[10][10];
	char invisible2player[10][10];
	char y1, y2, x1, x2;
	int kiekis;
public:
	Player2();
	void Set2();
	void Draw2();
	void Invisible2();
	bool Convertcordinates2(char z, int z1);
	void Placeships2(int name);
};