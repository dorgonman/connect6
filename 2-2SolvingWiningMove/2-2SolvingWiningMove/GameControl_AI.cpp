#include "GameControl.h"


extern HGE* hge;



void GameControl::executeRandomAI(int state, GameBoard* game){

		//�Ĥ@��|�O�¤l�A�u�U�@�l�A�U�b����
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


	

	//�Ĥ@��|�O�¤l�A�u�U�@�l�A�U�b����
	if(game->sequence.size() == 0){
		game->input(state, 10, 10);
		system("CLS");
		game->showSequence();
		return;

	}

	//�p�G�ڤ観threat�A�N�i�H�����U�G�l�U�h�o��ӧQ
	if(inputWinMove(state, game)){
		return;
	}


	//�ثe�S���j�M�A�u������ƨӨM�w�U�k 
	inputBestMove(1, state, game);
	inputBestMove(2, state, game);

}