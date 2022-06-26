cmake_minimum_required(VERSION 3.10)

#set the project name
project(SnakeGame)
#add subdirectory
add_subdirectory(board)
add_subdirectory(snake)
#add the executable
add_executable(SnakeGame snake.cpp)

target_link_libraries(SnakeGame PUBLIC Board)
target_link_libraries(SnakeGame PUBLIC Snake)

target_link_libraries(SnakeGame PUBLIC sfml-window sfml-system sfml-graphics)
target_include_directories(SnakeGame PUBLIC 
								"${PROJECT_BINARY_DIR}"
								"${PROJECT_SOURCE_DIR}/board"
							)
target_include_directories(SnakeGame PUBLIC 
								"${PROJECT_BINARY_DIR}"
								"${PROJECT_SOURCE_DIR}/snake"
							)

