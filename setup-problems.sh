#!/bin/bash

# Check if a problem number is provided as an argument
if [ -z "$1" ] || [ -z "$2" ]; then
  echo "Usage: $0 <year> <day>"
  exit 1
fi

# Define the problem number and create the folder for the problem
YEAR=$1
DAY=$2
PROBLEM_FOLDER="${YEAR}/${DAY}"
mkdir -p "$PROBLEM_FOLDER"

# Change directory to the problem folder
cd "$PROBLEM_FOLDER"

# Create the Main.cc file
cat > main.cpp <<EOL
/*
 * Year: $YEAR
 * Day: $DAY
 * URL: https://adventofcode.com/$YEAR/day/$DAY
 */

#include <iostream>

using namespace std;

#ifndef ONLINE_JUDGE
#include <chrono>
#include <cstdio>
#include <fstream>

using namespace chrono;

#endif

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



/* === Local Execution Time Measurement === */
#ifndef ONLINE_JUDGE
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start);

  clog << "Execution time: " << duration.count() << " ms" << endl;
#endif

  return 0;
}

EOL

# Create input.txt and output.txt files
touch input.txt output.txt

echo "Setup completed for Problem #$DAY"
