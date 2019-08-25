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

vector<int> ParseLine(string stringRow) {
  istringstream streamRow(stringRow);
  char c;
  int n;
  vector<int> intRow;
  while(streamRow >> n >> c) {
    intRow.push_back(n);
  }
  return intRow;
}

vector<vector<int>> ReadBoardFile(string path) {
  ifstream boardFile(path);
  vector<vector<int>> board;
  if(boardFile) {
    string line;
    while (getline(boardFile, line)) {
      board.push_back(ParseLine(line));
    }
  }
  return board;
}

void PrintBoard(vector<vector<int>> b) {
  cout << "\nboard" << "\n\n";
  for(vector<int> row: b) {
    cout << " ";
    for(int tile: row)
      cout << " " << tile;
    cout << "\n";
  }
  cout << "\n";
}

int main() {
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
}