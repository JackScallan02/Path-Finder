#include <iostream>
#include <unistd.h>
#include <vector>
#include "maze.h"



//g++ mazeRepresentation.cpp snake.cpp -o a -std=c++11
std::vector<std::vector<int> > initializeVisitedArray(Maze maze) {
  std::vector<std::vector<int> > visited;
  for (int i = 0; i < maze.getRows() + 1; i++) {
    std::vector<int> row;
    for (int j = 0; j < maze.getCols() + 1; j++) {
      row.push_back(0);
    }
    visited.push_back(row);
  }

  return visited;
}




void db(std::vector<int> curPos) {
  std::cout << "Row index: " << curPos[0] << " Col index: " << curPos[1] << std::endl;
}

int snakeDfs(Maze maze, std::vector<int> curPos, int rightBound, int bottomBound, std::vector<std::vector<int> > &visited) {
/* Maze format
    0 1 2 3 4 5 6 7 8 9
  0
  1   X X X   X   X X
  2       X   X   X
  3   X   X X X X X X
  4   X           X
  5       X X X X X X
  6   X     X   X X
  7   X X X X X X   X
  8   X X     X X X X
  9
*/

  std::vector<std::vector<char> > mazeRepresentation = maze.getMaze();
  std::vector<std::vector<int> > stack;
  stack.push_back(curPos);

  while (!stack.empty()) {
    sleep(1);
    std::cout << "curPos[0]: " << curPos[0] << std::endl;
    std::cout << "curPos[1]: " << curPos[1] << std::endl;

    curPos = stack.back();
    stack.pop_back();
    maze.setMazeVal(curPos[0], curPos[1], 'O');
    visited[curPos[0]][curPos[1]] = 1;

    std::cout << maze << std::endl;

    if (curPos[0] == bottomBound || curPos[1] == rightBound || curPos[0] == 0) {
      break;
    }

    //left
    if (mazeRepresentation[curPos[0]][curPos[1] - 1] == ' ' && !visited[curPos[0]][curPos[1] - 1]) {
      std::vector<int> newPos = {curPos[0], curPos[1] - 1};
      stack.push_back(newPos);
    }

    //down
    if (mazeRepresentation[curPos[0] + 1][curPos[1]] == ' ' && !visited[curPos[0] + 1][curPos[1]]) {
      std::vector<int> newPos = {curPos[0] + 1, curPos[1]};
      stack.push_back(newPos);
    }

    //right
    if (mazeRepresentation[curPos[0]][curPos[1] + 1] == ' ' && !visited[curPos[0]][curPos[1] + 1]) {
      std::vector<int> newPos = {curPos[0], curPos[1] + 1};
      stack.push_back(newPos);
    }

    //up
    if (mazeRepresentation[curPos[0] - 1][curPos[1]] == ' ' && !visited[curPos[0] - 1][curPos[1]]) {
      std::vector<int> newPos = {curPos[0] - 1, curPos[1]};
      stack.push_back(newPos);
    }
  }


  return 0;

}



int main() {
  Maze maze(8, 8);
  std::cout << maze << std::endl;
  std::vector<int> curPos = {1, 0};
  std::vector<std::vector<int> > visited = initializeVisitedArray(maze);
  snakeDfs(maze, curPos, maze.getRows(), maze.getCols(), visited);
  return 0;
}
