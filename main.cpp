#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::string;
using std::vector;

void ReadBoardFile(string path) {
  ifstream boardFile(path);
  if(boardFile) {
    string line;
    while (getline(boardFile, line)) {
      cout << line << "\n";
    }
  }
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
  ReadBoardFile("1.board");
//PrintBoard(board);
}