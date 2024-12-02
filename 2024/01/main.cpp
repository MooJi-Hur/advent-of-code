/*
 * Year: 2024
 * Day: 01
 * URL: https://adventofcode.com/2024/day/01
 */

#include <iostream>

using namespace std;

#ifndef ONLINE_JUDGE
#include <chrono>
#include <cstdio>
#include <fstream>

using namespace chrono;

#endif

#include <set>

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
  int totalSize = 1000;
  int sum = 0;

  multiset<int> lefts[totalSize];
  multiset<int> rights[totalSize];

  for (int i = 0; i < totalSize; ++i) {
    int left = 0, right = 0;
    cin >> left >> right;

    lefts->insert(left);
    rights->insert(right);
  }

  auto leftIter = lefts->begin();
  auto rightIter = rights->begin();

  for (int i = 0; i < totalSize; ++i) {
        sum += abs(*rightIter - *leftIter);

    leftIter++;
    rightIter++;
  }

  cout << sum;

/* === Local Execution Time Measurement === */
#ifndef ONLINE_JUDGE
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start);

  clog << "Execution time: " << duration.count() << " ms" << endl;
#endif

  return 0;
}
