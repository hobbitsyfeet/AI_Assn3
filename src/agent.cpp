#include "agent.h"
#include<iostream>

void move::setMove(int x, int y){
this->x = x;
this->y = y;
}
agent::agent(){
    gameboard = 0;
    resetPlayDomain();
}

board agent::backtrackingSearch(board* gameboard){
    this->gameboard = gameboard; // initialize gameboard for other functions to use and manipulate
    return backtrack();
}
bool agent::backtrack(){

    if(checkComplete()){
        return *gameboard;
    }
    //select cell to change
    //for each playableDomain
        //searchPlayable
        //if playableDomain is not empty
            //play assignment
            //result = backtrack
            //if result != faliure
                //return result
        //pop the history stack
        //return

    //


    return *gameboard; //returns the solution
}

void agent::play(int x, int y, int value){
    gameboard->setValue(x,y,value); //assign value to given position
    move currentMove;
    currentMove.setMove(x,y); //creates a move from this turn with played position
    playHistory.push(currentMove); //records the move in a stack
    return;
}

std::vector<int> agent::searchPlayable(int x, int y){
    std::cout<<"Searching available plays on ("<<x<<','<<y<<")\n";
    int subx,suby;
    //determine sub square coords for searchSub
    if(x <=3)
        subx = 0;
    else if(x <= 6 && x > 3)
        subx = 1;
    else if(x <= 9 && x > 6)
        subx = 2;
    if(y <=3)
        suby = 0;
    else if(y <= 6 && y > 3)
        subx = 1;
    else if(y <= 9 && y > 6)
        subx = 2;

    //these will search the restrictions and project the restrictions onto a playable domain.
    searchSub(subx,suby); // search sub square
    searchRow(y); //search row at given y
    searchCol(x); //search col at given x
    return playDomain;
}

//searches sub square (shown in board.h) and restricts playable domain
void agent::searchSub(int x, int y){
    int tempVal;
    for(int startX = x*3; startX < x*3+3; startX++){
        for(int startY = y*3; startY < y*3+3; startY++){
            tempVal = gameboard->getValue(startX,startY);
            removePlayDomain(tempVal);
        }
    }
}

//searches column at given x and restricts playable domain
void agent::searchCol(int x){
    int tempVal;
    for (int colCount = 0; colCount < 9; colCount++){
        tempVal = gameboard->getValue(x,colCount);
        removePlayDomain(tempVal);
    }
}

//searches row at given y and restricts playable domain
void agent::searchRow(int y){
    int tempVal;
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
    std::cout<<'{';
    for(unsigned int i = 0; i < playDomain.size(); i++){
        std::cout<<playDomain[i];
    }
std::cout<<'}';
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

/*
//checks to see if variable exists in play domain
bool agent::inPlayDomain(int value){
    for(unsigned int i = 0; i < playDomain.size(); i++){
        if(value == playDomain[i]){
            return true;
        }
    }
    return false;
}
*/

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

