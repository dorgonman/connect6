#include <vector>
using namespace std;

#include "Stone.h"
#include "GameLine.h"

#ifndef GAME_BOARD
#define GAME_BOARD




class GameBoard{
public:
	GameBoard();
	~GameBoard();
	void render();
	void buildLine();//�ا�����N�i�H����Ʈw�h�d
	
	void showBlackLine();
	void showWhiteLine();

	void clearLine();
	void clearSequence();
	bool input(int state, int gx, int gy);
	bool cancelOneInput();

	//�ݬݴѽL�O�_�w��6���l�s�b�@�_
	int checkCondition();
	void reload();
	void saveSequence();
	float evaluateGame(int step, int state);
	void showSequence();
	//�N�ۤv�ƻs�@���`�hCopy =>http://blog.monkeypotion.net/gameprog/pattern/prototype-pattern
	GameBoard* clone();


private:
	bool checkT2(int state);//�d�ݬݦۤv�O���O��threat 2
	bool checkT1(int state);//�d�ݬݦۤv�O���O��threat 2
	//�d�ݬݽL���W�O�_���o��linePattern
	bool checkPattern(int state, GameLine* pattern);


	


private:
	float evaluateBlackLine(int step, int state);
	float evaluateWhiteLine(int step, int state);
	float calculateScore(int step, int pState, int state, GameLine* linePattern);

public:
	enum eState{
		CONTINUE = -1,
		BLACKWIN = 0,
		WHITEWIN = 1
	};

private:


private:
	void buildBlackLine();
	void buildWhiteLine();

public:
	int board[20][20];//index 0 ���ϥ�

	vector<Stone*> sequence;
public://�s�x�¤l��line pattern�A��줧���٭n�hdatabase��match�~���
	vector<GameLine*> browLine;
	vector<GameLine*> bcolLine;
	vector<GameLine*> blrbiasLine;//left to right
	vector<GameLine*> brlbiasLine;//right to left

public://�x�s�դl��line pattern
	vector<GameLine*> wrowLine;
	vector<GameLine*> wcolLine;
	vector<GameLine*> wlrbiasLine;//left to right
	vector<GameLine*> wrlbiasLine;//right to left
	int alpha;
	int beta;




};

#endif