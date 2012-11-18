#include "GameLine.h"

#ifndef GAME_DB
#define GAME_DB
class GameDB{
public:
	GameDB();
	~GameDB();

	//�n�شX�h��db
	void buildDatabase(short int size);
	GameLine* getLinePattern(GameLine *line);
	void saveDB();
	void loadDB(FILE* saveData);


private:
	void computeLinePattern(GameLine* line);


private:
	vector<GameLine*> lineDB;
	short int lineSize;
	int nState;
};


#endif