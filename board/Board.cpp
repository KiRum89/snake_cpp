#include <iostream>
#include "Board.h"
using namespace std;
using namespace b;
Board::Board(int width, int height,int n){
	Board::width = width;
	Board::height = height;
	Board::n = n;
}	
void Board::setCellDims(){
	
	Board::dims[0]=static_cast<float>(Board::width)/static_cast<float>(Board::n);
	Board::dims[1]=static_cast<float>(Board::height)/static_cast<float>(Board::n);

}

void Board::setFood(){
	Board::foodCells[0][0]=10;
	Board::foodCells[0][1]=10;
}	


