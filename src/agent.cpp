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

board agent::findSolution(board* gameboard){
    this->gameboard = gameboard; // initialize gameboard for other functions to use and manipulate
    return *gameboard;
}

void agent::play(int x, int y, int value){
    gameboard->setValue(x,y,value);
    move currentMove;
    currentMove.setMove(x,y); //creates a move from this turn
    playHistory.push(currentMove); //records the move in a stack
    return;
}

std::vector<int> agent::searchPlayable(int x, int y){
    int subx,suby;
switch(x){
    case 1:
    case 2:
    case 3:subx = 0;
    break;
    case 4:
    case 5:
    case 6:subx = 1;
    break;
    case 7:
    case 8:
    case 9:subx = 2;
    break;
    default: subx = 0;
}
switch(y){
    case 1:
    case 2:
    case 3:suby = 0;
    break;
    case 4:
    case 5:
    case 6:suby = 1;
    break;
    case 7:
    case 8:
    case 9:suby = 2;
    break;
    default: suby = 0;
}
    searchSub(subx,suby);
    searchRow(y);
    searchCol(x);
    return playDomain;
}

void agent::searchSub(int x, int y){
    int tempVal;
    for(int startX = x*3; startX < x*3+3; startX++){
        for(int startY = y*3; startY < y*3+3; startY++){
            tempVal = gameboard->getValue(startX,startY);
            removePlayDomain(tempVal);
        }
    }
}

void agent::searchCol(int x){
    int tempVal;
    for (int i = 0; i < 9; i++){
        tempVal = gameboard->getValue(x,i);
        removePlayDomain(tempVal);
    }
}

void agent::searchRow(int y){
    int tempVal;
    for (int i = 0; i < 9; i++){
        tempVal = gameboard->getValue(i,y);
        removePlayDomain(tempVal);
    }
}

void agent::diplayGameboard(){
gameboard->display();
}

void agent::displayPlayDomain(){
    std::cout<<'{';
    for(unsigned int i = 0; i < playDomain.size(); i++){
        std::cout<<playDomain[i];
    }
std::cout<<'}';
}

void agent::resetPlayDomain(){
    std::vector<int> tempDomain;
    for(int i = 1; i <= 9; i++ ){
        tempDomain.push_back(i);
    }
    playDomain = tempDomain;
}

bool agent::inPlayDomain(int value){
    for(unsigned int i = 0; i < playDomain.size(); i++){
        if(value == playDomain[i]){
            return true;
        }
    }
    return false;
}

void agent::removePlayDomain(int value){
    for(int i = 0; i < playDomain.size(); i++){
        if(value == playDomain[i]){
            std::cout<<"ERASING:"<<value<<'\n';
            playDomain.erase(playDomain.begin()+i);
            return;
        }
    }
}

