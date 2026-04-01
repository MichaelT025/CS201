# CS 201 Homework 3 - Movie Search and Retrieval

## Overview

- **Course**: Spring 2026 - CS 201 Data Structures and Algorithms
- **Maximum Points**: 100 (Individual Work Only)
- **Deadline**: April 5, 2026, by 11:59 PM (late submissions will receive a score of zero)

## Objective

- Select the best data structure and design an efficient algorithm for search and retrieval.

## Problem Description

### Part 1: Program Implementation

Write a C++ program that reads a file containing movie names and actors separated by `/` and stores the movie name and actors using a data structure such that we can search for either the movie or the actor.

**Search Requirements:**
- If the movie name is specified as the search query: print all actors in that movie, one per line
- If the actor's name is specified as the search query: print all movies that the actor has acted in, one per line
- If either the movie name or actor name is not found: print an appropriate "Not Found" message

**Input:**
- The file containing movie names and actors is provided as a command-line argument
- The search query file is provided as a command-line argument
- You may use any data structures or algorithms provided by the C++ standard library (std namespace)

### Part 2: Performance Measurement

The program must measure and print the execution time for:
1. Creating the data structure
2. Performing the search

Include the program output in the report to justify the values shown in the table.

### Part 3: Testing with Multiple Input Files

After testing for correctness and efficiency, use the different input files provided in Blackboard along with the given query file (`query.txt`) and complete the table:

| DB File | # of records | Time taken to create data structure | Time taken to search | Total time taken |
|---------|-------------|-------------------------------------|---------------------|------------------|
| dbfile1.txt | | | | |
| dbfile2.txt | | | | |
| dbfile3.txt | | | | |

### Part 4: Report

Include the table in the report and write a short description that describes:
- The rationale for your choice of data structure
- The corresponding algorithm
- Determine the complexity of the search and retrieval operation
- Compare the search time for different db file sizes
- Explain the results obtained in the table

## Program Documentation and Testing

1. Use appropriate variable names and indentation in your source code
2. Include meaningful comments to indicate various operations performed by the program
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

## Submission

Upload only the source files (.h, .hpp, .cpp, .cc files) and the report (Word or PDF file) to Blackboard in the assignment submission section. Do NOT upload zip/tar files - upload individual source files (no object files or executables) and the Word or PDF file for the report.
