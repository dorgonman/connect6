#include "GameControl.h"





/*
function alphabeta(node, depth, α, β)         
    (* β represents previous player best choice - doesn't want it if α would worsen it *)
    if  depth = 0 "or" node is a terminal node
        return the heuristic value of node
    foreach child of node
        α := max(α, -alphabeta(child, depth-1, -β, -α))     
        (* use symmetry, -β becomes subsequently pruned α *)
        if β≤α
            break                             (* Beta cut-off *)
    return α

(* Initial call *)
alphabeta(origin, depth, -infinity, +infinity)

*/

//使用Nega-max


int g_state = 0;
float GameControl::alphabeta(GameBoard* child, int depth, float alpha, float beta, int step, int state){
	/*if(depth == 0){
		return child.evaluateGame(step, g_state);
	}


	for(int i = 1; i <= 19; i++){
		for(int j = 1; j <= 19; j++){
			GameBoard tmpGame;
			tmpGame.sequence =  child.sequence;
			memcpy(tmpGame.board, child.board, sizeof(child.board));
		
			if(tmpGame.input(state, i, j)){ 
				if(step % 2 == 0){
					step = 0;
					state = !state;//換方下
					alpha = max(alpha, -alphabeta(tmpGame, depth - 1, -beta, -alpha, step + 1, state));	
				}else{
					alpha = max(alpha, alphabeta(tmpGame, depth - 1, alpha, beta, step + 1, state));
				}
			}
			if(beta <= alpha){  //beta cut-off
				return alpha;
			}
		}
	}*/

	return alpha;
}


//mini-max的方法，F2的max node，G2是min node
Stone GameControl::alphabetaF2(GameBoard* child, int depth, int step, Stone stone){
	if(depth == 0){
		stone.score = child->evaluateGame(step, g_state);
		return stone;
	}


	float m = stone.alpha;
	for(int i = 1; i <= 19; i++){
		for(int j = 1; j <= 19; j++){
	
				GameBoard* tmpGame = child->clone();

	
				if(step ==  2){
					step = 0;
					stone.state = !stone.state;	
					float t = alphabetaG2(tmpGame, depth - 1, step, stone).score;
					if(t > m){
						m = t;
						stone.gx = i;
						stone.gy = j;
					}
				}else{
					
					if(tmpGame->input(stone.state, i, j)){
						float t = alphabetaF2(tmpGame, depth - 1, step + 1, stone).score;
						if(t > m){
							m = t;
							stone.gx = i;
							stone.gy = j;
					}
				}
				
		
			}
			if(m >= stone.beta){
				stone.score = m;
				return stone;//cut-off
			}
			delete tmpGame;
			tmpGame = NULL;

		}
	}


	stone.score = m;
	return stone;
}

Stone GameControl::alphabetaG2(GameBoard* child, int depth, int step, Stone stone){
	if(depth == 0){
		stone.score = child->evaluateGame(step, g_state);
		return stone;
	}


	float m = stone.beta;
	for(int i = 1; i <= 19; i++){
		for(int j = 1; j <= 19; j++){
			GameBoard* tmpGame = child->clone();

	
				if(step ==  2){
					step = 0;
					stone.state = !stone.state;	
					float t = alphabetaF2(tmpGame, depth - 1, step, stone).score;
					if(t < m){
						m = t;
						stone.gx = i;
						stone.gy = j;
					}
				}else{
					if(tmpGame->input(stone.state, i, j)){
						float t = alphabetaG2(tmpGame, depth - 1, step + 1, stone).score;
						if(t < m){
							m = t;
							stone.gx = i;
							stone.gy = j;
						}
					}

				}
				
		

			if(m <= stone.alpha){
				stone.score = m;
				return stone;//cut-off
			}
			delete tmpGame;
			tmpGame = NULL;

		}
	}


	stone.score = m;
	return stone;
}





Stone GameControl::ABSSS(GameBoard *root, int depth, int step, Stone stone){
	stone.score = inf;
	float gama = stone.score;
	while(1){
		gama = stone.score;
		stone.alpha = gama - 1;
		stone.beta = gama;
		stone = alphabetaF2(root, depth, step, stone);
		if(stone.score == gama){
			break;
		}
	};

	return stone;


}


bool GameControl::inputBestMove(int step, int state, GameBoard *game){
	

	//走一步得到的最終分數跟走二步得到的最終分數是不一樣的(因此，往後走越多步得到的結果越精確)


	//copy(game->sequence.begin(), game->sequence.end(), tmpGame.sequence.begin());
	/*g_state = state;
	
	int gx1 = 0;
	int gy1 = 0;
	int gx2 = 0;
	int gy2 = 0;

	Stone stone(state, 0, 0);
	stone.alpha = -inf;
	stone.beta = inf;
	stone = alphabetaF2(game, 2, 0, stone);
	game->input(state, stone.gx, stone.gy);

	Stone stone2(state, 0, 0);
	stone2.alpha = -inf;
	stone2.beta = inf;
	stone2 = alphabetaF2(game, 1, 1, stone2);
	game->input(state, stone2.gx, stone2.gy);*/

	

	//tmpGame.sequence.push_back(&Stone(state, 1, 1));

	GameBoard* tmpGame;
	float score = -inf;
	int gx = 0;
	int gy = 0;

	for(int i = 1; i <= 19; i++){
		for(int j = 1; j <= 19; j++){
			tmpGame = game->clone();
			//如果input成功的話(該位子上没有子)
			if(tmpGame->input(state, i, j)){
				float tmpScore = tmpGame->evaluateGame(step, state);
				if(tmpScore >= score){
					score = tmpScore;
					gx = i;
					gy = j;
				}
			}
			delete tmpGame;
			tmpGame = NULL;
		}
	}
	game->input(state, gx, gy);


	return false;
}