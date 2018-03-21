#include "board.h"

#include"board.h"
#include<iostream>

board::board(){
	grid [0][8] = 2; grid [1][8] = 9; grid [2][8] = 3;
	grid [0][7] = 5; grid [1][7] = 0; grid [2][7] = 8;
	grid [0][6] = 0; grid [1][6] = 0; grid [2][6] = 0;

	grid [0][5] = 0; grid [1][5] = 7; grid [2][5] = 0;
	grid [0][4] = 0; grid [1][4] = 0; grid [2][4] = 1;
	grid [0][3] = 8; grid [1][3] = 2; grid [2][3] = 9;

	grid [0][2] = 0; grid [1][2] = 0; grid [2][2] = 0;
	grid [0][1] = 9; grid [1][1] = 0; grid [2][1] = 0;
	grid [0][0] = 0; grid [1][0] = 0; grid [2][0] = 0;

	// next column of sub-squares

	grid [3][8] = 0; grid [4][8] = 6; grid [5][8] = 1;
	grid [3][7] = 2; grid [4][7] = 7; grid [5][7] = 0;
	grid [3][6] = 5; grid [4][6] = 0; grid [5][6] = 8;

	grid [3][5] = 0; grid [4][5] = 2; grid [5][5] = 5;
	grid [3][4] = 7; grid [4][4] = 0; grid [5][4] = 6;
	grid [3][3] = 1; grid [4][3] = 4; grid [5][3] = 0;

	grid [3][2] = 9; grid [4][2] = 0; grid [5][2] = 2;
	grid [3][1] = 0; grid [4][1] = 1; grid [5][1] = 4;
	grid [3][0] = 3; grid [4][0] = 5; grid [5][0] = 0;

	// next column of sub-squares

	grid [6][8] = 0; grid [7][8] = 0; grid [8][8] = 0;
	grid [6][7] = 0; grid [7][7] = 0; grid [8][7] = 3;
	grid [6][6] = 0; grid [7][6] = 0; grid [8][6] = 0;

	grid [6][5] = 9; grid [7][5] = 3; grid [8][5] = 1;
	grid [6][4] = 4; grid [7][4] = 0; grid [8][4] = 0;
	grid [6][3] = 0; grid [7][3] = 6; grid [8][3] = 0;

	grid [6][2] = 0; grid [7][2] = 0; grid [8][2] = 0;
	grid [6][1] = 3; grid [7][1] = 0; grid [8][1] = 5;
	grid [6][0] = 8; grid [7][0] = 2; grid [8][0] = 9;

}

board::board( board& setBoard){
	for (int col = 0; col < 9; col++ ){
		for ( int row = 0; row < 9; row ++){
			this->grid[row][col] = setBoard.getValue(row,col);
		}
	}
}

void board::setValue(int x, int y, int value){
    grid[x][y] = value;
}

int board::getValue(int x, int y){
    return grid[x][y];
}

void board::display(){
	for (int j = 8; j >= 0; j--){ // for each column
		for (int i = 0; i < 9; i++){	// for each row

			if(i % 3 == 0){	// if on third row, make space
				std:: cout<<" ";
			}
			std::cout<<grid[i][j]<<' '; //dispay grid cell
		}
		if(j%3 == 0){	// if on tird column, make new line space
			std::cout<<"\n";
		}
		std::cout<<"\n";// done printing all the columns, go onto next row
	}
}
