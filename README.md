# A* Search CLI Program
Objective: This is a project for learning the A* search algorithm and some core components of C++ 2017.

## Description
The project is built with C++ compliant with the 2017 standard. It employs the A* search algorithm for finding the shortest route between two points on a square grid graph. The program is executed through a command line interface (CLI) and produces output through the associated terminal's standard output. The program was developed with test-driven development (TDD).

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
The program reads a file, `stateMatrix.csv`, containing comma separated values, each either being a `1` or a `0`. In this file, each value represents the initial state of a node of the graph. A `1` represents a barrier. A `0` represents an open node. The rows and columns of values represent the two dimensions of the grid graph. The zero-based ordering of these dimensions are node coordinates. For instance, row `4` and column `5` are the coordinates of the bottom-right node of the graph.
```bash
$ cat stateMatrix.csv
0,1,0,0,0,0,
0,1,0,0,0,0,
0,1,0,0,0,0,
0,1,0,0,0,0,
0,0,0,0,1,0,
```
The start and goal node coordinates of the grid for the A* search algorithm are hardcoded in the program as arguments to the `Search` function. Then, the `Search` function further modifies the state matrix as it constructs the shortest route. Below is the last development execution. The main output involves an imperfect representation of the square grid graph due to nonuniform character spacing and an unmatched text line-height. Following the main output, is output from unit tests of the TDD process.
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
