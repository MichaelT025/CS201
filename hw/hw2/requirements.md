Spring 2026 – CS 201 Data Structures and Algorithms

Homework-2

Maximum points: 100. Individual Work Only.

Due Date: March 8, 2026, before 11:59pm (late submissions will get a score of zero)

## Objectives

- Implement the SymbolTable class in C++ using Red-Black Trees
- Use the SymbolTable class to implement the word frequency problem

## Problem Description

### 1. Implement the SymbolTable class

Implement the SymbolTable class using the given header file ST.hpp and test your implementation using the driver program STMain.cpp. Use the Red-Black tree implementation provided to implement the SymbolTable class. Note that you should not modify any code from the Red-Black tree implementation, the only file you must update is ST.hpp. Also, make sure that the implementation of each method conforms with the specified algorithmic complexity. The table below provides the method name, description, and expected worst-case complexity for each method:

| Name | Description | Time Complexity | Points |
|------|-------------|-----------------|--------|
| ST() | Default constructor | Constant | 5 |
| ~ST() | Destructor | Linear in size of ST | 5 |
| [] operator | Inserts a key if it is not already present and returns a reference to the value corresponding to that key | Logarithmic in size of ST | 5 |
| insert(key, value) | Inserts the given (key,value) pair if the key does not exist, otherwise will replace current key with new value | Logarithmic in size of ST | 5 |
| remove(position) | Remove element at the given position | Amortized constant | 5 |
| remove(key) | Remove element with given key | Logarithmic in size of ST | 5 |
| clear() | Remove all elements from the ST, after this size() returns zero | Linear in size of ST | 5 |
| empty() | Checks if ST has no elements | Constant | 5 |
| size() | Returns no. of elements in ST | Constant | 5 |
| count(key) | Returns no. of elements that match key (0 or 1 is returned as keys are unique) | Logarithmic in size of ST | 5 |
| find(key) | Finds a node with matching key and returns iterator to the matching element (nullptr when no match found) | Logarithmic in size of ST | 5 |
| contains(key) | Returns true if the key is found in ST, otherwise false | Logarithmic in size of ST | 5 |
| toVector() | Returns contents of ST as a vector of (key,value) pairs | Linear in size of ST | 5 |
| displayTree() | Prints the Red-Black Tree associated with ST | Linear in size of ST | 0 |
| display() | Prints ST as key: value | Linear in size of ST | 5 |

### 2. Use the SymbolTable class to solve Homework-1

Use the SymbolTable class to implement the solution to Homework-1 and compare the performance of the program with that of Homework-1 and complete the table below:

| Input File | # of distinct words | Time Taken Homework-1 | Time Taken using SymbolTable |
|------------|--------------------:|----------------------:|-----------------------------:|
| Input1.txt | | | |
| Input2.txt | | | |
| Input3.txt | | | |

### 3. Include the table in the report

Include the table in the report and write a short description that compares the performance of the two versions and explain any differences between the two approaches as well as any differences in the execution time.

## Program Documentation and Testing

1. Use appropriate variables names and indentation in your source code.
2. Include meaningful comments to indicate various operations performed by the program.
3. Programs must include the following header information within comments:

```cpp
/*
Name:
Email:
Course Section: Spring 2026 CS 201
Homework #:
To Compile: <include instructions to compile the program>
To Run: <include instructions to run the program>
*/
```
