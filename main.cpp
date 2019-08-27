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

enum class State {closed, obstacle, open, path};

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

void sortDescendingF(vector<vector<int>> *testNodes) {
  sort(testNodes->begin(), testNodes->end(), CompareDescendingF);
}

vector<vector<State>> Search(
    vector<vector<State>> grid, vector<int> start, vector<int> goal) {

  vector<vector<int>> testNodes {};

  int x {start[0]};
  int y {start[1]};
  int g {0};
  int h = Heuristic(x, y, goal[0], goal[1]);

  AddToTestNodes(x, y, g, h, testNodes, grid);

  while(not testNodes.empty()) {
    sortDescendingF(&testNodes);

    auto removed = testNodes.back();
    testNodes.pop_back();

    x = removed[0];
    y = removed[1];
    grid[x][y] = State::path;

    if(x==goal[0] and y==goal[1])
      return grid;

  }

  cout << "No path found!\n";
  return vector<vector<State>>{};
}

string NodeString(State state) {
  switch(state) {
    case State::obstacle: return "⛰️   ";
    case State::path: return "🚗   ";
    default: return "0   "; // State::open or State::closed
  }
}

void PrintMap(vector<vector<State>> grid) {
  cout << "\nGrid" << "\n\n";
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
}
