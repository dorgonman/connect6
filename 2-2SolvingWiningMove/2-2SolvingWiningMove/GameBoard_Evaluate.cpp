#include "GameBoard.h"
#include "GameControl.h"


float GameBoard::calculateScore(int step, int pState, int state, GameLine* linePattern){

	int score = 0;

	if(state == pState){//先看對方有沒有threat，要優先擋，所以分數加的比較多
				
			GameLine tmpLine(0);
			tmpLine.endX = linePattern->endX;
			tmpLine.endY = linePattern->endY;
			tmpLine.size = linePattern->size;
			tmpLine.state = linePattern->state;
			for(int i = 0; i < tmpLine.size; i++){
				tmpLine.state.set(i, true);
				GameLine* tmpLinePattern = GameControl::getInstance()->getLinePattern(&tmpLine);
				if(tmpLinePattern->threat == 2){//追殺看看，這條line越長的會越有利
					score +=  2000;

				}
				tmpLine.state = linePattern->state;
			}

			
			if(linePattern->threat == 1){
				if(checkT2(state)){	
					score += 20000;//如果我方盤面上已經有一個threat2，那麼如果再找到一個threat 1的話就代表可以追勝
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
				if(tmpLinePattern->threat == 2){//被追殺
					score +=  4000;
				
				}
	
				tmpLine.state = linePattern->state;
			}

			if(linePattern->threat > 2){//輸了
				score = score + 10000000;
			}

			if(linePattern->threat == 2){
				score = score + 2000000;
			}
			if(linePattern->threat == 1){
				score = score + 1000000;
			}
			//======上面的必需優先處理================

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