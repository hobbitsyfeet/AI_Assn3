#ifndef BOARD_H
#define BOARD_H

/*
			Seduko Board
			Organization
	y _ _ _ _ _ _ _ _ _
	8|     |     |     |
	7| 0,2 | 1,2 | 2,2 |
	6|_ _ _|_ _ _|_ _ _|
	5|     |     |     |
	4| 0,1 | 1,1 | 1,2 |
	3|_ _ _|_ _ _|_ _ _|
	2|     |     |     |
	1| 0,0 | 0,1 | 0,2 |
	0|_ _ _|_ _ _|_ _ _|
		0 1 2 3 4 5 6 7 8 x
*/

class board{
public:

	board();
	void searchSub(int x, int y); //searches sub-squares
	void searchCol(int x); //searches column at given x
	void searchRow(int y); //searches row at given y
	void display();

private:
	int grid[9][9];


};

#endif //BOARD_H
