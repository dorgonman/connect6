#include "GameDB.h"





void GameDB::saveDB(){

}


void GameDB::loadDB(FILE* saveData){


		if (saveData != NULL ) {
			int size = 0;

			fscanf(saveData, "%d", &size);
		//	cout << "size =" << pow(2.0, (double)size) << endl;
			//system("PAUSE");
			for(int i = 0; i < pow(2.0, (double)size); i++){
				char lable[50] = "";
				fscanf(saveData, "%s", lable);
				if(strcmp(lable, "line") == 0){
					GameLine* line = new GameLine(size);
					fscanf(saveData, "%d%d%d%d", &line->state, &line->threat, &line->condition, &line->BP);
					lineDB.push_back(line);
					//cout << line->state.to_ulong() << endl;
				}
			}
		}	

}

