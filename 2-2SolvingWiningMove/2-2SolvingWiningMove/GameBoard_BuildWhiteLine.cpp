#include "GameBoard.h"
#include "GameControl.h"




void GameBoard::buildWhiteLine(){
	//找白方的line pattern

		//column
		for(int i = 1; i <= 19; i++){
			GameLine* line = new GameLine(0);
			int size = 0;
			for(int j = 1; j <= 19; j++){
				if(board[i][j] == Stone::NOSTONE || board[i][j] == Stone::WHITE){
					if(board[i][j] == Stone::WHITE){
						line->state.set(size, true);
					}
					size++;
					line->endX = i;
					line->endY = j;
				}

				if(board[i][j] == Stone::BLACK || j == 19){

					if(size < 6 || line->state.to_ulong() == 0){//size小於6不可能贏，或者是線上沒有一顆黑子，因此不處理
						size = 0;
						line->state.reset();
					}else{
						line->size = size;
						wcolLine.push_back(line);
						line = new GameLine(0);
						size = 0;
					}
				}								
			}

			if(size < 6 || line->state.to_ulong() == 0){
				delete line;//回收這個多出來的line的記憶體
				line = NULL;
				
			}
		}


		/*cout << "column line pattern" << endl;
		int i = 0;
		vector<GameLine*>::iterator it;
		for( it = wcolLine.begin(); it != wcolLine.end(); it++ ){
			GameLine* line = *it;
			cout << "line:" << i << "size:" << line->size << endl;
			GameControl::getInstance()->showLine(line);
			i++;

		}
		system("pause");*/


		
		//row
		for(int j = 1; j <= 19; j++){
			GameLine* line = new GameLine(0);
			int size = 0;
			for(int i = 1; i <= 19; i++){
				//cout << i << j << endl;
				//cout << board[i][j] << endl;
				//system("PAUSE");
				if(board[i][j] == Stone::NOSTONE || board[i][j] == Stone::WHITE){
					if(board[i][j] == Stone::WHITE){
						line->state.set(size, true);
					}
					size++;
					line->endX = i;
					line->endY = j;
				}

				if(board[i][j] == Stone::BLACK || i == 19){
					if(size < 6 || line->state.to_ulong() == 0){//size小於6不可能贏，或者是線上沒有一顆黑子，因此不處理
						size = 0;
						line->state.reset();
					}else{
						line->size = size;
						wrowLine.push_back(line);
						line = new GameLine(0);
						size = 0;
					}
				}								
			}

			if(size < 6 || line->state.to_ulong() == 0){
				delete line;//回收這個多出來的line的記憶體
				line = NULL;
			}
		}

		
		/*int i = 0;
		vector<GameLine*>::iterator it;
		for( it = wrowLine.begin(); it != wrowLine.end(); it++ ){
			GameLine* line = *it;
			cout << "line:" << i << "size:" << line->size << endl;
			GameControl::getInstance()->showLine(line);
			i++;

		}*/



		//=====left to right=====================
		for(int i = 6; i <= 19; i++){
			GameLine* line = new GameLine(0);
			int size = 0;
			int bias = 0;
			for(int j = 1; j <= i; j++){

				//cout << j << ":" << i-bias << endl;
				//if(j == 8 && i-bias == 10){
					//cout << board[j][i - bias] << endl;
					//system("pause");
				//}
				//system("pause");
				if(board[j][i - bias] == Stone::NOSTONE || board[j][i - bias] == Stone::WHITE){
					if(board[j][i - bias] == Stone::WHITE){
						line->state.set(size, true);
					}
					size++;
					line->endX = j;
					line->endY = i - bias;
				}

				if(board[j][i - bias] == Stone::BLACK || j == i){//碰到牆壁或白子

					if(size < 6 || line->state.to_ulong() == 0){//size小於6不可能贏，或者是線上沒有一顆黑子，因此不處理
						size = 0;
						line->state.reset();
					}else{
						line->size = size;
						wlrbiasLine.push_back(line);
						line = new GameLine(0);
						size = 0;
					}
				}
				bias++;
			}

			if(size < 6 || line->state.to_ulong() == 0){
				delete line;//回收這個多出來的line的記憶體
				line = NULL;
				
			}
		}

		for(int i = 14; i >= 2; i--){//只到2，因為最中間那條在上面已經測過了
			GameLine* line = new GameLine(0);
			int size = 0;
			int bias = 0;
			for(int j = i; j <= 19; j++){

				//cout << j << ":" << 19 - bias << endl;
				if(board[j][19 - bias] == Stone::NOSTONE || board[j][19 - bias] == Stone::WHITE){
					if(board[j][19 - bias] == Stone::WHITE){
						line->state.set(size, true);
					}
					size++;
					line->endX = j;
					line->endY = 19 - bias;
				}

				if(board[j][19 - bias] == Stone::BLACK || j == 19){//碰到牆壁或白子

					if(size < 6 || line->state.to_ulong() == 0){//size小於6不可能贏，或者是線上沒有一顆黑子，因此不處理
						size = 0;
						line->state.reset();
					}else{
						line->size = size;
						wlrbiasLine.push_back(line);
						line = new GameLine(0);
						size = 0;
					}
				}
				bias++;
			
			}

			if(size < 6 || line->state.to_ulong() == 0){
				delete line;//回收這個多出來的line的記憶體
				line = NULL;
				
			}
		}

		/*cout << "left to right line pattern" << endl;

		 int i = 0;
		vector<GameLine*>::iterator it;
		for( it = wlrbiasLine.begin(); it != wlrbiasLine.end(); it++ ){
			GameLine* line = *it;
			cout << "line:" << i << "size:" << line->size << endl;
			GameControl::getInstance()->showLine(line);
			i++;

		}*/





		//===========right to left====================

		for(int i = 14; i >= 1; i--){
			GameLine* line = new GameLine(0);
			int size = 0;
			int bias = 0;
			for(int j = 1; j <= 20 - i; j++){


				//cout << i + bias << ":" << j << endl;
		

				//if(j == 8 && i-bias == 10){
					//cout << board[j][i - bias] << endl;
					//system("pause");
				//}
				//system("pause");
				if(board[i + bias][j] == Stone::NOSTONE || board[i + bias][j] == Stone::WHITE){
					if(board[i + bias][j] == Stone::WHITE){
						line->state.set(size, true);
					}
					size++;
					line->endX = i + bias;
					line->endY = j;
				}

				if(board[i + bias][j] == Stone::BLACK || j == 20 - i){

					if(size < 6 || line->state.to_ulong() == 0){//size小於6不可能贏，或者是線上沒有一顆黑子，因此不處理
						size = 0;
						line->state.reset();
					}else{
						line->size = size;
						wrlbiasLine.push_back(line);
						line = new GameLine(0);
						size = 0;
					}
				}
				bias++;
			}

			if(size < 6 || line->state.to_ulong() == 0){
				delete line;//回收這個多出來的line的記憶體
				line = NULL;
				
			}
		}


		for(int i = 6; i <= 18; i++){
			GameLine* line = new GameLine(0);
			int size = 0;
			int bias = 0;
			for(int j = 1; j <= i; j++){
				//cout << j << ":" <<  19 - i + bias  + 1<< endl;
				if(board[j][19 - i + bias  + 1] == Stone::NOSTONE || board[j][19 - i + bias  + 1] == Stone::WHITE){
					if(board[j][19 - i + bias  + 1] == Stone::WHITE){
						line->state.set(size, true);
					}
					size++;
					line->endX = j;
					line->endY = 19 - i + bias  + 1;
				}

				if(board[j][19 - i + bias  + 1] == Stone::BLACK || j == i){

					if(size < 6 || line->state.to_ulong() == 0){//size小於6不可能贏，或者是線上沒有一顆黑子，因此不處理
						size = 0;
						line->state.reset();
					}else{
						line->size = size;
						wrlbiasLine.push_back(line);
						line = new GameLine(0);
						size = 0;
					}
				}
				bias++;
			}
			if(size < 6 || line->state.to_ulong() == 0){
				delete line;//回收這個多出來的line的記憶體
				line = NULL;
				
			}
		}



	

		/*cout << "right to left line pattern" << endl;

		int i = 0;
		vector<GameLine*>::iterator it;
		for( it = wrlbiasLine.begin(); it != wrlbiasLine.end(); it++ ){
			GameLine* line = *it;
			cout << "line:" << i << "size:" << line->size << endl;
			GameControl::getInstance()->showLine(line);
			i++;

		}*/




}
