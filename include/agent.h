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
    board findSolution(board* gameboard); //given gameBoard, will find a solution
    void play(int x, int y, int value); //basic play function
    void diplayGameboard();
    void displayPlayDomain();
    std::vector<int> searchPlayable(int x, int y);

private:
    void searchSub(int x, int y); //searches sub-squares
    void searchCol(int x); //searches column at given x
    void searchRow(int y); //searches row at given

    void resetPlayDomain();

    bool inPlayDomain(int value);
    void removePlayDomain(int value);

    std::vector<int> playDomain;
    std::stack<move> playHistory;
    board* gameboard;
};

#endif // AGENT_H
