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

    return 0;
}
