# CS201: Data Structures and Algorithms

This repository contains homework assignments and in-class exercises for the **CS201: Data Structures and Algorithms** course.

## Course Overview
The course focuses on the fundamental concepts of data structures and algorithms, including:
- Time and space complexity analysis (Big O notation)
- Sorting and searching algorithms
- Linear data structures (arrays, linked lists, stacks, queues)
- Non-linear data structures (trees, graphs, hash tables)
- Algorithm design techniques

## Repository Structure

- `hw/`: Homework assignments focusing on performance testing and functional verification.
  - `perftest.cpp`: Benchmarking the performance of standard library sorting algorithms across varying problem sizes.
  - `functest.cpp`: Functional tests for sorting different data types (int, string, double) using `std::sort` and `std::reverse`.
- `inclass/`: Exercises and examples covered during class sessions.
  - `insertionsort.cpp`: Implementation and demonstration of the Insertion Sort algorithm.

## How to Compile and Run

To compile and run any of the C++ files, you can use `g++` or any other C++ compiler.

### Example: Running Insertion Sort
```bash
g++ -o insertionsort inclass/insertionsort.cpp
./insertionsort
```

### Example: Running Performance Test
```bash
g++ -o perftest hw/perftest.cpp
./perftest
```

## Languages & Tools
- **Language:** C++
- **Compiler:** `g++` (recommended)
- **Standard:** C++11 or higher
