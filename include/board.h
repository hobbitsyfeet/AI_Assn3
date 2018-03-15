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

NOTE: numbers in sub squares are the values
that are used to access them in searchSub()
This creates a nice 3*index to get to 0,0 of sub square (bottom left)
*/

class board{
public:

	board();
	void setValue(int x, int y, int value); //places value at X,Y coordinates
	int getValue(int x, int y);
	void display();

private:
	int grid[9][9];
    const int domain[9] = {1,2,3,4,5,6,7,8,9}; //playable numbers

};

#endif //BOARD_H
