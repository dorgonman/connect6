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

    cout<<"����ɶ�:"<<time<< "ms"<<endl;*/
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
  �o�T�Ӽg�k�O�@�˪�*/
/*  
129 'r' �}�ɤ覡����Ū�A�ɮ׫��Ы���}�l�B�C   
130 'r+' �}�ɤ覡���iŪ�g�A�ɮ׫��Ы���}�l�B�C   
131 'w' �}�ɤ覡���g�J�A�ɮ׫��Ы���}�l�B�A�ñN���ɪ����׳]�� 0�C�Y�ɮפ��s�b�A�h�إ߷s�ɡC   
132 'w+' �}�ɤ覡���iŪ�g�A�ɮ׫��Ы���}�l�B�A�ñN���ɪ����׳]�� 0�C�Y�ɮפ��s�b�A�h�إ߷s�ɡC   
133 'a' �}�ɤ覡���g�J�A�ɮ׫��Ы����ɮ׳̫�C�Y�ɮפ��s�b�A�h�إ߷s�ɡC   
134 'a+' �}�ɤ覡���iŪ�g�A�ɮ׫��Ы����ɮ׳̫�C�Y�ɮפ��s�b�A�h�إ߷s�ɡC   
135 'b' �Y�@�~�t�Ϊ���r�ΤG�i���ɤ��P�A�h�i�H�Φ��ѼơAUNIX �t�Τ��ݭn�ϥΥ��ѼơC   
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
	//�ѽL��19
	for(int i = 0; i < lineSize; i++){	
		int o = 0;//���l
		int mark = 0;//�̫�@�ӨS�l��mark
		unsigned long state = line->state.to_ulong();

		for(int j = 0; j < 6; j++){

			if(i + j >= lineSize){
				mark = lineSize;
				break;
			}

			if(((state >> i + j) & 1) == 1){//true�~�O���l
				o++;
			}else{
				mark = i + j;
			}	
		}

		if(o == 6){
			line->condition = 6;//��6�AĹ�F
			return;
		}	

		//�N��O���s4���]�I������F�A�ҥH����threat(�]���e���w�g��L)
		if(mark == lineSize){
			break;
		}

		if(o >= 4){
			i = mark;
			line->threat++;
		}

	}


	
	//��o��pattern���Othreat���ܡA�N�n�p��䬰�O��n��n�A�t�~Ĺ�F�]���ݭn�h��F�C
	if(line->threat == 0 && line->condition != 6){
		for(int k = 1; k < 4; k++){//���q��3=>��2=>��1�A�]����4����threat�A�ҥH���p��
	
			for(int i = 0; i < lineSize; i++){	
				unsigned long tmpState = line->state.to_ulong();
				if(((tmpState >> i) & 1) == 1){
					continue;//�o�Ӧ�m�W���l�A����j�M
				}

				//�յۥh�Uk���l�A���T�w�U��1������A�A�h�U�᭱�X��
				tmpState |= (1 << i);
				if (lineDB[nState - 1 - tmpState]->threat == 2){
					//���Ʀ�����h���t����A�Ӥ���A�]�������u���v����j�A�ҥH������
					if(pow((double)line->condition, 2.0) <=  pow((4.0 - (double)k), 2.0) ){
						line->condition = 4 - k;
						line->BP = i;
					}
				}				

				if (lineDB[nState - 1 - tmpState]->threat == 1){
					//�����u���v����p�A�ҥH�S������
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
							continue;//�o�Ӧ�m�W���l�A����j�M
						}
						tmpState1 |= (1 << m);
						//count++;
						if (lineDB[nState - 1 - tmpState1]->threat == 2){
							//���Ʀ�����h���t����A�Ӥ���A�]�������u���v����j�A�ҥH������
							if(pow((double)line->condition, 2.0) <=  pow((4.0 - (double)k), 2.0) ){
								line->condition = 4 - k;
								line->BP = i;
							}
						}		

						if (lineDB[nState - 1 - tmpState1]->threat == 1){
							//�����u���v����p�A�ҥH�S������
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
												continue;//�o�Ӧ�m�W���l�A����j�M
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
												//���Ʀ�����h���t����A�Ӥ���A�]�������u���v����j�A�ҥH������
												if(pow((double)line->condition, 2.0) <=  pow((4.0 - (double)k), 2.0) ){
													line->condition = 4 - k;
													line->BP = i;
												}
											}		

											if (lineDB[nState - 1 - tmpState2]->threat == 1){
												//�����u���v����p�A�ҥH�S������
												if(pow((double)line->condition, 2.0) <  pow((4.0 - (double)k), 2.0) ){
													line->condition = -1 * (4 - k);
													line->BP = i;
												}
											}
										}
									}
									
							
						
					}
				}

				//�p��̨Ϊ�BP
				//�C�U�@�l���|�����G�b
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