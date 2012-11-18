#include "GameBoard.h"
#include "GameControl.h"



void GameBoard::showBlackLine(){
	
	cout << "BLACK line" << endl;


	cout << "column line" << endl;
	int i = 0;
	vector<GameLine*>::iterator it;
	for( it = bcolLine.begin(); it != bcolLine.end(); it++ ){
		GameLine* line = *it;
		cout << "line:" << i << "  size:" << line->size << endl;
		cout << "start at:" << (char)(line->endX+64) << line->endY - line->size + 1 << endl;
		cout << "end at:" << (char)(line->endX+64) << line->endY << endl;
		GameControl::getInstance()->showLine(line);
		i++;

	}


	cout << endl;
	cout << "row line" << endl;

	i = 0;
	//vector<GameLine*>::iterator it;
	for( it = browLine.begin(); it != browLine.end(); it++ ){
			GameLine* line = *it;
			cout << "line:" << i << "  size:" << line->size << endl;
			cout << "start at:" << (char)((line->endX- line->size + 1) +64) << line->endY  << endl;
			cout << "end at:" << (char)(line->endX+64) << line->endY << endl;
			GameControl::getInstance()->showLine(line);
			i++;

	}


	cout << endl;
	cout << "left to right line" << endl;
	i = 0;
	for( it = blrbiasLine.begin(); it != blrbiasLine.end(); it++ ){
		GameLine* line = *it;
		cout << "line:" << i << "  size:" << line->size << endl;
		cout << "start at:" << (char)((line->endX- line->size + 1) + 64) << line->endY + line->size - 1  << endl;
		cout << "end at:" << (char)(line->endX+64) << line->endY << endl;
		GameControl::getInstance()->showLine(line);
		i++;
	}


	cout << endl;
	cout << "right to left line" << endl;

	i = 0;
	for( it = brlbiasLine.begin(); it != brlbiasLine.end(); it++ ){
			GameLine* line = *it;
			cout << "line:" << i << "  size:" << line->size << endl;
			cout << "start at:" << (char)((line->endX- line->size + 1) + 64) << line->endY - line->size + 1  << endl;
			cout << "end at:" << (char)(line->endX+64) << line->endY << endl;
			GameControl::getInstance()->showLine(line);
			i++;

	}

		cout << endl;


}





void GameBoard::showWhiteLine(){
	
	cout << "White line" << endl;


	cout << "column line" << endl;
	int i = 0;
	vector<GameLine*>::iterator it;
	for( it = wcolLine.begin(); it != wcolLine.end(); it++ ){
		GameLine* line = *it;
		cout << "line:" << i << "  size:" << line->size << endl;
		cout << "start at:" << (char)(line->endX+64) << line->endY - line->size + 1 << endl;
		cout << "end at:" << (char)(line->endX+64) << line->endY << endl;
		GameControl::getInstance()->showLine(line);
		i++;

	}

	cout << endl;


	cout << "row line" << endl;

	i = 0;
	//vector<GameLine*>::iterator it;
	for( it = wrowLine.begin(); it != wrowLine.end(); it++ ){
			GameLine* line = *it;
			cout << "line:" << i << "  size:" << line->size << endl;
			cout << "start at:" << (char)((line->endX- line->size + 1) +64) << line->endY  << endl;
			cout << "end at:" << (char)(line->endX+64) << line->endY << endl;
			GameControl::getInstance()->showLine(line);
			i++;

	}


	cout << endl;
	cout << "left to right line" << endl;
	i = 0;
	for( it = wlrbiasLine.begin(); it != wlrbiasLine.end(); it++ ){
		GameLine* line = *it;
		cout << "line:" << i << "  size:" << line->size << endl;
		cout << "start at:" << (char)((line->endX- line->size + 1) + 64) << line->endY + line->size - 1  << endl;
		cout << "end at:" << (char)(line->endX+64) << line->endY << endl;
		GameControl::getInstance()->showLine(line);
		i++;
	}
	cout << endl;


	cout << "right to left line" << endl;

	i = 0;
	for( it = wrlbiasLine.begin(); it != wrlbiasLine.end(); it++ ){
			GameLine* line = *it;
			cout << "line:" << i << "  size:" << line->size << endl;
			cout << "start at:" << (char)((line->endX- line->size + 1) + 64) << line->endY - line->size + 1  << endl;
			cout << "end at:" << (char)(line->endX+64) << line->endY << endl;
			GameControl::getInstance()->showLine(line);
			i++;

	}

		cout << endl;


}