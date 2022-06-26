#include "Snake.h"
#include <vector>
#include <iostream>

using namespace std;
Snake::Snake(){

}
void Snake::move(){
		
		//add next element according to the direction
		vector<int> lastElement = Snake::makeLastElement(); 

		Snake::cells.push_back(lastElement);
		//delete first element
		Snake::cells.erase(Snake::cells.begin());
	
}

vector<int> Snake::makeLastElement(){
		vector<int> lastElement =  Snake::cells[Snake::cells.size()-1];

		switch (Snake::direction)
		{
			case 0:
				lastElement[1]-=1;
				break;
			case 1:
				lastElement[0]+=1;
				break;
			case 2:
				lastElement[1]+=1;
				break;
			case 3:
				lastElement[0]-=1;
				break;
		}
	return lastElement;


}
