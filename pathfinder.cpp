#include <iostream>
#include <vector>

class Maze {
  int numRows;
  int numCols;
  std::vector<char> maze;


  Maze(int numRows, int numCols) {
    if (numRows < 4) { numRows = 4; }
    if (numCols < 4) { numCols = 4; }

    this->numRows = numRows;
    this->numCols = numCols;
    constructMaze();
  }


  void constructMaze() {
    /*
    Initialize 2D array row*cols with 'X'
    For first and last row and col, make 2 entrances of ' '
    For all other rows and cols, randomly place ' ' (50/50 odds)
    Set this->maze
    */
  }
};

int main() {
  return 0;
}
