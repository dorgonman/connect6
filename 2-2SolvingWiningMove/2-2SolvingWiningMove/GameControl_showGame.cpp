#include "GameControl.h"



void GameControl::showAllGameSequence(){
	vector<GameBoard*>::iterator it;
	for( it = games.begin(); it !=  games.end(); it++ ){
		GameBoard* game = *it;
		game->showSequence();

	}

	cout << endl;

}



