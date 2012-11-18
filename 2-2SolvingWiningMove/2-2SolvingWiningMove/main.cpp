#include "GameControl.h"
#include <windows.h>



void linePattern();
void initialize();
void loadResource();
bool FrameFunc();
void startGame();
void shutdown();
void redirectIOToConsole();






GameControl* gameControl;
hgeSprite* boardSpr;
hgeSprite* squareSpr;

HGE *hge = 0;
hgeGUI* gui;
hgeFont* fnt;
float dt = 0;
bool bstart = false;

void main(){
	
	//cout << (int)toupper('A') - 64 << endl;
	//system("PAUSE");


	//redirectIOToConsole();

	initialize();


	if(hge->System_Initiate()){

		loadResource();

	
		hge->System_Start();
	}

	shutdown();

	system("PAUSE");
	

}
GameBoard* newGame;


void startGame(){



	
	


	dt += hge->Timer_GetDelta();
	fnt->printf(510, 20, HGETEXT_LEFT, "time passed:%.0fs", dt);

	
	newGame->render();

	int step = (int)((float)newGame->sequence.size() / 2 + 0.5);
	fnt->printf(510, 95, HGETEXT_LEFT, "Round:%d",  step);
	



	static int gx = 0;
	static int gy = 0;
	int condition = newGame->checkCondition();
	if(condition == GameBoard::CONTINUE){
		float x, y;
		hge->Input_GetMousePos(&x, &y);
	
		int turn = step % 2;
		
		//=====================================================================
		if(turn == Stone::BLACK && gameControl->blackControl == GameControl::HUMAN){
			gx = x / 24;
			gy =  (480 - y) / 24;
			if(hge->Input_KeyDown(HGEK_LBUTTON)){
				system("CLS");
				if(newGame->input(turn, gx, gy)){
					newGame->showSequence();
					newGame->clearLine();
					newGame->buildLine();
					newGame->saveSequence();
				}
			}

			
		}

		if(turn == Stone::BLACK && gameControl->blackControl == GameControl::COMPUTER){
			system("CLS");
			gameControl->executeAI(turn, newGame);	
			newGame->showSequence();
			newGame->saveSequence();
			//gameControl->executeRandomAI(turn, newGame);
		}


		//===============================white===========================================

		if(turn == Stone::WHITE && gameControl->whiteControl == GameControl::HUMAN){
			gx = x / 24;
			gy =  (480 - y) / 24;
			if(hge->Input_KeyDown(HGEK_LBUTTON)){
				system("CLS");
				if(newGame->input(turn, gx, gy)){
					newGame->showSequence();
					newGame->saveSequence();
				}
			}

			
		}

		if(turn == Stone::WHITE && gameControl->whiteControl == GameControl::COMPUTER){
						system("CLS");
			gameControl->executeAI(turn, newGame);
			newGame->showSequence();
			newGame->saveSequence();
			//gameControl->executeRandomAI(turn, newGame);
		}
		//================================================================================

		fnt->printf(510, 35, HGETEXT_LEFT, "(%d, %d)", (int)x, (int)y);
		fnt->SetScale(1.5f);
		fnt->printf(510, 55, HGETEXT_LEFT, "(%c, %d)", (char)(gx + 64), (int)gy);
		fnt->SetScale(1.0f);
	
		if(turn == Stone::BLACK){
			fnt->printf(510, 115, HGETEXT_LEFT, "Turn:BLACK");
		}else if(turn == Stone::WHITE){;
			fnt->printf(510, 115, HGETEXT_LEFT, "Turn:WHITE");
		}

	}


	if(condition == GameBoard::BLACKWIN){
		fnt->printf(510, 55, HGETEXT_LEFT, "Black WIN!");
	}
	if(condition == GameBoard::WHITEWIN){
		fnt->printf(510, 55, HGETEXT_LEFT, "White WIN!");
	}
	if(gx > 0 && gy > 0 && gx < 20 && gy < 20){
		squareSpr->Render( gx * 24, 480 - gy * 24);
	}

	if(newGame->sequence.size() != 0){
		squareSpr->SetColor(0xFFFF5500);
		
		if(newGame->sequence.size() == 1){
			vector<Stone*>::iterator it = --newGame->sequence.end();
			Stone* stone = *it;
			squareSpr->Render( stone->gx * 24, 480 - stone->gy * 24);
		}else{
			vector<Stone*>::iterator it = --newGame->sequence.end();
			Stone* stone = *it;
			Stone* stone2 = *(--it);
			squareSpr->Render( stone->gx * 24, 480 - stone->gy * 24);
			squareSpr->Render( stone2->gx * 24, 480 - stone2->gy * 24);
		
		}
		squareSpr->SetColor(0xFFFFFFFF);
		
	}


	
	//回到前一手
	if(hge->Input_KeyDown(HGEK_F1)){
		newGame->cancelOneInput();
		system("CLS");
		newGame->showSequence();
		newGame->clearLine();
		newGame->buildLine();
	}

	if(hge->Input_KeyDown(HGEK_F2)){
		//newGame->reload();
		system("CLS");
		newGame->showSequence();
		bstart = false;
		dt = 0;
	}


	

	

	//	system("PAUSE");

	//fnt->




}

bool FrameFunc(){
	// newGame = gameControl->getGame(6);

	/*game->buildLine();
	game->clearLine();
	game->showBlackLine();
	game->showWhiteLine();*/
	//game->clearLine();
	gui->Update(hge->Timer_GetDelta());
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	boardSpr->Render(0, 0);
	if(gameControl->blackControl == GameControl::HUMAN){
		fnt->printf(510, 150, HGETEXT_LEFT, "Black:human");
	}else{
		fnt->printf(510, 150, HGETEXT_LEFT, "Black:computer");
	
	}

	if(gameControl->whiteControl == GameControl::HUMAN){
		fnt->printf(510, 180, HGETEXT_LEFT, "white:human");	
	}else{
		fnt->printf(510, 180, HGETEXT_LEFT, "white:computer");
	
	}



	if(bstart){
		fnt->printf(510, 220, HGETEXT_LEFT, "cancel one step:F1");
		fnt->printf(510, 250, HGETEXT_LEFT, "resetGameBoard:F2");
		startGame();
	}else{
		if(hge->Input_KeyDown(HGEK_ENTER)){
			bstart = true;
		}
		if(hge->Input_KeyDown(HGEK_F1)){
			gameControl->blackControl = GameControl::HUMAN;
			gameControl->whiteControl = GameControl::COMPUTER;
		}
		if(hge->Input_KeyDown(HGEK_F2)){
			gameControl->blackControl = GameControl::COMPUTER;
			gameControl->whiteControl = GameControl::HUMAN;
		}
		if(hge->Input_KeyDown(HGEK_F3)){
			gameControl->blackControl = GameControl::HUMAN;
			gameControl->whiteControl = GameControl::HUMAN;
		}
		if(hge->Input_KeyDown(HGEK_F4)){
			gameControl->blackControl = GameControl::COMPUTER;
			gameControl->whiteControl = GameControl::COMPUTER;
		}
		fnt->printf(510, 30, HGETEXT_LEFT, "press enter to start the game");
		fnt->printf(510, 220, HGETEXT_LEFT, "human to computer:F1");
		fnt->printf(510, 250, HGETEXT_LEFT, "computer to human:F2");
		fnt->printf(510, 280, HGETEXT_LEFT, "human to human:F3");
		fnt->printf(510, 310, HGETEXT_LEFT, "computer to computer:F4");
	}
	gui->Render();
	hge->Gfx_EndScene();


	//if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;

	



	return false;
}





void loadResource(){

	gameControl = GameControl::getInstance();
	boardSpr = new hgeSprite(gameControl->rm->GetTexture("newboard.png"), 0, 0, 500, 500);
	squareSpr = new hgeSprite(gameControl->rm->GetTexture("square.png"), 0, 0, 20, 20);
	//whiteStoneSpr = new hgeSprite(rm->GetTexture("white.png"), 0, 0, 23, 18);
	//blackStoneSpr = new hgeSprite(rm->GetTexture("black.png"), 0, 0, 23, 18);
	fnt = new hgeFont("font2.fnt");
		fnt->SetColor(0xFFFFFFFF);
	//fnt->SetScale(1.5f);

	gui = new hgeGUI();
	hgeSprite* cursorSpr = new hgeSprite(gameControl->rm->GetTexture("cursor.png"), 0, 0, 32, 32);
	cursorSpr->SetHotSpot(0, -20);
	gui->SetCursor(cursorSpr);
	gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	gui->Enter();
	newGame = new GameBoard();

	//gameControl->loadGame("sequenceLog.dat");
	//gameControl->showAllGameSequence();
	GameBoard* game = gameControl->getGame(0);

	cout << "Loading database, please waiting" << endl;
	LARGE_INTEGER m_liPerfFreq={0};
    QueryPerformanceFrequency(&m_liPerfFreq); 

    LARGE_INTEGER m_liPerfStart={0};
    QueryPerformanceCounter(&m_liPerfStart);

	gameControl->loadDB();

	
	LARGE_INTEGER liPerfNow={0};
    QueryPerformanceCounter(&liPerfNow);

    int time=( ((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000)/m_liPerfFreq.QuadPart);

    cout<<"執行時間:"<<time<< "ms"<<endl;
	//game->showBlackLine();
	//game->showWhiteLine();
//	game->clearLine();


	//gameControl->showAllGameSteps();



	hge->Random_Seed();


	//gameControl->loadGame("input.txt");
	//gameControl->showAllGameSequence();
	for(int i = 0; i < 0; i++){
		GameBoard* game = gameControl->getGame(i);
		int step = (int)((float)game->sequence.size() / 2 + 0.5);
		int turn = step % 2;
	
		gameControl->executeAI(turn, game);
		vector<Stone*>::iterator it = --game->sequence.end();
		Stone* stone1 = *it;
		Stone* stone2 = *(--it);

		cout << (char)(stone2->gx + 64) << (int)stone2->gy << " ";
		cout << (char)(stone1->gx + 64) << (int)stone1->gy << endl;

	}



	//system("pause");



}



void initialize(){
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_TITLE, "六子棋對局程式 by 交通大學多媒體工程所 張景照");
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_SHOWSPLASH, false);
	hge->System_SetState(HGE_SCREENWIDTH, 650);
    hge->System_SetState(HGE_SCREENHEIGHT, 500);
	hge->System_SetState(HGE_DONTSUSPEND, true);

	
}





void shutdown(){
	hge->System_Shutdown();
	hge->Release();

}



void linePattern(){

	cout << "create support database size = 19"  << endl;
	LARGE_INTEGER m_liPerfFreq={0};
    QueryPerformanceFrequency(&m_liPerfFreq); 

    LARGE_INTEGER m_liPerfStart={0};
    QueryPerformanceCounter(&m_liPerfStart);

	//game->buildAllDatabases(19);
	gameControl->loadDB();

	
	LARGE_INTEGER liPerfNow={0};
    QueryPerformanceCounter(&liPerfNow);

    int time=( ((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000)/m_liPerfFreq.QuadPart);

    cout<<"執行時間:"<<time<< "ms"<<endl;


	gameControl->loadLine("inputLine.txt");
	gameControl->showAllLines();
	//game->showLine(game->getLine(2));


	for(int i = 0; i < 8; i ++){
		GameLine* line = gameControl->getLinePattern(gameControl->getLine(i));
		cout << "line"  << i << "best position:" << line->BP << endl;

		if(line->condition == 6){
			cout << "win" << endl;
		}else if(line->threat != 0){
			cout << line->threat << "T" << endl;
		}else if(line->condition > 0){
			cout << "L" << line->condition  << endl;
		}else{
			cout << "D" << -1 * line->condition  << endl;
		}
	}




}


#include <iostream>
#include <io.h>
#include <fcntl.h>
void redirectIOToConsole(){
    // Allocate a console so we can output some useful information.
    AllocConsole();

    // Get the handle for STDOUT's file system.
    HANDLE stdOutputHandle = GetStdHandle( STD_OUTPUT_HANDLE );

    // Redirect STDOUT to the new console by associating STDOUT's file 
    // descriptor with an existing operating-system file handle.
    int hConsoleHandle = _open_osfhandle( (intptr_t)stdOutputHandle, _O_TEXT );
    FILE *pFile = _fdopen( hConsoleHandle, "w" );
    *stdout = *pFile;
    setvbuf( stdout, NULL, _IONBF, 0 );

    // This call ensures that iostream and C run-time library operations occur  
    // in the order that they appear in source code.
    ios::sync_with_stdio();
}

