#include <vector>
namespace b{
class Board
{
public:
	int width = 100;
	int height= 100;
	int n = 100;
	float dims[2];
	std::vector<std::vector<int>> foodCells{{10,10}}; //hardcoded for now	
	Board();
	Board(int width, int height, int n);	
	void setCellDims();
	void setFood();

};
}

