#include <iostream>
#include"board.h"
#include"agent.h"

using namespace std;

int main()
{
    board Seduko;
    agent solver;
    solver.backtrackingSearch(&Seduko);
    solver.diplayGameboard();
    solver.displayPlayDomain();
    //std::cout<<'\n'<<Seduko.getValue(0,1);
    std::cout<<"\n";
    solver.searchPlayable(0,0);
    solver.displayPlayDomain();
    return 0;
}
