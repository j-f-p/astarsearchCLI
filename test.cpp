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
      cout << NodeString(col) << " ";
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
  vector<vector<State>> grid{{State::closed, State::obstacle, State::open, State::open, State::open, State::open},
                            {State::closed, State::obstacle, State::open, State::open, State::open, State::open},
                            {State::closed, State::obstacle, State::open, State::open, State::open, State::open},
                            {State::open, State::obstacle, State::open, State::open, State::open, State::open},
                            {State::open, State::open, State::open, State::open, State::obstacle, State::open}};
  vector<vector<State>> solution_grid = grid;
  solution_grid[3][0] = State::closed;
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

void PrintVector(vector<int> v) {
  cout << "{ ";
  for (auto col : v) {
    cout << col << " ";
  }
  cout << "}" << "\n";
}

void TestCompare() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "Compare Function Test: ";
  vector<int> test_1 {1, 2, 5, 6};
  vector<int> test_2 {1, 3, 5, 7};
  vector<int> test_3 {1, 2, 5, 8};
  vector<int> test_4 {1, 3, 5, 7};
  if (CompareDescendingF(test_1, test_2)) {
    cout << "failed" << "\n";
    cout << "\n" << "a = ";
    PrintVector(test_1);
    cout << "b = ";
    PrintVector(test_2);
    cout
    << "CompareDescendingF(a, b): "
    << CompareDescendingF(test_1, test_2) << "\n";
    cout << "Correct answer: 0" << "\n";
    cout << "\n";
  } else if (!CompareDescendingF(test_3, test_4)) {
    cout << "failed" << "\n";
    cout << "\n" << "a = ";
    PrintVector(test_3);
    cout << "b = ";
    PrintVector(test_4);
    cout
    << "CompareDescendingF(a, b): "
    << CompareDescendingF(test_3, test_4) << "\n";
    cout << "Correct answer: 1" << "\n";
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
  return;
}