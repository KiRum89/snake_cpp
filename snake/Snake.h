#include <vector>
class Snake{

	public:
		int direction = 2;
		int n = 1;
		Snake();
		std::vector<std::vector<int>> cells{{0,0},{0,1},{0,2}};	
		void move();
		std::vector<int> makeLastElement();
};
