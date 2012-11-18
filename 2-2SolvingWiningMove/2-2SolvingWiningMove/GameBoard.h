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
	void buildLine();//建完之後就可以丟到資料庫去查
	
	void showBlackLine();
	void showWhiteLine();

	void clearLine();
	void clearSequence();
	bool input(int state, int gx, int gy);
	bool cancelOneInput();

	//看看棋盤是否已有6顆子連在一起
	int checkCondition();
	void reload();
	void saveSequence();
	float evaluateGame(int step, int state);
	void showSequence();
	//將自己複製一份深層Copy =>http://blog.monkeypotion.net/gameprog/pattern/prototype-pattern
	GameBoard* clone();


private:
	bool checkT2(int state);//查看看自己是不是有threat 2
	bool checkT1(int state);//查看看自己是不是有threat 2
	//查看看盤面上是否有這個linePattern
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
	int board[20][20];//index 0 不使用

	vector<Stone*> sequence;
public://存儲黑子的line pattern，找到之後還要去database做match才能用
	vector<GameLine*> browLine;
	vector<GameLine*> bcolLine;
	vector<GameLine*> blrbiasLine;//left to right
	vector<GameLine*> brlbiasLine;//right to left

public://儲存白子的line pattern
	vector<GameLine*> wrowLine;
	vector<GameLine*> wcolLine;
	vector<GameLine*> wlrbiasLine;//left to right
	vector<GameLine*> wrlbiasLine;//right to left
	int alpha;
	int beta;




};

#endif