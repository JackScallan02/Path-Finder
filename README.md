# Path-Finder
C++ program that, given a maze, visualizes a snake entering it at some point and finds the nearest exit.

### Maze Construction
The maze is initialized as an object and is randomly filled as a proportion of its dimensions. The outer borders are initialized accordingly, and printing the object will display its representation.

### Algorithm
The algorithm is similar to the iterative "depth-first search" algorithm. We retain a stack to store the order in which we have traversed the current path as a vector 'pos' where pos[0] is the current row index and pos[1] is the current column index. 
If we find a dead end, i.e., all surrounding positions have been visited, or all surrounding positions are unvisitable, then we "backtrack". Backtracking mocks the idea of a snake moving backwards in the maze, until it has a new path to discover. Every step back taken, we pop the current position vector from the stack, and update our displayed maze representation.

### Visualization:
<img src="https://recordit.co/cGOJQT7npK.gif">
