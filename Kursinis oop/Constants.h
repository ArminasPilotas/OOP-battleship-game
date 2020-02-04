#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include "Menu.h"
#include "Bot.h"
#include "Player1.h"
#include "Player2.h"
#include "Game.h"
#include <iostream>
#include "Constants.h"
using namespace std;
const int destroyer = 2;
const int carrier = 5;
const int battleship = 4;
const int cruiser = 3;
const int submarine = 3;
const char raides[10] = { 'A','B','C','D','E','F','G','H','I','J' };
const int skaiciai[10] = { 0,1,2,3,4,5,6,7,8,9 };
const char pataikyta = '$';
const char nepataikyta = '*';
const char tikraipataikyta = 'X';