# A* Search CLI Program
Objective: A project for learning the A* search algorithm and some core components of modern C++.

## Description
The project program is written in modern C++. It employs the A* search algorithm for finding the shortest route between two points on a 2D Cartesian grid. The program is executed through a command line interface (CLI) and produces output through the associated terminal's standard output.

## Program Pseudocode
```
Define node states: open, path, obstacle or closed

ReadGrid()
  Read grid from file:
  Define grid: a matrix of node states, initially either open or obstacle.
  Return grid.

Define heuristic function hf(x1, y1, x2, y2):
  Compute the Manhattan distance between the two points (x1, y1) and (x2, y2).

Note that a node data structure is the set of values {x, y, g, h} where:
  x and y are the coordinates of the node.
  g is the cost of the search to arrive at the node
  h = hf(x, y, xg, yg) where (xg, yg) are the coordinates of the goal node

Search(grid, (xs, ys), (xg, yg))
  Initialize empty list of nodes called test; it's to be a list of nodes to test.

  Initialize first node to add to list test and to be examined by Search:
    x and y are the coordinates of the start node (xs, ys).
    g = 0
    h = hf(xs, ys, xg, yg)

  Add node start to list test.

  While list test has 1 or more nodes:
    Sort list test in descending order of g + h = f.
    Remove node with smallest value of f from list test.
    Set state of removed node as being a path.
    If removed node is the goal node:
      Return grid.
    Otherwise:
      Examine each of removed node's neighboring nodes:
        If state of neighbor node is open:
          Initialize neighbor node {x, y, g, h}
          Add neighbor node to list test.
          Set node state to closed.

  While loop is exited when there are no more test nodes and goal node was not
  tested. In this case, report that a path connecting start and goal nodes could
  not be found and return an empty matrix.

PrintGrid(grid)
  Print string mapping of grid.

Main()
  Initialize grid from grid file: grid = ReadGrid()
  Initialize start and goal node coordinates: (xs, ys), (xg, yg)
  grid = Search(grid, (xs, ys), (xg, yg))
  PrintGrid(grid)
```

## Environment
This program was developed on Ubuntu 19.04. It was compiled with x86_64-linux-gnu-g++-8 (Ubuntu 8.3.0-6ubuntu1) 8.3.0 with `-std=c++17`, the 2017 ISO C++ standard plus amendments.

## Execution
The program reads a file, `stateMatrix.csv`, containing comma separated values of `1`s or `0`s. A `1` represents a barrier. A `0` represents an open node. The lines and columns of values represent the two dimensions of the rectangular grid.
```bash
$ cat stateMatrix.csv
0,1,0,0,0,0,
0,1,0,0,0,0,
0,1,0,0,0,0,
0,1,0,0,0,0,
0,0,0,0,1,0,
```
The start and goal node coordinates of the grid for the A* search algorithm are hardcoded in the program as arguments to the `Search` function. Below is the last development execution.
```bash
$ c++ -std=c++17 main.cpp
$ ./a.out

Grid with A* Search Path

	🚦   ⛰️   0   0   0   0   
	🚗   ⛰️   0   0   0   0   
	🚗   ⛰️   0   0   0   0   
	🚗   ⛰️   0   🚗   🚗   🚗   
	🚗   🚗   🚗   🚗   ⛰️   🏁   

----------------------------------------------------------
Heuristic Function Test: passed
----------------------------------------------------------
----------------------------------------------------------
AddToTestNodes Function Test: passed
----------------------------------------------------------
----------------------------------------------------------
Compare Function Test: passed
----------------------------------------------------------
----------------------------------------------------------
Test trivial search: passed
----------------------------------------------------------
----------------------------------------------------------
IsOpenNode Function Test: passed
----------------------------------------------------------
----------------------------------------------------------
ExamineNeighbors Function Test: passed
----------------------------------------------------------
----------------------------------------------------------
Search test: passed
----------------------------------------------------------


```

## Reference
This project follows closely that from a Udacity introductory course on C++.
