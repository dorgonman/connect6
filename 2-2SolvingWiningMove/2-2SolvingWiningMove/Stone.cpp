#include "Stone.h"
#include "GameControl.h"



Stone::Stone(int _state,int _gx, int _gy){
		state = _state;
		gx = _gx;
		gy = _gy;
		alpha = -inf;
		beta = inf;
		score = 0;


}


Stone::~Stone(){


}