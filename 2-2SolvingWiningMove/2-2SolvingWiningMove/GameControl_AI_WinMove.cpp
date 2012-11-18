#include "GameControl.h"



bool GameControl::inputColumnWinMove(int state, GameBoard* game){
	if(state == Stone::WHITE){
		vector<GameLine*>::iterator it;
		for( it = game->wcolLine.begin(); it != game->wcolLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			if(linePattern->threat > 0){
				
				//system("cls");
				//GameControl::getInstance()->showLine(linePattern);
				//GameControl::getInstance()->showLine(line);
				int startY = linePattern->endY - linePattern->size + 1;
				for(int i = 0; i < linePattern->size; i++){
					GameLine tmpLine(linePattern->size);//每次都試著下二顆子去測看看哪二個位子能達到活6(因為輪到我們下時有threat，就代表已經勝利了)
					tmpLine.state = linePattern->state;
					tmpLine.state.set(i, true);
					tmpLine.endX = linePattern->endX;
					tmpLine.endY = linePattern->endY;
					
					//cout << startY << i << endl;

					int tmpState = tmpLine.state.to_ulong();;
					for(int j = i + 1; j < linePattern->size; j++){
						tmpLine.state.set(j, true);
						//cout << startY << j << endl;
						//GameControl::getInstance()->showLine(&tmpLine);
						GameLine* tmpLinePattern = GameControl::getInstance()->getLinePattern(&tmpLine);
						//cout << tmpLinePattern->condition << endl;
						if(tmpLinePattern->condition == 6){
							int startY = linePattern->endY - linePattern->size + 1;
							game->input(state, linePattern->endX, startY + i);
							game->input(state, linePattern->endX, startY + j);
							//cout << i << j << endl;
							//system("pause");

							return true;
						}
						tmpLine.state = tmpState;

					}				
				}
			}
		}
	}


	if(state == Stone::BLACK){
		vector<GameLine*>::iterator it;
		for( it = game->bcolLine.begin(); it != game->bcolLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			if(linePattern->threat > 0){
				
				//system("cls");
				//GameControl::getInstance()->showLine(linePattern);
				//GameControl::getInstance()->showLine(line);
				int startY = linePattern->endY - linePattern->size + 1;
				for(int i = 0; i < linePattern->size; i++){
					GameLine tmpLine(linePattern->size);//每次都試著下二顆子去測看看哪二個位子能達到活6(因為輪到我們下時有threat，就代表已經勝利了)
					tmpLine.state = linePattern->state;
					tmpLine.state.set(i, true);
					tmpLine.endX = linePattern->endX;
					tmpLine.endY = linePattern->endY;
					
					//cout << startY << i << endl;

					int tmpState = tmpLine.state.to_ulong();;
					for(int j = i + 1; j < linePattern->size; j++){
						tmpLine.state.set(j, true);
						//cout << startY << j << endl;
						//GameControl::getInstance()->showLine(&tmpLine);
						GameLine* tmpLinePattern = GameControl::getInstance()->getLinePattern(&tmpLine);
						//cout << tmpLinePattern->condition << endl;
						if(tmpLinePattern->condition == 6){
							int startY = linePattern->endY - linePattern->size + 1;
							game->input(state, linePattern->endX, startY + i);
							game->input(state, linePattern->endX, startY + j);
							//cout << i << j << endl;
							//system("pause");

							return true;
						}
						tmpLine.state = tmpState;

					}				
				}
			}
		}
	}

	return false;


}




bool GameControl::inputRowWinMove(int state, GameBoard* game){

	if(state == Stone::WHITE){
		vector<GameLine*>::iterator it;
		for( it = game->wrowLine.begin(); it != game->wrowLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			if(linePattern->threat > 0){
				
				//system("cls");
				//GameControl::getInstance()->showLine(linePattern);
				//GameControl::getInstance()->showLine(line);
				int startY = linePattern->endY - linePattern->size + 1;
				for(int i = 0; i < linePattern->size; i++){
					GameLine tmpLine(linePattern->size);//每次都試著下二顆子去測看看哪二個位子能達到活6(因為輪到我們下時有threat，就代表已經勝利了)
					tmpLine.state = linePattern->state;
					tmpLine.state.set(i, true);
					tmpLine.endX = linePattern->endX;
					tmpLine.endY = linePattern->endY;
					
					//cout << startY << i << endl;

					int tmpState = tmpLine.state.to_ulong();;
					for(int j = i + 1; j < linePattern->size; j++){
						tmpLine.state.set(j, true);
						//cout << startY << j << endl;
						//GameControl::getInstance()->showLine(&tmpLine);
						GameLine* tmpLinePattern = GameControl::getInstance()->getLinePattern(&tmpLine);
						//cout << tmpLinePattern->condition << endl;
						if(tmpLinePattern->condition == 6){
							int startX = linePattern->endX - linePattern->size + 1;
							game->input(state, startX + i, linePattern->endY);
							game->input(state, startX + j, linePattern->endY);
							//cout << i << j << endl;
							//system("pause");

							return true;
						}
						tmpLine.state = tmpState;

					}				
				}
			}
		}
	}


	if(state == Stone::BLACK){
		vector<GameLine*>::iterator it;
		for( it = game->browLine.begin(); it != game->browLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			if(linePattern->threat > 0){
				
				//system("cls");
				//GameControl::getInstance()->showLine(linePattern);
				//GameControl::getInstance()->showLine(line);
				int startY = linePattern->endY - linePattern->size + 1;
				for(int i = 0; i < linePattern->size; i++){
					GameLine tmpLine(linePattern->size);//每次都試著下二顆子去測看看哪二個位子能達到活6(因為輪到我們下時有threat，就代表已經勝利了)
					tmpLine.state = linePattern->state;
					tmpLine.state.set(i, true);
					tmpLine.endX = linePattern->endX;
					tmpLine.endY = linePattern->endY;
					
					//cout << startY << i << endl;

					int tmpState = tmpLine.state.to_ulong();;
					for(int j = i + 1; j < linePattern->size; j++){
						tmpLine.state.set(j, true);
						//cout << startY << j << endl;
						//GameControl::getInstance()->showLine(&tmpLine);
						GameLine* tmpLinePattern = GameControl::getInstance()->getLinePattern(&tmpLine);
						//cout << tmpLinePattern->condition << endl;
						if(tmpLinePattern->condition == 6){
							int startX = linePattern->endX - linePattern->size + 1;
			
							game->input(state, startX + i, linePattern->endY);
							game->input(state, startX + j, linePattern->endY);
							//cout << i << j << endl;
							//system("pause");

							return true;
						}
						tmpLine.state = tmpState;

					}				
				}
			}
		}
	}

	return false;




}



bool GameControl::inputLeftToRightWinMove(int state, GameBoard* game){

	if(state == Stone::WHITE){
		vector<GameLine*>::iterator it;
		for( it = game->wlrbiasLine.begin(); it != game->wlrbiasLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			if(linePattern->threat > 0){
				
				//system("cls");
				//GameControl::getInstance()->showLine(linePattern);
				//GameControl::getInstance()->showLine(line);
				int startY = linePattern->endY - linePattern->size + 1;
				for(int i = 0; i < linePattern->size; i++){
					GameLine tmpLine(linePattern->size);//每次都試著下二顆子去測看看哪二個位子能達到活6(因為輪到我們下時有threat，就代表已經勝利了)
					tmpLine.state = linePattern->state;
					tmpLine.state.set(i, true);
					tmpLine.endX = linePattern->endX;
					tmpLine.endY = linePattern->endY;
					
					//cout << startY << i << endl;

					int tmpState = tmpLine.state.to_ulong();;
					for(int j = i + 1; j < linePattern->size; j++){
						tmpLine.state.set(j, true);
						//cout << startY << j << endl;
						//GameControl::getInstance()->showLine(&tmpLine);
						GameLine* tmpLinePattern = GameControl::getInstance()->getLinePattern(&tmpLine);
						//cout << tmpLinePattern->condition << endl;
						if(tmpLinePattern->condition == 6){

							//cout << "start at:" << (char)((line->endX- line->size + 1) + 64) << line->endY + line->size - 1  << endl;
							//cout << "end at:" << (char)(line->endX+64) << line->endY << endl;
							int startX = linePattern->endX - linePattern->size + 1;
							int startY = linePattern->endY + linePattern->size - 1;

							//cout << startX << startY << endl;
							//cout << linePattern->endX << linePattern->endY << endl;
							//system("pause");
							//cout << i << j << endl;
		
							//system("pause");
							game->input(state, startX + i, startY - i);
							game->input(state, startX + j, startY - j);
							//cout << i << j << endl;
							//system("pause");

							return true;
						}
						tmpLine.state = tmpState;

					}				
				}
			}
		}
	}


	if(state == Stone::BLACK){
		vector<GameLine*>::iterator it;
		for( it = game->blrbiasLine.begin(); it != game->blrbiasLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			if(linePattern->threat > 0){
				
				//system("cls");
				//GameControl::getInstance()->showLine(linePattern);
				//GameControl::getInstance()->showLine(line);
				int startY = linePattern->endY - linePattern->size + 1;
				for(int i = 0; i < linePattern->size; i++){
					GameLine tmpLine(linePattern->size);//每次都試著下二顆子去測看看哪二個位子能達到活6(因為輪到我們下時有threat，就代表已經勝利了)
					tmpLine.state = linePattern->state;
					tmpLine.state.set(i, true);
					tmpLine.endX = linePattern->endX;
					tmpLine.endY = linePattern->endY;
					
					//cout << startY << i << endl;

					int tmpState = tmpLine.state.to_ulong();;
					for(int j = i + 1; j < linePattern->size; j++){
						tmpLine.state.set(j, true);
						//cout << startY << j << endl;
						//GameControl::getInstance()->showLine(&tmpLine);
						GameLine* tmpLinePattern = GameControl::getInstance()->getLinePattern(&tmpLine);
						//cout << tmpLinePattern->condition << endl;
						if(tmpLinePattern->condition == 6){

							int startX = linePattern->endX - linePattern->size + 1;
							int startY = linePattern->endY + linePattern->size - 1;
							game->input(state, startX + i, startY - i);
							game->input(state, startX + j, startY - j);

							return true;
						}
						tmpLine.state = tmpState;

					}				
				}
			}
		}
	}

	return false;
}

bool GameControl::inputRightToLeftWinMove(int state, GameBoard* game){

	
	if(state == Stone::WHITE){
		vector<GameLine*>::iterator it;
		for( it = game->wrlbiasLine.begin(); it != game->wrlbiasLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			if(linePattern->threat > 0){
				
				//system("cls");
				//GameControl::getInstance()->showLine(linePattern);
				//GameControl::getInstance()->showLine(line);
				int startY = linePattern->endY - linePattern->size + 1;
				for(int i = 0; i < linePattern->size; i++){
					GameLine tmpLine(linePattern->size);//每次都試著下二顆子去測看看哪二個位子能達到活6(因為輪到我們下時有threat，就代表已經勝利了)
					tmpLine.state = linePattern->state;
					tmpLine.state.set(i, true);
					tmpLine.endX = linePattern->endX;
					tmpLine.endY = linePattern->endY;
					
					//cout << startY << i << endl;

					int tmpState = tmpLine.state.to_ulong();;
					for(int j = i + 1; j < linePattern->size; j++){
						tmpLine.state.set(j, true);
						//cout << startY << j << endl;
						//GameControl::getInstance()->showLine(&tmpLine);
						GameLine* tmpLinePattern = GameControl::getInstance()->getLinePattern(&tmpLine);
						//cout << tmpLinePattern->condition << endl;
						if(tmpLinePattern->condition == 6){
							int startX = linePattern->endX - linePattern->size + 1;
							int startY = linePattern->endY - linePattern->size + 1;
							//cout << i << j << endl;
		
							//system("pause");
							game->input(state, startX + i, startY + i);
							game->input(state, startX + j, startY + j);
							//cout << i << j << endl;
							//system("pause");

							return true;
						}
						tmpLine.state = tmpState;

					}				
				}
			}
		}
	}



	if(state == Stone::BLACK){
		vector<GameLine*>::iterator it;
		for( it = game->brlbiasLine.begin(); it != game->brlbiasLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			if(linePattern->threat > 0){
				
				//system("cls");
				//GameControl::getInstance()->showLine(linePattern);
				//GameControl::getInstance()->showLine(line);
				int startY = linePattern->endY - linePattern->size + 1;
				for(int i = 0; i < linePattern->size; i++){
					GameLine tmpLine(linePattern->size);//每次都試著下二顆子去測看看哪二個位子能達到活6(因為輪到我們下時有threat，就代表已經勝利了)
					tmpLine.state = linePattern->state;
					tmpLine.state.set(i, true);
					tmpLine.endX = linePattern->endX;
					tmpLine.endY = linePattern->endY;
					
					//cout << startY << i << endl;

					int tmpState = tmpLine.state.to_ulong();;
					for(int j = i + 1; j < linePattern->size; j++){
						tmpLine.state.set(j, true);
						GameLine* tmpLinePattern = GameControl::getInstance()->getLinePattern(&tmpLine);
						if(tmpLinePattern->condition == 6){
							int startX = linePattern->endX - linePattern->size + 1;
							int startY = linePattern->endY - linePattern->size + 1;
						//	cout <<  linePattern->endX << linePattern->endY << endl;
							//system("pause");
							game->input(state, startX + i, startY + i);
							game->input(state, startX + j, startY + j);
							return true;
						}
						tmpLine.state = tmpState;

					}				
				}
			}
		}
	}

	return false;


}
bool GameControl::inputWinMove(int state, GameBoard* game){

	if(inputColumnWinMove(state, game)){
		return true;
	}

	if(inputRowWinMove(state, game)){
		return true;
	}

	if(inputLeftToRightWinMove(state, game)){
		return true;
	}

	
	if(inputRightToLeftWinMove(state, game)){
		return true;
	}

	


	if(state == Stone::BLACK){
	
	}

	return false;


}

