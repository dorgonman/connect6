#include "GameDB.h"


GameDB::GameDB(){
//	db.reset();
	/*dbSize = _dbSize;
	cout << "create support database size = " << dbSize << ", please waiting" << endl;
	  LARGE_INTEGER m_liPerfFreq={0};
    QueryPerformanceFrequency(&m_liPerfFreq); 
     
    LARGE_INTEGER m_liPerfStart={0};
    QueryPerformanceCounter(&m_liPerfStart);


	buildSupportDatabase();
	LARGE_INTEGER liPerfNow={0};
    QueryPerformanceCounter(&liPerfNow);

    int time=( ((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000)/m_liPerfFreq.QuadPart);

    cout<<"執行時間:"<<time<< "ms"<<endl;*/
	lineSize = 0;
	nState = 0;
}

GameDB::~GameDB(){
	vector<GameLine*>::iterator it;
	for( it = lineDB.begin(); it !=  lineDB.end(); it++ ){
			GameLine* line = *it;
			delete line;
	}
	lineDB.clear();

}


/*p=new   int;   
  p=new   int[0];   
  p=new   int[1];   
  這三個寫法是一樣的*/
/*  
129 'r' 開檔方式為唯讀，檔案指標指到開始處。   
130 'r+' 開檔方式為可讀寫，檔案指標指到開始處。   
131 'w' 開檔方式為寫入，檔案指標指到開始處，並將原檔的長度設為 0。若檔案不存在，則建立新檔。   
132 'w+' 開檔方式為可讀寫，檔案指標指到開始處，並將原檔的長度設為 0。若檔案不存在，則建立新檔。   
133 'a' 開檔方式為寫入，檔案指標指到檔案最後。若檔案不存在，則建立新檔。   
134 'a+' 開檔方式為可讀寫，檔案指標指到檔案最後。若檔案不存在，則建立新檔。   
135 'b' 若作業系統的文字及二進位檔不同，則可以用此參數，UNIX 系統不需要使用本參數。   
136 */  

void GameDB::buildDatabase(short int size){
	nState = (int)pow(2.0, size);
	lineSize = size;

	//GameLine* line = new GameLine();
	//line->state = nState - 1;
	//line->condition = -3;
	//lineDB.push_back(line);
	for(int i = nState - 1; i >= 0; i--){
		//cout << i << endl;
		GameLine* line = new GameLine(size);
		line->state = i;	
		//cout << line->threat << endl;
		lineDB.push_back(line);
		computeLinePattern(line);

		//cout << i << endl;
	}



	FILE* saveData;
	fopen_s(&saveData, "db.dat", "a");
	fprintf(saveData, "%d\n", size);
	for(int i = 0; i < nState; i++){
		fprintf(saveData, "line\n");
		fprintf(saveData, "%d %d %d %d\n", lineDB[i]->state, lineDB[i]->threat, lineDB[i]->condition, lineDB[i]->BP);
	}
	fclose(saveData);
}


void searchLine(GameLine* line, int start){


}

#include "GameControl.h"


void  GameDB::computeLinePattern(GameLine* line){
		//this->showLine(line);
		//system("PAUSE");
	//棋盤為19
	for(int i = 0; i < lineSize; i++){	
		int o = 0;//有子
		int mark = 0;//最後一個沒子的mark
		unsigned long state = line->state.to_ulong();

		for(int j = 0; j < 6; j++){

			if(i + j >= lineSize){
				mark = lineSize;
				break;
			}

			if(((state >> i + j) & 1) == 1){//true才是有子
				o++;
			}else{
				mark = i + j;
			}	
		}

		if(o == 6){
			line->condition = 6;//活6，贏了
			return;
		}	

		//就算是有連4顆也碰到牆壁了，所以不算threat(因為前面已經算過)
		if(mark == lineSize){
			break;
		}

		if(o >= 4){
			i = mark;
			line->threat++;
		}

	}


	
	//當這條pattern不是threat的話，就要計算其為是死n活n，另外贏了也不需要去算了。
	if(line->threat == 0 && line->condition != 6){
		for(int k = 1; k < 4; k++){//先從活3=>活2=>活1，因為活4等於threat，所以不計算
	
			for(int i = 0; i < lineSize; i++){	
				unsigned long tmpState = line->state.to_ulong();
				if(((tmpState >> i) & 1) == 1){
					continue;//這個位置上有子，往後搜尋
				}

				//試著去下k顆子，先固定下完1顆之後，再去下後面幾顆
				tmpState |= (1 << i);
				if (lineDB[nState - 1 - tmpState]->threat == 2){
					//先化成平方去掉負號後再來比較，因為活的優先權比較大，所以有等於
					if(pow((double)line->condition, 2.0) <=  pow((4.0 - (double)k), 2.0) ){
						line->condition = 4 - k;
						line->BP = i;
					}
				}				

				if (lineDB[nState - 1 - tmpState]->threat == 1){
					//死的優先權比較小，所以沒有等於
					if(pow((double)line->condition, 2.0) <  pow((4.0 - (double)k), 2.0) ){
						line->condition = -1 * (4 - k);
						line->BP = i;
					}
				}

		



				if(k >= 2){

					for(int m = i + 1; m < lineSize; m++){	
						//int count1 = count;
						unsigned long tmpState1 = tmpState;
						if(((tmpState >> m) & 1) == 1){
							continue;//這個位置上有子，往後搜尋
						}
						tmpState1 |= (1 << m);
						//count++;
						if (lineDB[nState - 1 - tmpState1]->threat == 2){
							//先化成平方去掉負號後再來比較，因為活的優先權比較大，所以有等於
							if(pow((double)line->condition, 2.0) <=  pow((4.0 - (double)k), 2.0) ){
								line->condition = 4 - k;
								line->BP = i;
							}
						}		

						if (lineDB[nState - 1 - tmpState1]->threat == 1){
							//死的優先權比較小，所以沒有等於
							if(pow((double)line->condition, 2.0) <  pow((4.0 - (double)k), 2.0) ){
								line->condition = -1 * (4 - k);
								line->BP = i;
							}
						}


									if(k >= 3){
										for(int n = m + 1; n < lineSize; n++){	
											//int count2 = count1;
											unsigned long tmpState2 = tmpState1;
											if(((tmpState2 >> n) & 1) == 1){
												continue;//這個位置上有子，往後搜尋
											}
											tmpState2 |= (1 << n);
											//if(line->state.to_ulong() == 8){
												//this->showLine(lineDB[nState - 1 - tmpState2]);
												//cout << lineDB[nState - 1 - tmpState2]->threat;
												//this->showLine(line);
											//	system("PAUSE");
											//}
											//count++;
											if (lineDB[nState - 1 - tmpState2]->threat == 2){
												//先化成平方去掉負號後再來比較，因為活的優先權比較大，所以有等於
												if(pow((double)line->condition, 2.0) <=  pow((4.0 - (double)k), 2.0) ){
													line->condition = 4 - k;
													line->BP = i;
												}
											}		

											if (lineDB[nState - 1 - tmpState2]->threat == 1){
												//死的優先權比較小，所以沒有等於
												if(pow((double)line->condition, 2.0) <  pow((4.0 - (double)k), 2.0) ){
													line->condition = -1 * (4 - k);
													line->BP = i;
												}
											}
										}
									}
									
							
						
					}
				}

				//計算最佳的BP
				//每下一子都會切成二半
				GameLine* line1 = new GameLine(i);
					for(int z = 0; z < i; z++){
						if(((tmpState >> z) & 1) == 1){
							line1->state.set(z, true);
						}
					}
				GameLine* line2 = new GameLine(lineSize - i - 1);
				line2->state = (tmpState >> i + 1);
				GameLine* lineA = GameControl::getInstance()->getLinePattern(line1);
				GameLine* lineB = GameControl::getInstance()->getLinePattern(line2);
				if(lineA == NULL && lineB == NULL){
					line->BP = i;
				}
				delete line1;
				delete line2;
			}
		}
	}
}




GameLine* GameDB::getLinePattern(GameLine *line){
	if(lineDB.size() == 0){
		return NULL;
	}

	return lineDB[lineDB.size() - 1 - line->state.to_ulong()];
}