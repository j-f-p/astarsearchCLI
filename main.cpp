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

vector<vector<State>> ReadBoardFile(string path) {
  ifstream boardFile(path);
  vector<vector<State>> board;
  if(boardFile) {
    string line;
    while (getline(boardFile, line)) {
      board.push_back(ParseLine(line));
    }
  }
  return board;
}

string CellString(State state) {
  switch(state) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   ";
  }
}

void PrintBoard(vector<vector<State>> board) {
  cout << "\nBoard" << "\n\n";
  for(vector<State> row: board) {
    cout << "\t";
    for(State tile: row)
      cout << CellString(tile);
    cout << "\n";
  }
  cout << "\n";
}

int main() {
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
}