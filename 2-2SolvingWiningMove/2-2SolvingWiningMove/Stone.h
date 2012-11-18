#include "hgeSprite.h"
#include "hgeresource.h"
#include "iostream"
using namespace std;



#ifndef GAME_STONE
#define GAME_STONE
#define inf 3.4028234663852886E+38F
class Stone{

public:
	Stone(int _state, int _gx, int _gy);
	~Stone();

public:
	enum eState{
		NOSTONE = -1,
		BLACK = 0,
		WHITE = 1
	};
	short int state;//0為黑子、1為白子
	short int gx;//1234 col
	short int gy;//1234 row

	float alpha;
	float beta;
	float score;


};

#endif