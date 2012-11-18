#include "GameControl.h"




void GameControl::showAllLines(){
	int i = 0;
	vector<GameLine*>::iterator it;
	for( it = lines.begin(); it != lines.end(); it++ ){
		GameLine* line = *it;
		cout << "line:" << i << endl;
		showLine(line);
		i++;
	}
}



void GameControl::showLine(GameLine* line){

	for(int i = 0; i < line->size; i++){
		if(line->state.test(i)){
			printf("O");
		}else{
			printf(".");
		}
	}

	cout << endl;

	//cout << line->state.to_string() <<endl;

}




GameLine* GameControl::getLine(int index){
	if((int)lines.size() == 0){
		return NULL;
	}

	if(index > ((int)lines.size() - 1)){
		return lines[0]; 
	}

	return lines[index];
}


GameLine* GameControl::getLinePattern(GameLine *line){
	if(line->size < 6){
		return NULL;
	}

	if(dbs.size() == 0){
		return NULL;
	}
	GameLine* tmpLine = dbs[line->size - 6]->getLinePattern(line);
	tmpLine->endX = line->endX;
	tmpLine->endY = line->endY;
	tmpLine->state = line->state;

	return 	tmpLine;
}




void GameControl::buildAllDatabases(int size){
	//清除檔案內容
	FILE* saveData;
	fopen_s(&saveData, "db.dat", "w");
	fclose(saveData);

	for(int i = 6; i <= size; i++){
		GameDB* db = new GameDB();
		db->buildDatabase(i);
		dbs.push_back(db);
	}

}


void GameControl::loadLine(char* fileName){
	FILE* fileData;
	fopen_s(&fileData, fileName, "r");
	if ( fileData != NULL ) {
		while(!feof(fileData)){
			int size = 0;
			fscanf(fileData, "%d", &size);
			fgetc(fileData);//跳掉一個空格
			if(size > 0){
				GameLine* line = new GameLine(size);				
				for(int i = 0; i < size; i++){
					char ch;
					ch = fgetc(fileData);
					if(ch == 'O'){
						line->state.set(i, true);
						//game->state |= (1 << i);
					}
				}
			
				lines.push_back(line);
			}	
		}	
		fclose(fileData);
	}
}


void GameControl::loadDB(){
		FILE* saveData;
		fopen_s(&saveData,"db.dat", "r");

		if (saveData != NULL ){
			while(!feof(saveData)){
				GameDB* db = new GameDB();
				db->loadDB(saveData);
				dbs.push_back(db);		
			}
			fclose(saveData);
		}	

}