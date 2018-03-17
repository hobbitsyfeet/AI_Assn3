#ifndef AGENT_H
#define AGENT_H

#include"board.h"
#include<stack> // for play history
#include<vector>

struct move{
    void setMove(int x, int y);
    int x;
    int y;
};

class agent
{
public:
    agent();
    board backtrackingSearch(board* gameboard);

    void play(int x, int y, int value); //basic play function
    void diplayGameboard();
    void displayPlayDomain();
    std::vector<int> searchPlayable(int x, int y);

private:
    bool backtrack(); //given gameBoard, will find a solution (using backtracking algorithm)
    void searchSub(int x, int y); //searches sub-squares and sets playable domain
    void searchCol(int x); //searches column at given x and sets playable domain
    void searchRow(int y); //searches row at given and sets playable domain

    bool checkComplete(); //returns whether the board is full

    void resetPlayDomain();//resets play domain to domain of the game

    //bool inPlayDomain(int value); // checks if a value exists in play domain.
    void removePlayDomain(int value);

    std::vector<int> playDomain;
    std::stack<move> playHistory;
    board* gameboard;
};

#endif // AGENT_H
