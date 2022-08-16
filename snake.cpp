#include <iostream>
#include <vector>
#include "maze.h"

//g++ maze.cpp snake.cpp -o a -std=c++11


int snakeDfs(Maze &maze, std::vector<int> curPos) {
  /*
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
    Idea: snake enters from left column, tries to find exit in top, bottom, or right
    perform dfs starting at column 0, and mark each visited coordinate as "visited"
      if we find an exit, or no more openings, return
      if we find an opening, dfs(opening)
  */


  if (curPos[1] == 1 || curPos[1] == maze.getRows() || curPos[0] == maze.getCols()) {
    //Snake has found an exit
    return 1;
  }

  return 0;
}



int main() {
  Maze maze(8, 8);
  std::cout << maze << std::endl;
  std::vector<int> curPos = {0, 0};
  std::cout << snakeDfs(maze, curPos) << std::endl;
  return 0;
}
