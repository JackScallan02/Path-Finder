#pragma once

class Maze {
  int numRows;
  int numCols;
  std::vector<std::vector<char> > mazeRepresentation;

  public:
    Maze(int numRows, int numCols);
    bool isBorder(int i, int j, int bottom, int right);
    int getRandomInt(int start, int end);
    void setBorderEntrances();
    void setInnerPaths();
    void constructMaze();
    int const getCols();
    int const getRows();
    std::vector<std::vector<char> > getMaze();
};

std::ostream& operator<<(std::ostream &s, Maze &maze);
