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

enum class State {kEmpty, kObstacle};

vector<State> ParseLine(string stringRow) {
  istringstream streamRow(stringRow);
  char c;
  int n;
  vector<State> stateRow;
  while(streamRow >> n >> c and c==',') {
    if(n==0) {
      stateRow.push_back(State::kEmpty);
    }
    else {
      stateRow.push_back(State::kObstacle);
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

vector<vector<State>> Search(
    vector<vector<State>> grid, vector<int> start, vector<int> goal) {
  cout << "No path found!\n";
  return vector<vector<State>>{};
}

string CellString(State state) {
  switch(state) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   ";
  }
}

void PrintMap(vector<vector<State>> grid) {
  cout << "\nGrid" << "\n\n";
  for(vector<State> row: grid) {
    cout << "\t";
    for(State tile: row)
      cout << CellString(tile);
    cout << "\n";
  }
  cout << "\n";
}

int main() {
  auto grid = Search(
    ReadGridFile("stateMatrix.csv"), vector<int> {0, 0}, vector<int> {4, 5});

  if(not grid.empty())
    PrintMap(grid);
}
