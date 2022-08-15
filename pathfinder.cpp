#include <iostream>
#include <vector>

class Maze {
  int numRows;
  int numCols;
  std::vector<std::vector<char> > maze;


  public: Maze(int numRows, int numCols) {
    if (numRows < 4) { numRows = 4; }
    if (numCols < 4) { numCols = 4; }

    this->numRows = numRows;
    this->numCols = numCols;
    constructMaze();
  }


  void constructMaze() {
    /* IDEA
      Initialize 2D array row*cols with 'X'
      For first and last row and col, make 2 entrances of ' '
      For all other rows and cols, randomly place ' ' (50/50 odds)
      Set this->maze
    */
    /* PSUEDOCODE
      1. Populate array 'maze' with 'X'
      For (i to numRows)
        For (j to numCols)
          numCols[i].push_back('X')

      2. Create 2 entrances per side
         For each column value in maze[0]
            entrance1 = randomInt(0, numCols)
            maze[entrance1] = ' '
            entrance2 = randomChoice(randomInt(0, entrance1), (entrance1 + 1, numCols))
            maze[entrance2] = ' '
        For each column value in maze[numRows]...
        For each row value in maze[i][numCols]...
        For each row value in maze[i][0]...

      3. Populate inner maze
         For (i to numRows)
            For (j to numCols)
                maze[i][j] = randomChoice('X', ' ')

      4. Set this->maze = maze
    */
  }

  int const getCols() {
    return this->numCols;
  }

  int const getRows() {
    return this->numRows;
  }

  std::vector<std::vector<char> > getMaze() {
    return this->maze;
  }

};

std::ostream& operator<<(std::ostream &s, const Maze &maze) {
  std::string output = "";
  /*
  For each row in maze.maze
    For each col in maze.maze
      output str += maze.maze[row][col]

  return output str
  */
  return s << output;
}

int main() {


  return 0;

}
