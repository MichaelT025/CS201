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

- `hw/`: Homework assignments focusing on performance testing and functional verification. Organized by assignment (e.g., `hw/hw0/`).
- `inclass/`: Exercises and examples covered during class sessions.

### Homework 0: Sorting Algorithms
- **Implementations**: Insertion Sort and Merge Sort using C++ iterators.
- **Location**: `hw/hw0/`
- **Verification**: `functest.cpp` for functional correctness and `perftest.cpp` for performance analysis.
- **Report**: `report.md` containing performance data and analysis.

### Week 3 Topics
- **Solving Recurrences**: Master Method, Recursion Trees, and Substitution Method.
- **Heaps & Trees**: Binary trees, Heap property, and HeapSort implementation.

### Week 4 Topics
- **Quick Sort**: Partitioning strategies, pivot selection, and complexity analysis.
- **Linear-Time Sorting**: Counting Sort, Radix Sort, and Bucket Sort algorithms.
- **Hash Tables**: Hash functions, collision handling (chaining, open addressing), and load factor.

### Week 5 Topics
- **Binary Trees**: Traversal algorithms including Preorder, Inorder, Postorder (DFS), and Level Order (BFS).

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

### Example: Running Performance Test (HW0)

```bash
g++ -o perftest hw/hw0/perftest.cpp
./perftest
```


## Languages & Tools

- **OS:** Ubuntu (Linux)
- **Language:** C++
- **Compiler:** `g++` (part of `build-essential`)
- **Standard:** C++11 or higher
