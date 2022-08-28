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

void backTrack(std::vector<std::vector<int> > &curPath, Maze &maze, int &backTrackAmount) {
  //std::cout << "PATH: ";
  std::cout << "Backtracking with an amount of " << backTrackAmount << std::endl;
  sleep(1);
  int pathSize = curPath.size();
  for (int i = pathSize - 1; i >= pathSize - backTrackAmount; i--) {

    maze.setMazeVal(curPath[i][0], curPath[i][1], ' ');
    curPath.pop_back();
    std::cout << maze << std::endl;
    sleep(1);
    std::cout << "Here" << std::endl;
  }

}



void db(std::vector<int> curPos) {
  std::cout << "Row index: " << curPos[0] << " Col index: " << curPos[1] << std::endl;
}

int snakeDfs(Maze maze, std::vector<int> curPos, int rightBound, int bottomBound, std::vector<std::vector<int> > &visited, std::vector<std::vector <int> > &curPosInfo) {
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
Idea: When you first visit a node,
    set curPosInfo[i][j] = number of nodes this node has yet to visit

    If our node is at a deadend, we must backtrack
      In backtrack function:
          get last node in stack (current node)
          pop it
          Update maze
          get last node in stack = LAST
          if number of nodes that LAST has to visit > 0,
              set curPosInfo[Last[0]][Last[1]] (num nodes to visit) -= 1
              return (we will be dfsing it)
          while (stack.size > 0 and LAST does not have any nodes to visit):
            pop from stack
            update maze
            LAST = top of stack
          set curPosInfo[Last[0]][Last[1]] (num nodes to visit) -= 1
*/


  std::vector<std::vector<char> > mazeRepresentation = maze.getMaze();
  std::vector<std::vector<int> > stack;
  std::vector<std::vector<int> > curPath;
  stack.push_back(curPos);

  while (!stack.empty()) {

    curPos = stack.back();
    stack.pop_back();
    curPath.push_back(curPos);
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

//NEED TO DO:
/*
Keep 3d array of curPosInfo
curPosInfo[x][y] = [backTrackAmount, numVerticesLeftToVisit]
Then we can check curPosInfo if numVerticesLeftToVisit > 0. If it is,
  do not back track.
If it is 0, back track by the backtrackamount.
*/


int main() {
  Maze maze(8, 8);
  std::cout << maze << std::endl;
  std::vector<int> curPos = {1, 0};
  std::vector<std::vector<int> > visited = initialize2DVector(maze);
  std::vector<std::vector<int> > curPosInfo = initialize2DVector(maze); //Stores amount of paths not yet visited stemming from vertex[i][j]
  snakeDfs(maze, curPos, maze.getRows(), maze.getCols(), visited, curPosInfo);
  return 0;
}
