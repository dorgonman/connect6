#include "GameLine.h"


	/*   �p�G����bitset���ܡA�n���ѽL���e�O�ΥH�U���覡�G
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

