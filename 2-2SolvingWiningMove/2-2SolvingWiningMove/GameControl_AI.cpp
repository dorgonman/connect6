#include "GameControl.h"


extern HGE* hge;



void GameControl::executeRandomAI(int state, GameBoard* game){

		//第一手會是黑子，只下一子，下在中間
	if(game->sequence.size() == 0){
		game->input(state, 10, 10);
		system("CLS");
		game->showSequence();
		return;

	}

	if(state == Stone::BLACK){
		int i = 0;

		while(i < 2){
			int gx = hge->Random_Int(1, 19);
			int gy = hge->Random_Int(1, 19);
			if(game->input(state, gx, gy)){
				system("CLS");
				game->showSequence();
				i++;
			}

			bool flag = false;
			for(int i = 1; i <= 19; i++){
				for(int j = 1; j <= 19; j++){
					if(game->board[i][j] == Stone::NOSTONE){
						flag = true;
					}
				}
			}
			if(!flag){
				return;
			}
		}
	
	}


	if(state == Stone::WHITE){
		int i = 0;

		while(i < 2){
			int gx = hge->Random_Int(1, 19);
			int gy = hge->Random_Int(1, 19);
			if(game->input(state, gx, gy)){

				system("CLS");
				game->showSequence();
				i++;
			}
			bool flag = false;
			for(int i = 1; i <= 19; i++){
				for(int j = 1; j <= 19; j++){
					if(game->board[i][j] == Stone::NOSTONE){
						flag = true;
					}
				}
			}
			if(!flag){
				return;
			}

		}
	}



}



void GameControl::executeAI(int state, GameBoard *game){


	

	//第一手會是黑子，只下一子，下在中間
	if(game->sequence.size() == 0){
		game->input(state, 10, 10);
		system("CLS");
		game->showSequence();
		return;

	}

	//如果我方有threat，就可以直接下二子下去得到勝利
	if(inputWinMove(state, game)){
		return;
	}


	//目前沒做搜尋，只有算分數來決定下法 
	inputBestMove(1, state, game);
	inputBestMove(2, state, game);

}