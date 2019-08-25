#include <iostream>
#include <vector>
using std::cout;
using std::vector;

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
  vector<vector<int>> board {{0, 1, 0, 0, 0, 0},
                             {0, 1, 0, 0, 0, 0},
                             {0, 1, 0, 0, 0, 0},
                             {0, 1, 0, 0, 0, 0},
                             {0, 0, 0, 0, 1, 0}};
  
  PrintBoard(board);
}