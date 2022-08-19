#include <iostream>
#include <unistd.h>
#include <vector>
#include "maze.h"



//g++ mazeRepresentation.cpp snake.cpp -o a -std=c++11
std::vector<std::vector<int> > initializeVisitedArray(Maze maze) {
  std::vector<std::vector<int> > visited;
  for (int i = 0; i < maze.getRows(); i++) {
    std::vector<int> row;
    for (int j = 0; j < maze.getCols(); j++) {
      row.push_back(0);
    }
    visited.push_back(row);
  }

  return visited;
}



void db(std::vector<int> curPos) {
  std::cout << "Row index: " << curPos[0] << " Col index: " << curPos[1] << std::endl;
}

int snakeDfs(Maze maze, std::vector<int> curPos, int rightBound, int bottomBound, std::vector<std::vector<int> > &visited, std::vector<int> curStack) {
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

  sleep(1);

  //Pass in a second stack as parameter so snake can display a backtrack


  maze.setMazeVal(curPos[0], curPos[1], 'O');

  std::vector<std::vector<char> > mazeRepresentation = maze.getMaze();
  std::cout << maze << std::endl;

  if (mazeRepresentation[curPos[0]][curPos[1]] == 'X') {
    //Snake cannot dfs any further
    return 0;
  }

  if (curPos[0] == 0 || curPos[1] == rightBound + 1 || curPos[0] == bottomBound + 1) {
    //Snake has found an exit
    return 1;
  }

  if (visited[curPos[0]][curPos[1]] == 1) {
    return 0;
  }
  visited[curPos[0]][curPos[1]] = 1;


  //up
  if (mazeRepresentation[curPos[0] - 1][curPos[1]] == ' ') {
    std::vector<int> newPos = {curPos[0] - 1, curPos[1]};
    if (snakeDfs(maze, newPos, rightBound, bottomBound, visited, curStack)) {
      return 1;
    }
  }

  //right
  if (mazeRepresentation[curPos[0]][curPos[1] + 1] == ' ') {
    std::vector<int> newPos = {curPos[0], curPos[1] + 1};
    if (snakeDfs(maze, newPos, rightBound, bottomBound, visited, curStack)) {
      return 1;
    }
  }

  //down
  if (mazeRepresentation[curPos[0] + 1][curPos[1]] == ' ') {
    std::vector<int> newPos = {curPos[0] + 1, curPos[1]};
    if (snakeDfs(maze, newPos, rightBound, bottomBound, visited, curStack)) {
      return 1;
    }
  }

  //left
  if (mazeRepresentation[curPos[0]][curPos[1] - 1] == ' ') {
    std::vector<int> newPos = {curPos[0], curPos[1] - 1};
    if (snakeDfs(maze, newPos, rightBound, bottomBound, visited, curStack)) {
      return 1;
    }
  }

  return 0;
}



int main() {
  Maze maze(8, 8);
  std::cout << maze << std::endl;
  std::vector<int> curPos = {1, 0};
  std::vector<int> curStack;
  std::vector<std::vector<int> > visited = initializeVisitedArray(maze);
  snakeDfs(maze, curPos, maze.getRows(), maze.getCols(), visited, curStack);
  return 0;
}
