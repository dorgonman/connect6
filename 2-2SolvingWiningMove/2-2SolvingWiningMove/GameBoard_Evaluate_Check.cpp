#include "GameControl.h"

bool GameBoard::checkT2(int state){

	if(state == Stone::BLACK){
			vector<GameLine*>::iterator it;
		for( it = bcolLine.begin(); it != bcolLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			if(linePattern->threat == 2){
				return true;
			}
		}



		
		for( it = browLine.begin(); it != browLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->threat == 2){
					return true;
				}
		}

		for( it = blrbiasLine.begin(); it != blrbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->threat == 2){
					return true;
				}

		}
		for( it = brlbiasLine.begin(); it != brlbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->threat == 2){
					return true;
				}
		}

	}else{

			
		vector<GameLine*>::iterator it;
		for( it = wcolLine.begin(); it != wcolLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			if(linePattern->threat == 2){
				return true;
			}
		}



		
		for( it = wrowLine.begin(); it != wrowLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->threat == 2){
					return true;
				}
		}

		for( it = wlrbiasLine.begin(); it != wlrbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->threat == 2){
					return true;
				}

		}
		for( it = wrlbiasLine.begin(); it != wrlbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->threat == 2){
					return true;
				}
		}



	
	}

	return false;

}




bool GameBoard::checkT1(int state){

	if(state == Stone::BLACK){
			vector<GameLine*>::iterator it;
		for( it = bcolLine.begin(); it != bcolLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			if(linePattern->threat == 1){
				return true;
			}
		}



		
		for( it = browLine.begin(); it != browLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->threat == 1){
					return true;
				}
		}

		for( it = blrbiasLine.begin(); it != blrbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->threat == 1){
					return true;
				}

		}
		for( it = brlbiasLine.begin(); it != brlbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->threat == 1){
					return true;
				}
		}

	}else{

			
		vector<GameLine*>::iterator it;
		for( it = wcolLine.begin(); it != wcolLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			if(linePattern->threat == 1){
				return true;
			}
		}



		
		for( it = wrowLine.begin(); it != wrowLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->threat == 1){
					return true;
				}
		}

		for( it = wlrbiasLine.begin(); it != wlrbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->threat == 1){
					return true;
				}

		}
		for( it = wrlbiasLine.begin(); it != wrlbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->threat == 1){
					return true;
				}
		}



	
	}

	return false;

}



bool GameBoard::checkPattern(int state, GameLine* pattern){
	if(state == Stone::BLACK){
	
		for(vector<GameLine*>::iterator it = bcolLine.begin(); it != bcolLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
			if(linePattern->size == pattern->size && 
				linePattern->endX == pattern->endX &&
				linePattern->endY == pattern->endY &&
				linePattern->condition == pattern->condition &&
				linePattern->state == pattern->state &&
				linePattern->BP == pattern->BP){
				return true;
			}
		}



		
		for(vector<GameLine*>::iterator it = browLine.begin(); it != browLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->size == pattern->size && 
					linePattern->endX == pattern->endX &&
					linePattern->endY == pattern->endY &&
					linePattern->condition == pattern->condition &&
					linePattern->state == pattern->state &&
					linePattern->BP == pattern->BP){
				return true;
				}
		}

		for(vector<GameLine*>::iterator it = blrbiasLine.begin(); it != blrbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->threat == 1){
					return true;
				}

		}
		for(vector<GameLine*>::iterator it = brlbiasLine.begin(); it != brlbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->size == pattern->size && 
				linePattern->endX == pattern->endX &&
				linePattern->endY == pattern->endY &&
				linePattern->condition == pattern->condition &&
				linePattern->state == pattern->state &&
				linePattern->BP == pattern->BP){
				return true;
				}
		}

	}else{

			
		for(vector<GameLine*>::iterator it = wcolLine.begin(); it != wcolLine.end(); it++ ){
			GameLine* line = *it;
			GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->size == pattern->size && 
				linePattern->endX == pattern->endX &&
				linePattern->endY == pattern->endY &&
				linePattern->condition == pattern->condition &&
				linePattern->state == pattern->state &&
				linePattern->BP == pattern->BP){
				return true;
			}
		}



		
		for(vector<GameLine*>::iterator it = wrowLine.begin(); it != wrowLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->size == pattern->size && 
					linePattern->endX == pattern->endX &&
					linePattern->endY == pattern->endY &&
					linePattern->condition == pattern->condition &&
					linePattern->state == pattern->state &&
					linePattern->BP == pattern->BP){
				return true;
				}
		}

		for(vector<GameLine*>::iterator it = wlrbiasLine.begin(); it != wlrbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->size == pattern->size && 
				linePattern->endX == pattern->endX &&
				linePattern->endY == pattern->endY &&
				linePattern->condition == pattern->condition &&
				linePattern->state == pattern->state &&
				linePattern->BP == pattern->BP){
				return true;
			}

		}
		for(vector<GameLine*>::iterator it = wrlbiasLine.begin(); it != wrlbiasLine.end(); it++ ){
				GameLine* line = *it;
				GameLine* linePattern = GameControl::getInstance()->getLinePattern(line);
				if(linePattern->size == pattern->size && 
				linePattern->endX == pattern->endX &&
				linePattern->endY == pattern->endY &&
				linePattern->condition == pattern->condition &&
				linePattern->state == pattern->state &&
				linePattern->BP == pattern->BP){
				return true;
				}
		}

	
	}


	return false;
}