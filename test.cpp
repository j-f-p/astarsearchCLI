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

string NodeStateAsString(State state) {
  switch(state) {
    case State::closed:   return " closed  ";
    case State::finish:   return " finish  ";
    case State::obstacle: return " obstacle";
    case State::open:     return " open    ";
    case State::path:     return " path    ";
    case State::start:    return " start   ";
    default:              return " error   ";
  }
}

void PrintVectorOfVectors(vector<vector<State>> v) {
  for (auto row : v) {
    cout << "{ ";
    for (auto col : row) {
      cout << NodeStateAsString(col) << " ";
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

void TestTrivialSearch() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "Test trivial search: ";
  auto gridState0 = ReadGridFile("stateMatrix.csv");
  auto gridState1 = Search(gridState0, vector<int> {4, 5}, vector<int> {4, 5});
  gridState0[0][0] = State::start;  // expected state after Search
  gridState0[4][5] = State::finish; // expected state after Search
  if (gridState1 != gridState0) {
    cout << "failed" << "\n";
    cout << "Search(board, {4,5}, {4,5})" << "\n";
    cout << "Solution board: " << "\n";
    PrintVectorOfVectors(gridState0);
    cout << "Your board: " << "\n";
    PrintVectorOfVectors(gridState1);
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
  return;
}

void TestIsOpenNode() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "IsOpenNode Function Test: ";
  vector<vector<State>> grid{{State::closed, State::obstacle, State::open, State::open, State::open, State::open},
                            {State::closed, State::obstacle, State::open, State::open, State::open, State::open},
                            {State::closed, State::obstacle, State::open, State::open, State::open, State::open},
                            {State::closed, State::obstacle, State::open, State::open, State::open, State::open},
                            {State::closed, State::closed, State::open, State::open, State::obstacle, State::open}};

  if (IsOpenNode(0, 0, grid)) { // node in grid but is not open
    cout << "failed" << "\n";
    cout << "\n" << "Test grid is: " << "\n";
    PrintVectorOfVectors(grid);
    cout << "Cell checked: (0, 0)" << "\n";
    cout << "\n";
  } else if (!IsOpenNode(4, 2, grid)) { // node {4, 2} is open
    cout << "failed" << "\n";
    cout << "\n" << "Test grid is: " << "\n";
    PrintVectorOfVectors(grid);
    cout << "Cell checked: (4, 2)" << "\n";
    cout << "\n";
  } else if (IsOpenNode(10, 2, grid)) { // node is not in grid
    cout << "failed" << "\n";
    cout << "\n" << "Test grid is: " << "\n";
    PrintVectorOfVectors(grid);
    cout << "Cell checked: (10, 2)" << "\n";
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
}

void TestExamineNeighbors() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "ExamineNeighbors Function Test: ";
  vector<int> current{4, 2, 7, 3};
  vector<int> goal {4, 5};
  vector<vector<int>> open{{4, 2, 7, 3}};
  vector<vector<int>> solution_open = open;
  solution_open.push_back(vector<int>{3, 2, 8, 4});
  solution_open.push_back(vector<int>{4, 3, 8, 2});
  vector<vector<State>> grid{{State::closed, State::obstacle, State::open, State::open, State::open, State::open},
                            {State::closed, State::obstacle, State::open, State::open, State::open, State::open},
                            {State::closed, State::obstacle, State::open, State::open, State::open, State::open},
                            {State::closed, State::obstacle, State::open, State::open, State::open, State::open},
                            {State::closed, State::closed, State::open, State::open, State::obstacle, State::open}};
  vector<vector<State>> solution_grid = grid;
  solution_grid[3][2] = State::closed;
  solution_grid[4][3] = State::closed;
  ExamineNeighbors(current, goal, open, grid);
  SortDescendingF(&open);
  SortDescendingF(&solution_open);
  if (open != solution_open) {
    cout << "failed" << "\n";
    cout << "\n";
    cout << "Your open list is: " << "\n";
    PrintVectorOfVectors(open);
    cout << "Solution open list is: " << "\n";
    PrintVectorOfVectors(solution_open);
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

void TestSearch() {
  cout << "----------------------------------------------------------" << "\n";
  cout << "Test search: ";
  auto gridState0 = ReadGridFile("stateMatrix.csv");
  auto gridState1 = Search(gridState0, vector<int> {0, 0}, vector<int> {4, 5});
  // Expected grid state after Search
  gridState0[0][0] = State::start;
  gridState0[1][0] = State::path;
  gridState0[2][0] = State::path;
  gridState0[3][0] = State::path;
  gridState0[4][0] = State::path;
  gridState0[4][1] = State::path;
  gridState0[4][2] = State::path;
  gridState0[4][3] = State::path;
  gridState0[3][3] = State::path;
  gridState0[3][4] = State::path;
  gridState0[3][5] = State::path;
  gridState0[4][5] = State::finish;
  gridState0[3][2] = State::closed;
  gridState0[2][3] = State::closed;
  gridState0[2][4] = State::closed;
  gridState0[2][5] = State::closed;
  if (gridState1 != gridState0) {
    cout << "failed" << "\n";
    cout << "Search(board, {4,5}, {4,5})" << "\n";
    cout << "Solution board: " << "\n";
    PrintVectorOfVectors(gridState0);
    cout << "Your board: " << "\n";
    PrintVectorOfVectors(gridState1);
    cout << "\n";
  } else {
    cout << "passed" << "\n";
  }
  cout << "----------------------------------------------------------" << "\n";
  return;
}