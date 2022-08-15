#include <iostream>
#include <vector>

class Maze {
  int numRows;
  int numCols;
  std::vector<std::vector<char> > mazeRepresentation;


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
      1. Populate array 'mazeRepresentation' with 'X'
      For (i to numRows)
        For (j to numCols)
          mazeRepresentation[i].push_back('X')

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

    for (int i = 0; i < this->numRows; i++) {
      std::vector<char> row;
      this->mazeRepresentation.push_back(row);
      for (int j = 0; j < this->numCols; j++) {
        this->mazeRepresentation[i].push_back('X');
      }
    }


  }

  int const getCols() {
    return this->numCols;
  }

  int const getRows() {
    return this->numRows;
  }



  std::vector<std::vector<char> > getMaze() {
    return this->mazeRepresentation;
  }

};

std::ostream& operator<<(std::ostream &s, Maze &maze) {
  std::string output = "";
  
  for (int i = 0; i < maze.getRows(); i++) {
    for (int j = 0; j < maze.getCols(); j++) {
      output += maze.getMaze()[i][j];
      output += " ";
    }
    output += "\n";
  }

  return s << output;
}

int main() {
  Maze maze(3, 4);
  std::cout << maze;
  return 0;

}
