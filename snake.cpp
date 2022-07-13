#include <iostream>
#include <Board.h>
#include <Snake.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace std;
using namespace b;
/*
 *comment
 */
void drawGridH(Board board, sf::RenderWindow &window){
		//draw grid
		//sf::Vertex(sf::Vector2f(board.width,i*board.dims[1]))};

		for (int i=0;i<board.n;++i){
			sf::Vertex a = sf::Vertex(sf::Vector2f(0,i*board.dims[1]));
			sf::Vertex b = sf::Vertex(sf::Vector2f(board.width,i*board.dims[1]));

			sf::Vertex line[] ={a,b};
			window.draw(line,2,sf::Lines);
		}	
}
void drawGridV(Board board, sf::RenderWindow &window){
		//draw grid
		//sf::Vertex(sf::Vector2f(board.width,i*board.dims[1]))};

		for (int i=0;i<board.n;++i){
			sf::Vertex a = sf::Vertex(sf::Vector2f(i*board.dims[0],0));
			sf::Vertex b = sf::Vertex(sf::Vector2f(i*board.dims[0],board.height));

			sf::Vertex line[] ={a,b};
			window.draw(line,2,sf::Lines);
		}	
}

void drawSnake(Board board, sf::RenderWindow &window, Snake snake){
	for (vector<int> cell : snake.cells){ 
		sf::RectangleShape rect(sf::Vector2f(board.dims[0],board.dims[1]));
		rect.setPosition(sf::Vector2f(board.dims[0]*cell[0],board.dims[1]*cell[1]));
		
		window.draw(rect);
	}	

}

void drawFood(Board board, sf::RenderWindow &window){
	for (vector<int> cell : board.foodCells){ 
		sf::RectangleShape rect(sf::Vector2f(board.dims[0],board.dims[1]));
		rect.setPosition(sf::Vector2f(board.dims[0]*cell[0],board.dims[1]*cell[1]));
		window.draw(rect);
	}	
}

int main(){

		Board board = Board(200,200,14);
		Snake snake = Snake();
		board.setCellDims();

		sf::RenderWindow window(sf::VideoMode(board.width, board.height), "Snake works!");
		
		
		
	sf::Clock clock;

	while (window.isOpen())
		{

			board.setFood();	
			drawGridH(board,window);
			drawGridV(board,window);

			drawSnake(board,window,snake);
			drawFood(board,window);
			if (clock.getElapsedTime().asSeconds()>0.1){
				

				snake.move();
				if (snake.cells[snake.cells.size()-1]==board.foodCells[0]){
					vector<int> lastElement = snake.makeLastElement();		
					snake.cells.push_back(lastElement);

				}		
				cout << snake.cells.size()<<endl;
				clock.restart();

			}	

			//if board.food is empty add food
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			 }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				snake.direction=3;

			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				snake.direction=1;
 			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				snake.direction=0;
 			}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				snake.direction=2;
 			}

			 window.display();
				

			window.clear();	

				
		}
			
}

