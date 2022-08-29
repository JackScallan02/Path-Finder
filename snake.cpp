#include <iostream>
#include <unistd.h>
#include <vector>
#include "maze.h"



//g++ mazeRepresentation.cpp snake.cpp -o a -std=c++11
std::vector<std::vector<int> > initialize2DVector(Maze maze) {
  std::vector<std::vector<int> > vect;
  for (int i = 0; i < maze.getRows() + 2; i++) {
    std::vector<int> row;
    for (int j = 0; j < maze.getCols() + 2; j++) {
      row.push_back(0);
    }
    vect.push_back(row);
  }
  return vect;
}

void backTrack(std::vector<int> &stack, Maze &maze) {
  //std::cout << "PATH: ";


}

Maze makeTestMaze() {
  Maze testMaze(8, 8);
  for (int row = 1; row < 9; row++) {
    for (int col = 1; col < 9; col++) {
      if (row == 4 && col < 5) {
        testMaze.setMazeVal(row, col, ' ');
      } else if ((row == 2 || row == 3 || row == 5 || row == 6) && col == 3) {
        testMaze.setMazeVal(row, col, ' ');
      } else {
        testMaze.setMazeVal(row, col, 'X');
      }
    }
  }
  return testMaze;
}


void printStack(std::vector<std::vector<int> > stack) {
  int size = stack.size();
  std::cout << "STACK: {";
  for (int i = 0; i < size - 1; i++) {
    std::cout << "(" << stack[i][0] << ", " << stack[i][1] << "), ";
  }
  std::cout << "(" << stack[size - 1][0] << ", " << stack[size - 1][1] << ")}" << std::endl;
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


/*
Algorithm:
Keep entire path in stack
If a dead end is found
  pop current node from the stack
  update the maze representation

*/


  std::vector<std::vector<char> > mazeRepresentation = maze.getMaze();
  std::vector<std::vector<int> > stack;
  stack.push_back(curPos);
  int numberOfNeighbors;

  while (!stack.empty()) {
    printStack(stack);

    curPos = stack.back();
    stack.pop_back();

    maze.setMazeVal(curPos[0], curPos[1], 'O');

    visited[curPos[0]][curPos[1]] = 1;


    sleep(1);
    std::cout << maze << std::endl;


    if (curPos[0] == bottomBound || curPos[1] == rightBound || curPos[0] == 0) {
      break;
    }

    //left
    if (mazeRepresentation[curPos[0]][curPos[1] - 1] == ' ' && !visited[curPos[0]][curPos[1] - 1]) {
      std::vector<int> newPos = {curPos[0], curPos[1] - 1};
      numberOfNeighbors++;
      stack.push_back(newPos);
    }

    //down
    if (mazeRepresentation[curPos[0] + 1][curPos[1]] == ' ' && !visited[curPos[0] + 1][curPos[1]]) {
      std::vector<int> newPos = {curPos[0] + 1, curPos[1]};
      numberOfNeighbors++;
      stack.push_back(newPos);
    }

    //right
    if (mazeRepresentation[curPos[0]][curPos[1] + 1] == ' ' && !visited[curPos[0]][curPos[1] + 1]) {
      std::vector<int> newPos = {curPos[0], curPos[1] + 1};
      numberOfNeighbors++;
      stack.push_back(newPos);
    }

    //up
    if (mazeRepresentation[curPos[0] - 1][curPos[1]] == ' ' && !visited[curPos[0] - 1][curPos[1]]) {
      std::vector<int> newPos = {curPos[0] - 1, curPos[1]};
      numberOfNeighbors++;
      stack.push_back(newPos);
    }

  }

  return 0;

}

//NEED TO DO:
/*
Keep 3d array of curPosInfo
curPosInfo[x][y] = [backTrackAmount, numVerticesLeftToVisit]
Then we can check curPosInfo if numVerticesLeftToVisit > 0. If it is,
  do not back track.
If it is 0, back track by the backtrackamount.
*/


int main() {
  //Maze maze(8, 8);
  Maze maze = makeTestMaze();
  std::cout << maze << std::endl;
  std::vector<int> curPos = {1, 0};
  std::vector<std::vector<int> > visited = initialize2DVector(maze);
  snakeDfs(maze, curPos, maze.getRows(), maze.getCols(), visited);
  return 0;
}
