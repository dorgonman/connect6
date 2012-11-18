#include "GameBoard.h"
#include "GameControl.h"


float GameBoard::calculateScore(int step, int pState, int state, GameLine* linePattern){

	int score = 0;

	if(state == pState){//���ݹ�観�S��threat�A�n�u���סA�ҥH���ƥ[������h
				
			GameLine tmpLine(0);
			tmpLine.endX = linePattern->endX;
			tmpLine.endY = linePattern->endY;
			tmpLine.size = linePattern->size;
			tmpLine.state = linePattern->state;
			for(int i = 0; i < tmpLine.size; i++){
				tmpLine.state.set(i, true);
				GameLine* tmpLinePattern = GameControl::getInstance()->getLinePattern(&tmpLine);
				if(tmpLinePattern->threat == 2){//�l���ݬݡA�o��line�V�����|�V���Q
					score +=  2000;

				}
				tmpLine.state = linePattern->state;
			}

			
			if(linePattern->threat == 1){
				if(checkT2(state)){	
					score += 20000;//�p�G�ڤ�L���W�w�g���@��threat2�A����p�G�A���@��threat 1���ܴN�N��i�H�l��
				}
			}

			if(linePattern->threat > 2){
				score = score + 20000;
			}

			if(linePattern->threat == 2){
				score = score + 10000;
			}

			if(linePattern->threat == 1){
				score = score + 5000;
			}

			if(linePattern->condition == 3){
				score = score + 2500;
			}

			if(linePattern->condition == -3){
				score = score + 1250;
			
			}

			
			if(linePattern->condition == 2){
				score = score + 700;
			}

			if(linePattern->condition == -2){
				score = score + 300;
			}
			
			
			if(linePattern->condition == 1){
				score = score + 200;
			
			}

			if(linePattern->condition == -1){
				score = score + 75.125;
			}
		
		}else{
				
			GameLine tmpLine(0);
			tmpLine.endX = linePattern->endX;
			tmpLine.endY = linePattern->endY;
			tmpLine.size = linePattern->size;
			tmpLine.state = linePattern->state;
			for(int i = 0; i < tmpLine.size; i++){
				tmpLine.state.set(i, true);
				GameLine* tmpLinePattern = GameControl::getInstance()->getLinePattern(&tmpLine);
				if(tmpLinePattern->threat == 2){//�Q�l��
					score +=  4000;
				
				}
	
				tmpLine.state = linePattern->state;
			}

			if(linePattern->threat > 2){//��F
				score = score + 10000000;
			}

			if(linePattern->threat == 2){
				score = score + 2000000;
			}
			if(linePattern->threat == 1){
				score = score + 1000000;
			}
			//======�W���������u���B�z================

			if(linePattern->condition == 3){
				score = score + 5000;
			
			}


			if(linePattern->condition == -3){
				score = score + 2500;
			
			}

			
			if(linePattern->condition == 2){
				score = score + 1300;
			
			}
			if(linePattern->condition == -2){
				score = score + 625;
			}
			
			
			if(linePattern->condition == 1){
				score = score + 320.5;
			
			}

			if(linePattern->condition == -1){
				score = score + 106.25;
			}

			if(linePattern->BP > 0){
				score +=2;
			}

		}

	return score;
}



float GameBoard::evaluateBlackLine(int step, int state){
	float score = 0;

	//if(state == Stone::BLACK){
		vector<GameLine*>::iterator it;
		for( it = bcolLine.begin(); it != bcolLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			score += calculateScore(step, Stone::BLACK, state, linePattern);

		}



		
		for( it = browLine.begin(); it != browLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				score += calculateScore(step, Stone::BLACK, state, linePattern);

		}

		for( it = blrbiasLine.begin(); it != blrbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				score += calculateScore(step,Stone::BLACK, state, linePattern);
				score += 2;


		}
		for( it = brlbiasLine.begin(); it != brlbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				score += calculateScore(step,Stone::BLACK, state, linePattern);
				score += 2;


		}

	/*}else{
			vector<GameLine*>::iterator it;
		for( it = bcolLine.begin(); it != bcolLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			score += calculateScore2(Stone::BLACK, state, linePattern);

		}



		
		for( it = browLine.begin(); it != browLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				score += calculateScore2(Stone::BLACK, state, linePattern);

		}

		for( it = blrbiasLine.begin(); it != blrbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				score += calculateScore2(Stone::BLACK, state, linePattern);


		}
		for( it = brlbiasLine.begin(); it != brlbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				score += calculateScore2(Stone::BLACK, state, linePattern);


		}

	}*/



	return score;
}


float GameBoard::evaluateWhiteLine(int step, int state){
	vector<Stone*>::iterator i = --sequence.end();
	Stone* stone = *i;

	float score = 0;

	//if(state == Stone::BLACK){
		vector<GameLine*>::iterator it;
		for( it = wcolLine.begin(); it != wcolLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			score += calculateScore(step, Stone::WHITE, state, linePattern);
		}



		
		for( it = wrowLine.begin(); it != wrowLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				score += calculateScore(step, Stone::WHITE, state, linePattern);
		}

		for( it = wlrbiasLine.begin(); it != wlrbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				score += calculateScore(step, Stone::WHITE, state, linePattern);
				score += 2;


		}
		for( it = wrlbiasLine.begin(); it != wrlbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				score += calculateScore(step, Stone::WHITE, state, linePattern);
				score += 2;

		}
	/*}else{

		vector<GameLine*>::iterator it;
		for( it = wcolLine.begin(); it != wcolLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			score += calculateScore2(Stone::WHITE, state, linePattern);
		}



		
		for( it = wrowLine.begin(); it != wrowLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				score += calculateScore2(Stone::WHITE, state, linePattern);
		}

		for( it = wlrbiasLine.begin(); it != wlrbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				score += calculateScore2(Stone::WHITE, state, linePattern);


		}
		for( it = wrlbiasLine.begin(); it != wrlbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				score += calculateScore2(Stone::WHITE, state, linePattern);

		}
	
	
	
	}*/




	return score;
}

float GameBoard::evaluateGame(int step, int state){
	if(sequence.size() == 0){
		return 0;
	}
	vector<Stone*>::iterator it = --sequence.end();
	Stone* stone = *it;

	float blackScore = evaluateBlackLine(step, state);
	float whiteScore = evaluateWhiteLine(step, state);

	if(state == Stone::BLACK){
		return blackScore - whiteScore;
	}

	if(state == Stone::WHITE){
		return whiteScore - blackScore;
	}


	return 0;
}