#include "stdlib.h"
#include "iostream"
#include <math.h>
#include <bitset>
#include "vector"


using namespace std;



#ifndef GAME_LINE
#define GAME_LINE

class GameLine{
public:
	~GameLine();
	GameLine(short int _size);

public:
	short int endX;//這條線在盤面上最後碰到牆壁的位子
	short int endY;
	short int size;//line有幾個位子，wall
	short int threat;//有幾個threat;
	short int condition;//活3或死3或是贏的狀況
	short int BP;//best position這條線上最好的攻擊點
	bitset<19> state;//最多能有2^19個State-space
};


#endif