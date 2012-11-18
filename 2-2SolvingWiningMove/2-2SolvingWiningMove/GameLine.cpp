#include "GameLine.h"


	/*   如果不用bitset的話，要拿棋盤內容是用以下的方式：
			for(int i = 0; i < nPosition; i++){
				if(board & (int)pow(2.0, i)){
					printf("O");
				}else{
					printf(".");
				}

	}*/


GameLine::~GameLine(){

}


GameLine::GameLine(short int  _size){
	size = _size;
	state.reset();
	//cout << "position:" << nPosition << endl;
	threat = 0;
	condition = 0;
	state = 0;
	BP = -1;
	endX = -1;
	endY = -1;

}

