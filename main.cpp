#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
  vector<vector<int>> board {{0, 1, 0, 0, 0, 0},
                             {0, 1, 0, 0, 0, 0},
                             {0, 1, 0, 0, 0, 0},
                             {0, 1, 0, 0, 0, 0},
                             {0, 0, 0, 0, 1, 0}};
  
  cout << "board =\n" << "{\n";
  for(auto row: board) {
    cout << "\t{ ";
    for(int tile: row)
      cout << tile << " ";
    cout << "}\n";
  }
  cout << "}\n";
}