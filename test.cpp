void TestHeuristic() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "Heuristic Function Test: ";
  if (Heuristic(1, 2, 3, 4) != 4) {
    cout << "failed" << "\n";
    cout << "\n" << "Heuristic(1, 2, 3, 4) = " << Heuristic(1, 2, 3, 4) << "\n";
    cout << "Correct result: 4" << "\n";
    cout << "\n";
  } else if (Heuristic(2, -1, 4, -7) != 8) {
    cout << "TestHeuristic Failed" << "\n";
    cout << "\n" << "Heuristic(2, -1, 4, -7) = " << Heuristic(2, -1, 4, -7) << "\n";
    cout << "Correct result: 8" << "\n";
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
}

void PrintVectorOfVectors(vector<vector<int>> v) {
  for (auto row : v) {
    cout << "{ ";
    for (auto col : row) {
      cout << col << " ";
    }
    cout << "}" << "\n";
  }
}

void PrintVectorOfVectors(vector<vector<State>> v) {
  for (auto row : v) {
    cout << "{ ";
    for (auto col : row) {
      cout << CellString(col) << " ";
    }
    cout << "}" << "\n";
  }
}

void TestAddToTestNodes() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "AddToTestNodes Function Test: ";
  int x = 3;
  int y = 0;
  int g = 5;
  int h = 7;
  vector<vector<int>> testNodes{{0, 0, 2, 9}, {1, 0, 2, 2}, {2, 0, 2, 4}};
  vector<vector<int>> solution_testNodes = testNodes; 
  solution_testNodes.push_back(vector<int>{3, 0, 5, 7});
  vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kOpen, State::kOpen, State::kOpen, State::kOpen},
                            {State::kClosed, State::kObstacle, State::kOpen, State::kOpen, State::kOpen, State::kOpen},
                            {State::kClosed, State::kObstacle, State::kOpen, State::kOpen, State::kOpen, State::kOpen},
                            {State::kOpen, State::kObstacle, State::kOpen, State::kOpen, State::kOpen, State::kOpen},
                            {State::kOpen, State::kOpen, State::kOpen, State::kOpen, State::kObstacle, State::kOpen}};
  vector<vector<State>> solution_grid = grid;
  solution_grid[3][0] = State::kClosed;
  AddToTestNodes(x, y, g, h, testNodes, grid);
  if (testNodes != solution_testNodes) {
    cout << "failed" << "\n";
    cout << "\n";
    cout << "Your testNodes list is: " << "\n";
    PrintVectorOfVectors(testNodes);
    cout << "Solution testNodes list is: " << "\n";
    PrintVectorOfVectors(solution_testNodes);
    cout << "\n";
  } else if (grid != solution_grid) {
    cout << "failed" << "\n";
    cout << "\n";
    cout << "Your grid is: " << "\n";
    PrintVectorOfVectors(grid);
    cout << "\n";
    cout << "Solution grid is: " << "\n";
    PrintVectorOfVectors(solution_grid);
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
  return;
}