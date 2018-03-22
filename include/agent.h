#ifndef AGENT_H
#define AGENT_H

#include"board.h"
#include<stack> // for play history
#include<vector>

//move is used for storing and retreiving history (x,y coords)
struct move{
		move(int x, int y);//constructs a move with x,y coordinates
		move(const move& setMove);//copies another move (used for stack.top())
    void setMove(int x, int y);//

    int x;
    int y;
};

class agent
{
public:
    agent();//agent constructor
    board backtrackingSearch(board* gameboard);//solves this board with backtracking

    void play(int x, int y, int value); //basic play function
		void unplay();//removes the last played value on the board from known history
    void diplayGameboard();//displays the known gameboard
    void displayPlayDomain();//displays the playable domain (playDomain)
    std::vector<int> searchPlayable(int x, int y); //returns a list of playable values in a cell

private:
    bool backtrack(); //given gameBoard, will find a solution (using backtracking algorithm)
    void searchSub(int x, int y); //searches sub-squares and sets playable domain
    void searchCol(int x); //searches column at given x and sets playable domain
    void searchRow(int y); //searches row at given and sets playable domain

    bool checkComplete(); //returns whether the board is full

    void resetPlayDomain();//resets play domain to domain of the game

    void removePlayDomain(int value);// removes passed value from the domain

		move findMostConstrained();// unfinished function that finds the cell that's most restricted

    std::vector<int> playDomain;//structure that holds the domain 1-9 (used in searches)
    std::stack<move> playHistory;// stack that holds x,y coords of last played move
    board* gameboard;//pointer to the known suduko board, set in backtrackingSearch
};

#endif // AGENT_H
