#include "GameControl.h"
#include <ctype.h>;







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
GameControl::GameControl(){
	rm = new hgeResourceManager();

	whiteStoneSpr = new hgeSprite(rm->GetTexture("white.png"), 0, 0, 20, 20);
	blackStoneSpr = new hgeSprite(rm->GetTexture("black.png"), 0, 0, 20, 20);
	blackControl = HUMAN;
	whiteControl = COMPUTER;
	//system("PAUSE");
	//whiteStoneSpr->SetHotSpot(20 / 2, 20 / 2);
	//blackStoneSpr->SetHotSpot(20 / 2, 20 / 2);
}


GameControl::~GameControl(){
	vector<GameLine*>::iterator it;
	for( it = lines.begin(); it !=  lines.end(); it++ ){
			GameLine* line = *it;
			delete line;
	}
	lines.clear();
	delete instance;


}




GameControl* GameControl::instance = NULL;

GameControl* GameControl::getInstance(){
	if(instance == NULL){
		instance = new GameControl();
	}
	return instance;
}
