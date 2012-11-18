#include "GameBoard.h"
#include "GameControl.h"
GameBoard::GameBoard(){
	memset(board, -1, sizeof(board));
	alpha = -inf;
	beta = inf;
}



GameBoard::~GameBoard(){

	clearSequence();
	clearLine();


}



void GameBoard::reload(){
	memset(board, -1, sizeof(board));
	clearLine();
	clearSequence();
}


void GameBoard::render(){

	for(int i = 1; i <= 19; i++){
		for(int j = 1; j <= 19; j++){
			if(board[i][j] != -1){
				if(board[i][j] == Stone::WHITE){
					GameControl::getInstance()->whiteStoneSpr->Render( i * 24, 480 - j * 24);
				}else{
					GameControl::getInstance()->blackStoneSpr->Render( i * 24, 480 - j * 24);
				}
			}
		
		}
	
	}



}



bool GameBoard::input(int state, int gx, int gy){

	if(gx > 19 || gy > 19 || gx < 1 || gy < 1){
		//cout << "invalid position" << endl;
		return false;
	}

	if(board[gx][gy] == Stone::NOSTONE){
		board[gx][gy] = state;
		Stone* stone = new Stone(state, gx, gy);
		sequence.push_back(stone);
		clearLine();
		buildLine();
		return true;
	}
//	cout << "the position is occupied" << endl;
	return false;
}

bool GameBoard::cancelOneInput(){
	if(sequence.size() == 0){
		return false;
	}
	vector<Stone*>::iterator it = --sequence.end();
	Stone* stone = *it;
	board[stone->gx][stone->gy] = Stone::NOSTONE;
	delete stone;
	stone = NULL;

	sequence.erase(it);
	saveSequence();
	return true;

}

void GameBoard::clearSequence(){
	vector<Stone*>::iterator it;
	for( it = sequence.begin(); it != sequence.end(); it++ ){
		Stone* stone = *it;
		delete stone;
		stone = NULL;
	}
	sequence.clear();


}



void GameBoard::buildLine(){
	clearLine();
	buildBlackLine();
	buildWhiteLine();
}






void GameBoard::clearLine(){

	//==================清掉黑子===================
	vector<GameLine*>::iterator it;
	for( it = bcolLine.begin(); it != bcolLine.end(); it++ ){
		GameLine* line = *it;
		delete line;
		line = NULL;
	}
	bcolLine.clear();


	for( it = browLine.begin(); it != browLine.end(); it++ ){
			GameLine* line = *it;
			delete line;
			line = NULL;

	}
	browLine.clear();

	for( it = blrbiasLine.begin(); it != blrbiasLine.end(); it++ ){
		GameLine* line = *it;
		delete line;
		line = NULL;
	}

	blrbiasLine.clear();


	for( it = brlbiasLine.begin(); it != brlbiasLine.end(); it++ ){
			GameLine* line = *it;
			delete line;
			line = NULL;
	}
	brlbiasLine.clear();




	//================清掉白子=====================

	for( it = wcolLine.begin(); it != wcolLine.end(); it++ ){
		GameLine* line = *it;
		delete line;
		line = NULL;
	}
	wcolLine.clear();


	for( it = wrowLine.begin(); it != wrowLine.end(); it++ ){
			GameLine* line = *it;
			delete line;
			line = NULL;

	}
	wrowLine.clear();

	for( it = wlrbiasLine.begin(); it != wlrbiasLine.end(); it++ ){
		GameLine* line = *it;
		delete line;
		line = NULL;
	}

	wlrbiasLine.clear();


	for( it = wrlbiasLine.begin(); it != wrlbiasLine.end(); it++ ){
			GameLine* line = *it;
			delete line;
			line = NULL;
	}
	wrlbiasLine.clear();




}



int GameBoard::checkCondition(){
	int condition = CONTINUE;

	//==================黑子===================
	vector<GameLine*>::iterator it;
	for( it = bcolLine.begin(); it != bcolLine.end(); it++ ){
		GameLine* line = *it;
		GameLine* tmpLine = GameControl::getInstance()->getLinePattern(line);

		if(tmpLine != NULL){
			if(tmpLine->condition == 6){
				condition = BLACKWIN;
			}
		}


	}



	for( it = browLine.begin(); it != browLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* tmpLine = GameControl::getInstance()->getLinePattern(line);
			if(tmpLine != NULL){
				if(tmpLine->condition == 6){
					condition = BLACKWIN;
				}
			}


	}


	for( it = blrbiasLine.begin(); it != blrbiasLine.end(); it++ ){
		GameLine* line = *it;
		GameLine* tmpLine = GameControl::getInstance()->getLinePattern(line);
		if(tmpLine != NULL){
			if(tmpLine->condition == 6){
				condition = BLACKWIN;
			}
		}


	}




	for( it = brlbiasLine.begin(); it != brlbiasLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* tmpLine = GameControl::getInstance()->getLinePattern(line);
			if(tmpLine != NULL){
				if(tmpLine->condition == 6){
					condition = BLACKWIN;
				}
			}


	}





	//================白子=====================

	for( it = wcolLine.begin(); it != wcolLine.end(); it++ ){
		GameLine* line = *it;
		GameLine* tmpLine = GameControl::getInstance()->getLinePattern(line);

		if(tmpLine != NULL){
			if(tmpLine->condition == 6){
				condition = WHITEWIN;
			}
		}


	}



	for( it = wrowLine.begin(); it != wrowLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* tmpLine = GameControl::getInstance()->getLinePattern(line);
			if(tmpLine != NULL){
				if(tmpLine->condition == 6){
					condition = WHITEWIN;
				}
			}



	}


	for( it = wlrbiasLine.begin(); it != wlrbiasLine.end(); it++ ){
		GameLine* line = *it;
		GameLine* tmpLine = GameControl::getInstance()->getLinePattern(line);
		if(tmpLine != NULL){
			if(tmpLine->condition == 6){
				condition = WHITEWIN;
			}
		}


	}




	for( it = wrlbiasLine.begin(); it != wrlbiasLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* tmpLine = GameControl::getInstance()->getLinePattern(line);
			if(tmpLine != NULL){
				if(tmpLine->condition == 6){
					condition = WHITEWIN;
				}
			}

	}


	return condition;

}




void GameBoard::saveSequence(){
	FILE* saveData;
	fopen_s(&saveData, "sequenceLog.dat", "w");
	vector<Stone*>::iterator it;
	for( it = sequence.begin(); it != sequence.end(); it++ ){
		Stone* stone = *it;
		fprintf(saveData, "%c%d", (char)(stone->gx+ 64), stone->gy);
		fprintf(saveData, " ");
	}

	fclose(saveData);


}


void GameBoard::showSequence(){
		cout << "game total sequence:" << sequence.size() << endl;
		int i = 0;
		vector<Stone*>::iterator it;
		for( it = sequence.begin(); it !=  sequence.end(); it++ ){
			Stone* p = *it;
			if(p->state == Stone::BLACK){
				cout << "black:";
			}else{
				cout << "white:";
			}

			cout << (char)(p->gx + 64) << p->gy << ' ' ;

			i++;
			int step = (int)((float)i / 2 + 0.5);
			int turn = step % 2;
			if(turn != p->state){
				cout << endl;
			}
		
		}
		cout << endl;


}

GameBoard* GameBoard::clone(){
	GameBoard* cloneObj = new GameBoard();

	//cloneObj->sequence = sequence;
	for(vector<Stone*>::iterator it = sequence.begin(); it !=  sequence.end(); it++ ){
		Stone* p = *it;
		cloneObj->sequence.push_back(new Stone(p->state, p->gx, p->gy));
	}
	memcpy(cloneObj->board, board, sizeof(board));
	return cloneObj;
}