#include "GameDB.h"
#include "GameBoard.h"
#include "hgeresource.h"
#include "hge.h"
#include "hgegui.h"
#include "hgefont.h"


#ifndef GAME_CONTROL
#define GAME_CONTROL



class GameControl{
public:
	GameControl();
	~GameControl();
public://loading����
	void loadLine(char* fileName);
	void loadDB();
	void loadGame(char* fileName);

public://debug
	GameLine* getLine(int index);
	GameBoard* getGame(int index);
	void showLine(GameLine* line);
	void showAllLines();
	void showAllGameSequence();
public:
	void buildAllDatabases(int size);
	//��J�@��line�N��o��ӱ�line�һݭn��T 
	GameLine* getLinePattern(GameLine *line);
	void executeAI(int state, GameBoard* game);
	void executeRandomAI(int state, GameBoard* game);//���ե�
private:
	bool inputWinMove(int state, GameBoard* game);
	bool inputColumnWinMove(int state, GameBoard* game);
	bool inputRowWinMove(int state, GameBoard* game);
	bool inputLeftToRightWinMove(int state, GameBoard* game);
	bool inputRightToLeftWinMove(int state, GameBoard* game);
private:
	bool inputBestMove(int step, int state, GameBoard* game);
	//�̫�G�ӰѼƬO�ĴX��(�C�H�C��turn���i�H�U2��)��ثe�U���O�¦⪺�٬O�զ⪺
	float alphabeta(GameBoard* child, int depth, float alpha, float beta, int step, int state);
	Stone alphabetaF2(GameBoard* child, int depth, int step, Stone stone);
	Stone alphabetaG2(GameBoard* child, int depth, int step, Stone stone);
	Stone ABSSS(GameBoard* root, int depth, int step, Stone stone);





public:
	enum eControl{
		HUMAN = 0,
		COMPUTER = 1
	};

	int blackControl;
	int whiteControl;
	

public:
	static GameControl* getInstance();
	hgeResourceManager* rm;
	hgeSprite* whiteStoneSpr;
    hgeSprite* blackStoneSpr;


private:
	static GameControl* instance;
	vector<GameBoard*> games;



private:
	vector<GameLine*> lines;//���ե�
    vector<GameDB*> dbs;
	



};


#endif