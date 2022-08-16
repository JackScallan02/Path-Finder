#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>
#include "maze.h"

Maze::Maze(int numRows, int numCols) {
  if (numRows < 4) { numRows = 4; }
  if (numCols < 4) { numCols = 4; }

  this->numRows = numRows;
  this->numCols = numCols;
  constructMaze();
}


bool Maze::isBorder(int i, int j, int bottom, int right) {
  //Returns true or false if coordinate is at a border of the maze
  if (i == 0 || j == 0 || i == bottom || j == right) {
    return true;
  }
  return false;
}


int Maze::getRandomInt(int start, int end) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(start, end + 1);
  return distr(gen);
}

void Maze::setBorderEntrances() {
  //Sets a proportion border items ('X') to entrances (' ')
  std::unordered_set<int> borderEntrances;

  //Left Border
  int randomIndex = getRandomInt(2, numRows - 2);
  while (borderEntrances.size() < (numCols / 3)) {
    if (borderEntrances.find(randomIndex) == borderEntrances.end()) {
      borderEntrances.insert(randomIndex);
      mazeRepresentation[randomIndex][1] = ' ';
    }
    randomIndex = getRandomInt(2, numRows - 2);
  }
  borderEntrances.clear();

  //Right Border
  randomIndex = getRandomInt(2, numRows - 3);
  while (borderEntrances.size() < (numCols / 3)) {
    if (borderEntrances.find(randomIndex) == borderEntrances.end()) {
      borderEntrances.insert(randomIndex);
      mazeRepresentation[randomIndex][numCols] = ' ';
    }
    randomIndex = getRandomInt(2, numRows - 2);
  }
  borderEntrances.clear();

  //Top Border
  randomIndex = getRandomInt(2, numCols - 2);
  while (borderEntrances.size() < (numRows / 3)) {
    if (borderEntrances.find(randomIndex) == borderEntrances.end()) {
      borderEntrances.insert(randomIndex);
      mazeRepresentation[1][randomIndex] = ' ';
    }
    randomIndex = getRandomInt(2, numCols - 2);
  }
  borderEntrances.clear();

  //Bottom Border
  randomIndex = getRandomInt(2, numCols - 2);
  while (borderEntrances.size() < (numRows / 3)) {
    if (borderEntrances.find(randomIndex) == borderEntrances.end()) {
      borderEntrances.insert(randomIndex);
      mazeRepresentation[numRows][randomIndex] = ' ';
    }
    randomIndex = getRandomInt(2, numCols - 2);
  }
  borderEntrances.clear();

}

void Maze::setInnerPaths() {
  //Sets a proportion of 'X' items in the maze to ' ' (open paths)
  for (int i = 2; i < numRows - 1; i++) {
    for (int j = 2; j < numCols - 1; j++) {
      if (getRandomInt(0, 1)) {
        mazeRepresentation[i][j] = ' ';
      }
    }
  }
}


void Maze::constructMaze() {
  //Constructs a maze with empty chars around the border and fills it
  //with 'X' as a block or ' ' as an opening.

  int rowIndex = 0;
  std::vector<char> row;
  mazeRepresentation.push_back(row);
  while (rowIndex < numCols + 2) {
    mazeRepresentation[0].push_back(' ');
    rowIndex++;
  }

  for (int i = 1; i < numRows + 1; i++) {
    row = std::vector<char>();
    row.push_back(' ');
    mazeRepresentation.push_back(row);
    for (int j = 1; j < numCols + 1; j++) {
      mazeRepresentation[i].push_back('X');
    }
    mazeRepresentation[i].push_back(' ');

  }

  rowIndex = 0;
  row = std::vector<char>();
  mazeRepresentation.push_back(row);
  while (rowIndex < numCols + 2) {
    mazeRepresentation[mazeRepresentation.size() - 1].push_back(' ');
    rowIndex++;
  }

  setBorderEntrances();
  setInnerPaths();
}


int const Maze::getCols() {
  return numCols;
}

int const Maze::getRows() {
  return numRows;
}


std::vector<std::vector<char> > Maze::getMaze() {
  return mazeRepresentation;
}


std::ostream& operator<<(std::ostream &s, Maze &maze) {
  //Returns a string representation of the maze
  std::string output = "";

  for (int i = 0; i < maze.getRows() + 2; i++) {
    for (int j = 0; j < maze.getCols() + 2; j++) {
      output += maze.getMaze()[i][j];
      output += " ";
    }
    output += "\n";
  }

  return s << output;
}
