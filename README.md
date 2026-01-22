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
- `inclass/`: Exercises and examples covered during class sessions.

### Week 3 Topics
- **Solving Recurrences**: Master Method, Recursion Trees, and Substitution Method.
- **Heaps & Trees**: Binary trees, Heap property, and HeapSort implementation.

### Example: Running Heapsort (Week 3)
```bash
g++ -o heapsort inclass/week3/max_heapsort.cpp
./heapsort
```

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

- **OS:** Ubuntu (Linux)
- **Language:** C++
- **Compiler:** `g++` (part of `build-essential`)
- **Standard:** C++11 or higher
