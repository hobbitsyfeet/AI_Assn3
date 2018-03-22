#include "agent.h"
#include<iostream>

//******
//Move functions, used for play history
//******
void move::setMove(int x, int y){
this->x = x;
this->y = y;
}
 move::move(int x, int y){
	 this->x = x;
	 this->y = y;
 }
 move::move(const move& setMove){
	this->x = setMove.x;
	this->y = setMove.y;
}

//******
//Agent functions, used to solve the board
//******

//initializes gameboard ptr to null and sets play domain to 1 through 9
agent::agent(){
    gameboard = 0;
    resetPlayDomain();
}

//sets the current board, and preforms backtracking and returns solved board
board agent::backtrackingSearch(board* gameboard){
    this->gameboard = gameboard; // initialize gameboard for other functions to use and manipulate
		backtrack();
		return *this->gameboard;
}

bool agent::backtrack(){
	std::cout<<"Starting Backtracking\n";
	//temperary play domain (for use in recursion)
	std::vector<int> playable;

	//if board is full
  if(checkComplete()){
		std::cout<<"RETURNING COMPLETE\n";
    	return true;
  }

	//else find next unplayed
	for(int col = 0; col < 9; col++){
		for(int row = 0; row < 9 ; row ++){

			//if empty cell
			if(gameboard->getValue(row,col) == 0){
			//assign available plays to this local vector
			playable = searchPlayable(row,col);
			displayPlayDomain();

			// if there exists a valid play
			if(playable.size() != 0){
				// try playing each value in a backtracking fasion

				for(int domainPlay = 0; domainPlay < playable.size(); domainPlay++){
					//NOTE we can sort domain for heuristic to play most restricted <HERE>.
					play(row,col,playable[domainPlay]);
					std::cout<<"PLAYING: ("<<playable[domainPlay]<<")\n";
					gameboard->display();
					//if move is valid, continue down this path
					if(backtrack()){return true;}
						//do not make this move
					else{unplay();}
					}//end for domainPlay

				}//end if playDomainSize is valid

				return false; //path leads to dead end
			}// end if value is playable
		}//end for row
	}//end for column
return false;
}

//sets value on the board and adds to play history
void agent::play(int x, int y, int value){
    gameboard->setValue(x,y,value); //assign value to given position
    move currentMove(x,y); // creates a move with this position
    playHistory.push(currentMove); //records the move in a stack
    return;
}

//pops stack history and removes value from the board
void:: agent::unplay(){
	std::cout<<"unplaying at("<<playHistory.top().x<<','<<playHistory.top().y<<")\n";
	//set the board position last played to 0 (unset)
	gameboard->setValue(playHistory.top().x, playHistory.top().y, 0);
	playHistory.pop();
}

std::vector<int> agent::searchPlayable(int x, int y){
    std::cout<<"Searching available plays on ("<<x<<','<<y<<")\n";
		//set domain to contain 1 through 9
		resetPlayDomain();
    //these will search the restrictions and project the restrictions onto a playable domain.
    searchSub(x,y); //search sub square
    searchRow(y); //search row at given y
    searchCol(x); //search col at given x
    return playDomain;
}

//searches sub square (shown in board.h) and restricts playable domain
void agent::searchSub(int x, int y){
	int subx,suby;
	//translates x,y coord into appropriate sub square coord
	if(x < 3)
			subx = 0;
	else if(x >= 3 && x < 6)
			subx = 1;
	else if(x >= 6 && x < 9)
			subx = 2;

		if(y < 3)
				suby = 0;
		else if(y >= 3 && y < 6)
				suby = 1;
		else if(y >= 6 && y < 9)
				suby = 2;

    int tempVal;

		//iterates subsquare in order of bottom left to top right, removing vals from playDomain
    for(int startX = subx*3; startX < subx*3+3; startX++){
        for(int startY = suby*3; startY < suby*3+3; startY++){
            tempVal = gameboard->getValue(startX,startY);
            removePlayDomain(tempVal);
        }//end for startY
    }//end for startX
}//end SearchSub

//searches column at given x and restricts playable domain
void agent::searchCol(int x){
    int tempVal;
		//iterates the column from bottom up
    for (int colCount = 0; colCount < 9; colCount++){
        tempVal = gameboard->getValue(x,colCount);
        removePlayDomain(tempVal);
    }
}

//searches row at given y and restricts playable domain
void agent::searchRow(int y){
    int tempVal;
		//iterates the row left to right
    for (int rowCount = 0; rowCount < 9; rowCount++){
        tempVal = gameboard->getValue(rowCount,y);
        removePlayDomain(tempVal);
    }
}

//iterates the board and checks if there exists an empty cell
bool agent::checkComplete(){
    //searches bottom up left to right
    for(int col = 0; col < 9; col++){
        for (int row = 0; row < 9; row++){
            //if there exists 0 (empty placement)
            if(gameboard->getValue(col,row) == 0)
                return false;
        }//end row
    }//end col
    return true;
}

//prints gameboard top left to right
void agent::diplayGameboard(){
gameboard->display();
}

//prints the playDomain in a set notation
void agent::displayPlayDomain(){

    std::cout<<"Playable Domain: {";
    for(unsigned int i = 0; i < playDomain.size(); i++){
        std::cout<<playDomain[i];
    }
std::cout<<"}\n";
}

//resets play domain to {1,2,...,9}
void agent::resetPlayDomain(){
    std::vector<int> tempDomain;
    //assigns 1-9 in temp domain
    for(int i = 1; i <= 9; i++ ){
        tempDomain.push_back(i);
    }
    //sets play domain to temp domain containing 1-9
    playDomain = tempDomain;
}

//removes value given from play domain
void agent::removePlayDomain(int value){
    //for the size of play domain
    for(unsigned int i = 0; i < playDomain.size(); i++){
        //if the value is found in domain, remove it
        if(value == playDomain[i]){
            //std::cout<<"ERASING:"<<value<<'\n';
            playDomain.erase(playDomain.begin()+i);
            return;//stop searching
        }
    }//end for
}

//Huristic used to find the most appropriate value to play next
move agent::findMostConstrained(){
	int bestValue = 9;
	std::vector<int> tempDomain;
	move bestMove(0,0);
	for (int row = 0; row < 9; row++){
		for (int col = 0; col < 9; col ++){
			//if it's an empty cell
			if(gameboard->getValue(row,col) == 0){
				//check it's playable domain
				tempDomain = searchPlayable(row,col);
				if(tempDomain.size() < bestValue && tempDomain.size() != 0){
					bestMove.setMove(col,row);
				}
			}
		}
	}
	std::cout<<"BestMove is "<<bestMove.x<<','<<bestMove.y<<"\n";
	return bestMove;
}
