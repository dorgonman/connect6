#include "GameControl.h"




GameBoard* GameControl::getGame(int index){
	if((int)games.size() == 0){
		return NULL;
	}

	if(index > ((int)games.size() - 1)){
		return games[0]; 
	}

	return games[index];
}


void GameControl::loadGame(char* fileName){

	FILE* fileData;
	fopen_s(&fileData, fileName, "r");
	if ( fileData != NULL ) {
		while(!feof(fileData)){
			bool state = Stone::BLACK;
			char cx = fgetc(fileData);
			//printf("another game\n");
			if(feof(fileData)){
				break;
			}
			GameBoard* game = new GameBoard();
			int gy;
			fscanf(fileData, "%d", &gy);
			int gx = (int)(toupper(cx)) - 64;
			game->sequence.push_back(new Stone(state, gx, gy));
			game->board[gx][gy] = state;

			state = !state;
			cx = fgetc(fileData);//拿掉一個空格

			int flag = 0;
			while(cx != '\n' && !feof(fileData)){
				if(cx == ' '){
					cx = fgetc(fileData);
					continue;
				}
				fscanf(fileData, "%d", &gy);
				
				game->sequence.push_back(new Stone(state, (int)(toupper(cx)) - 64, gy));
				gx = (int)(toupper(cx)) - 64;
				game->board[gx][gy] = state;



				//偵測是否換另一方下了
				flag++;
				if(flag % 2 == 0){
					flag = 0;
					state = !state;
				}
				cx = fgetc(fileData);//拿掉空格

			}

			this->games.push_back(game);

			

			//int position;
			//fscanf(fileData, "%d", &position);
			//cout << position << endl;
		}
		fclose(fileData);
	}

	//cout << "end of game" << endl;


}

