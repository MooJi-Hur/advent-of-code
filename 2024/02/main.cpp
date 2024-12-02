/*
 * Year: 2024
 * Day: 02
 * URL: https://adventofcode.com/2024/day/02
 */

#include <iostream>

using namespace std;

#ifndef ONLINE_JUDGE
#include <chrono>
#include <cstdio>
#include <fstream>

using namespace chrono;

#endif

#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int main(void) {
/* === Local Execution Time Measurement and File I/O === */
#ifndef ONLINE_JUDGE
  auto start = high_resolution_clock::now();

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream inputFile("input.txt");
  ofstream outputFile("output.txt");

  if (inputFile.is_open() && outputFile.is_open()) {
    cin.rdbuf(inputFile.rdbuf());
    cout.rdbuf(outputFile.rdbuf());
  } else {
    cerr << "Failed to open input/output files." << endl;
    return 1;
  }

#endif

  /* === Problem Solving Code ===
    Write the solution code for the problem here. */
  string line;
  int totalSafe = 0;

  while (getline(cin, line)) {
    istringstream lineStream(line);
    vector<int> elements;
    int element;

    while (lineStream >> element) {
      elements.push_back(element);
    }

    bool initPositiveSign = 0;

    for (int i = 1; i < elements.size(); ++i) {
      bool currentPositiveSign = 0;
      bool sortSafe = 0;
      bool differenceAbsSafe = 0;

      int difference = elements[i] - elements[i - 1];

      differenceAbsSafe = (abs(difference) > 0) && (abs(difference) < 4);

      if (!differenceAbsSafe) {
        break;
      }

      currentPositiveSign = difference > 0;

      if (i == 1) {
        initPositiveSign = currentPositiveSign;
      }

      sortSafe = (currentPositiveSign == initPositiveSign);

      if (!sortSafe) {
        break;
      }

      if (i == elements.size() - 1) {
        totalSafe++;
      }
    }
  };

  cout << totalSafe;

  /* === Local Execution Time Measurement === */
#ifndef ONLINE_JUDGE
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start);

  clog << "Execution time: " << duration.count() << " ms" << endl;
#endif

  return 0;
}
