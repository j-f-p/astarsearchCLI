#include <algorithm> // sort
#include <cstdlib> // abs
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

const int positionDeltas[4][2] {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

enum class State {closed, finish, obstacle, open, path, start};

vector<State> ParseLine(string stringRow) {
  istringstream streamRow(stringRow);
  char c;
  int n;
  vector<State> stateRow;
  while(streamRow >> n >> c and c==',') {
    if(n==0) {
      stateRow.push_back(State::open);
    }
    else {
      stateRow.push_back(State::obstacle);
    }
  }
  return stateRow;
}

vector<vector<State>> ReadGridFile(string path) {
  ifstream gridFile(path);
  vector<vector<State>> grid;
  if(gridFile) {
    string line;
    while (getline(gridFile, line)) {
      grid.push_back(ParseLine(line));
    }
  }
  return grid;
}

int Heuristic(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

void AddToTestNodes(int x, int y, int g, int h, 
    vector<vector<int>> &testNodes, vector<vector<State>> &grid) {
  testNodes.push_back(vector<int> {x, y, g, h});
  grid[x][y] = State::closed;
}

bool CompareDescendingF(const vector<int> node1, const vector<int> node2) {
  return node1[2]+node1[3] > node2[2]+node2[3];
}

void SortDescendingF(vector<vector<int>> *testNodes) {
  sort(testNodes->begin(), testNodes->end(), CompareDescendingF);
}

bool IsOpenNode(int x, int y, vector<vector<State>> &grid) {
  if(x > -1 and x < grid.size() and
     y > -1 and y < grid[0].size() and grid[x][y]==State::open)
    return true;
  return false;
}

void ExamineNeighbors(
    const vector<int> &removedNode, const vector<int> &goalPt,
    vector<vector<int>> &open, vector<vector<State>> &grid) {
  int x = removedNode[0];
  int y = removedNode[1];
  int g = removedNode[2];
  
  for(int neighbor=0; neighbor<4; neighbor++) {
    int xN = x + positionDeltas[neighbor][0];
    int yN = y + positionDeltas[neighbor][1];

    if(IsOpenNode(xN, yN, grid)) {
      int gN = g + 1;
      int hN = Heuristic(xN, yN, goalPt[0], goalPt[1]);
      AddToTestNodes(xN, yN, gN, hN, open, grid);
    }
  }
}

vector<vector<State>> Search(
    vector<vector<State>> grid, vector<int> startPt, vector<int> goalPt) {

  vector<vector<int>> testNodes {};

  int x {startPt[0]};
  int y {startPt[1]};
  int g {0};
  int h = Heuristic(x, y, goalPt[0], goalPt[1]);

  AddToTestNodes(x, y, g, h, testNodes, grid);

  while(not testNodes.empty()) {
    SortDescendingF(&testNodes);

    auto removed = testNodes.back();
    testNodes.pop_back();

    x = removed[0];
    y = removed[1];
    grid[x][y] = State::path;

    if(x==goalPt[0] and y==goalPt[1]) {
      grid[0][0] = State::start;
      grid[x][y] = State::finish;
      return grid;
    }

    ExamineNeighbors(removed, goalPt, testNodes, grid);
  }

  cout << "No path found!\n";
  return vector<vector<State>>{};
}

string NodeString(State state) {
  switch(state) {
    case State::finish: return "🏁   ";
    case State::obstacle: return "⛰️   ";
    case State::path: return "🚗   ";
    case State::start: return "🚦   ";
    default: return "0   "; // State::open or State::closed
  }
}

void PrintMap(vector<vector<State>> grid) {
  cout << "\nGrid with A* Search Path" << "\n\n";
  for(vector<State> row: grid) {
    cout << "\t";
    for(State tile: row)
      cout << NodeString(tile);
    cout << "\n";
  }
  cout << "\n";
}

#include "test.cpp"

int main() {
  auto grid = Search(
    ReadGridFile("stateMatrix.csv"), vector<int> {0, 0}, vector<int> {4, 5});

  if(not grid.empty())
    PrintMap(grid);
  
  TestHeuristic();
  TestAddToTestNodes();
  TestCompare();
  TestTrivialSearch();
  TestIsOpenNode();
  TestExamineNeighbors();
  TestSearch();
}
