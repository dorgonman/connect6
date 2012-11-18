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
	short int endX;//�o���u�b�L���W�̫�I���������l
	short int endY;
	short int size;//line���X�Ӧ�l�Awall
	short int threat;//���X��threat;
	short int condition;//��3�Φ�3�άOĹ�����p
	short int BP;//best position�o���u�W�̦n�������I
	bitset<19> state;//�̦h�঳2^19��State-space
};


#endif